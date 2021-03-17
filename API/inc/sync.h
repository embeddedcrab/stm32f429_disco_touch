/******************************************************************************
* Copyright (c) 2021 - Hemant Sharma - All Rights Reserved
*
* Feel free to use this Code at your own risk for your own purposes.
*
******************************************************************************/
/******************************************************************************
* Title:		Sync API Header
* Filename:		sync.h
* Author:		HS
* Origin Date:	02/23/2021
* Version:		1.0.0
* Notes:
******************************************************************************/

/** @file:	sync.h
 *  @brief:	This file contains API functions for synchronization.
 */
#ifndef SYNC_H_
#define SYNC_H_


#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
* Includes
******************************************************************************/

#include "stm32f4xx.h"
/* RTOS headers inclusion */
#include "cmsis_os.h"


/******************************************************************************
* Preprocessor Constants
******************************************************************************/


/******************************************************************************
* Configuration Constants
******************************************************************************/

#define MAX_MUTEX_RETRY_COUNTER		10


/******************************************************************************
* Macros
******************************************************************************/

#define LOCK_BIT_POSITION			0
#define SYNC_BIT_POSITION			1
#define WRITE_BIT_POSITION			2
#define READ_BIT_POSITION			3


/******************************************************************************
* Typedefs
******************************************************************************/

/**
 * @brief
 */
typedef struct sync_mutex_t_
{
    union
    {
    	struct
		{
            unsigned char lock	: 1;
            unsigned char sync	: 1;/* Can be used for sequencing or anything */
            unsigned char write	: 1;
            unsigned char read	: 1;
            unsigned char		: 4;
		};
        unsigned char byte;
    };
} sync_mutex_t;// __attribute__((aligned(1)));


/******************************************************************************
* Variables
******************************************************************************/


/******************************************************************************
* Static Functions
******************************************************************************/

/*------- Atomic Load and Store Functions  -------*/

/**
 * @function	atomic_load8
 *
 * @brief		Load variable value from memory
 *
 * @param[in]	p_addr	-	Memory address of variable
 *
 * @param[out]	p_out	-	Value at memory address
 *
 * @param[inout]NA
 *
 * @return		NA
 *
 * \par<b>Description:</b><br>
 *
 * <i>Imp Note:</i>
 * 				Uses CMSIS instruction
 *
 */
static inline void atomic_load8( volatile unsigned char *p_out, volatile unsigned char * p_addr )
{
	*p_out = __LDREXB( p_addr );
}


/**
 * @function	atomic_store8
 *
 * @brief		Store Value to memory using variable
 *
 * @param[in]	p_value	-	pointer to value to be stored
 * 				p_addr	-	pointer to address of memory variable
 *
 * @param[out]	NA
 *
 * @param[inout]NA
 *
 * @return		Status of Completion of instruction
 * 				0 - Success
 * 				1 - Failure
 *
 * \par<b>Description:</b><br>
 *
 * <i>Imp Note:</i>
 * 					Uses CMSIS instruction
 *
 */
static inline unsigned long atomic_store8( volatile unsigned char *p_value, volatile unsigned char * p_addr )
{
	return __STREXB( *p_value, p_addr );
}


/******************************************************************************
* Function Prototypes
******************************************************************************/

/*------- Bit lock Functions  -------*/

/**
 * @function	lock_bit
 *
 * @brief		Locks bit of variable using exclusive load-store instruction
 *
 * @param[in]
 *
 * @param[out]
 *
 * @param[inout]pointer to lock variable
 *
 * @return		return status of operations
 * 				0 - Success
 * 				1 - Failed
 *
 * \par<b>Description:</b><br>
 *
 * <i>Imp Note:</i>
 * 				Disabled optimization to discard changes done by compiler
 *
 */
long lock_bit( volatile unsigned char * p_varlock ) __attribute__((optimize("0")));


/**
 * @function	unlock_bit
 *
 * @brief		Unlocks bit of variable
 *
 * @param[in]
 *
 * @param[out]
 *
 * @param[inout]pointer to lock variable
 *
 * @return		NA
 *
 * \par<b>Description:</b><br>
 *
 * <i>Imp Note:</i>
 * 				Disabled optimization to discard changes done by compiler
 * 				Uses Atomic operation by Entering Critical Section
 *
 */
void unlock_bit( volatile unsigned char * p_varlock ) __attribute__((optimize("0")));





/* Lock Bit of a variable */
#define GET_BIT_LOCK(lock)											\
{																	\
	long status = -1;												\
	do																\
	{																\
		status = lock_bit( &(lock.byte) );							\
	}while( status != 0 );											\
}

/* Release Bit Lock */
#define RELEASE_BIT_LOCK(lock)	unlock_bit( &(lock.byte) )


#ifdef __cplusplus
}
#endif	/* extern "C" linkage */


#endif /* SYNC_H_ */

/********************************** End of File ******************************/

