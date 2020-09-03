/******************************************************************************
* Copyright (c) 2019 - Hemant Sharma - All Rights Reserved
*
* Feel free to use this Code at your own risk for your own purposes.
*
*******************************************************************************/
/******************************************************************************
* Title:		RTOS Wrappers API Header
* Filename:		rtos_wrappers.h
* Author:		HS
* Origin Date:	10/27/2019
* Version:		1.0.0
* Notes:
*******************************************************************************/

/** @file:	rtos_wrappers.h
 *  @brief:	This file contains RTOS Wrapper API functions.
 */
#ifndef RTOS_WRAPPERS_H_
#define RTOS_WRAPPERS_H_


/******************************************************************************
* Includes
*******************************************************************************/
/* RTOS headers inclusion */
#include "cmsis_os.h"


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

/**
 * @brief
 */


/******************************************************************************
* Variables
*******************************************************************************/


/******************************************************************************
* Function Prototypes
*******************************************************************************/


/******************************************************************************
 *
 * @brief	Class for RTOS Wrappers
 *
 ******************************************************************************/
class RTOS_WRAPPER__
{
/* Public Members */
public:
	/* Task creation function */
	static BaseType_t create( TaskFunction_t fp_task_code,
								const char * const p_name,
								const configSTACK_DEPTH_TYPE& stack_depth,
								void * const parameters, UBaseType_t priority,
								TaskHandle_t * const p_task_handle )
	{
		/* Local Variables */
		BaseType_t ret_status = pdTRUE;
		/* Create Task */
		ret_status = xTaskCreate( fp_task_code, p_name, stack_depth, parameters,
									priority, p_task_handle );
		/* Check return status */
		if( ret_status != pdTRUE )
		{
			vTaskDelete( *p_task_handle );
		}
		/* Return status */
		return ret_status;
	}

	static void destroy( TaskHandle_t * const p_task_handle )
	{
		vTaskDelete( *p_task_handle );
	}

/* Private Members */
private:
};


#endif /* RTOS_WRAPPERS_H_ */

/********************************** End of File *******************************/
