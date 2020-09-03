/******************************************************************************
* Copyright (c) 2019 - Hemant Sharma - All Rights Reserved
*
* Feel free to use this Code at your own risk for your own purposes.
*
*******************************************************************************/
/******************************************************************************
* Title:		LED Flasher Task Header
* Filename:		led_task.h
* Author:		HS
* Origin Date:	01/18/2020
* Version:		1.0.0
* Notes:
*******************************************************************************/

/** @file:	led_task.h
 *  @brief:	This file contains function declarations for Led Flasher Task
 */
#ifndef LED_TASK_H_
#define LED_TASK_H_


/******************************************************************************
* Includes
*******************************************************************************/

/* Include Headers */
#include "stm32f4xx.h"

/* Include FreeRTOS Headers */
#include <cmsis_os.h>
#include <dri_mem.h>


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

/* Parameters for task creation */
typedef struct TaskCreationParams_
{
	char * p_name;
	configSTACK_DEPTH_TYPE stackDepth;
	UBaseType_t priority;
}TaskCreationParams;


/******************************************************************************
* Function Prototypes
*******************************************************************************/


/******************************************************************************
* Variables
*******************************************************************************/


/******************************************************************************
 *
 * @brief	Class for LED_Task__ Instance
 *
 ******************************************************************************/
/* Define a class for LED task */
class LedTask__
{
public:
	/** Constructors and Destructors */
	LedTask__() = delete;
	LedTask__ operator=( const LedTask__& ) = delete;

	explicit LedTask__( GPIO_TypeDef * port, uint32_t pin, TaskCreationParams * param ) :
		xLedPort(port), xLedPin(pin), xHandle(NULL)
	{
		xLedTaskParams.p_name = param->p_name;
		xLedTaskParams.priority = param->priority;
		xLedTaskParams.stackDepth = param->stackDepth;
	}

	/* Destructor for Led task class */
	virtual ~LedTask__()
	{
		;/* Do Nothing for now
		or Free Dynamic Allocated Memory (if any) */
		vTaskDelete( xHandle );
	}

	/* Task Initialization Function */
	void init( void );

protected:


private:
	/* Port Info */
	volatile GPIO_TypeDef * xLedPort;
	uint32_t xLedPin;

	/* Task Info */
	TaskHandle_t xHandle;
	TaskCreationParams xLedTaskParams;

	/* Will work as a linker to the actual task function */
	static void xsvTaskEntryPoint( void *params )
	{
		((LedTask__ *) params)->xvTaskEntry(params);
	}

	/* This function contains the actual body of task */
	void xvTaskEntry( void *pvParams );
};


#endif /* LED_TASK_H_ */

/********************************** End of File *******************************/
