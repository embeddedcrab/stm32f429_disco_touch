/******************************************************************************
* Copyright (c) 2021 - Hemant Sharma - All Rights Reserved
*
* Feel free to use this Code at your own risk for your own purposes.
*
*******************************************************************************/
/******************************************************************************
* Title:		Sync API Source
* Filename:		sync.c
* Author:		HS
* Origin Date:	02/23/2021
* Version:		1.0.0
* Notes:
*
* Change History
* --------------
*
*******************************************************************************/

/** @file:	sync.c
 *  @brief:	This source file contains API function definitions for Sync
 */


/******************************************************************************
* Includes
*******************************************************************************/

/* Include headers */
#include <sync.h>


/******************************************************************************
* Preprocessor Constants
*******************************************************************************/


/******************************************************************************
* Configuration Constants
*******************************************************************************/


/******************************************************************************
* Macros
*******************************************************************************/


/******************************************************************************
* Typedefs
*******************************************************************************/


/******************************************************************************
* Variables
*******************************************************************************/


/******************************************************************************
* Function Definitions
*******************************************************************************/

/*------- Locking - Unlocking Functions  -------*/

/**
 * @function	lock_bit
 *
 * @brief		Locks bit of variable using exclusive load-store instruction
 *
 * <i>Imp Note:</i>
 */
long lock_bit( volatile unsigned char * p_varlock )
{
	/* Local Variables */
    unsigned char lock_l = 0;
    unsigned char count_l = 0;

    do
    {
        /* Fetch lock value */
        atomic_load8( &lock_l, p_varlock );
        /* Read lock bit, if not locked then try lock */
        if( !(lock_l & (1<<LOCK_BIT_POSITION)) )
        {
            /* Set Lock */
            lock_l |= 0x01;
            if( 0 == atomic_store8( &lock_l, p_varlock ) )
            {
            	/* Return Success status */
            	return 0;
            }
            else
            {
            	__CLREX();
            	break;
            }
        }
        else
        {
        	/* Counter for iterations */
            if( count_l >= MAX_MUTEX_RETRY_COUNTER )
            {
            	__CLREX();/* Confirm it, because LD is successful and monitors needs to be cleared! */
                break;
            }
            else
            {
            	count_l += 1;
            }
        }
    } while( lock_l & (1<<LOCK_BIT_POSITION) );

    /* Return Failure status */
    return 1;
}


/**
 * @function	unlock_bit
 *
 * @brief
 *
 * <i>Imp Note:</i>
 */
void unlock_bit( volatile unsigned char * p_varlock )
{
	*p_varlock &= ~(1<<LOCK_BIT_POSITION);
}


/********************************** End of File *******************************/
