/******************************************************************************
* Copyright (c) 2019 - Hemant Sharma - All Rights Reserved
*
* Feel free to use this Code at your own risk for your own purposes.
*
*******************************************************************************/
/******************************************************************************
* Title:		LED Flasher API Source
* Filename:		led_task.cpp
* Author:		HS
* Origin Date:	03/04/2020
* Version:		1.0.0
* Notes:
*
* Change History
* --------------
*
*******************************************************************************/

/** @file:	led_task.cpp
 *  @brief:	This source file contains API function definitions for LED Flasher
 */


/******************************************************************************
* Includes
*******************************************************************************/

/* Include class headers */
#include <led_task.h>
#include <logger.h>


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

/* Declare static data member of class
 *
 * Note: Tell linker to take variable from this source file
 * */



/******************************************************************************
* Function Definitions
*******************************************************************************/

/******* Public Member function for LED_Task__ class *******/


/**
 * @function
 *
 * @brief		LED Task iniitalization function
 *
 * <i>Imp Note:</i>
 */
void LedTask__ :: init( void )
{
	/* Return Status of Task */
	BaseType_t xReturned = pdFAIL;

	/* Initialize Hardware */
	GPIO_InitTypeDef pin_config =
	{
		.Pin = xLedPin,
		.Mode = GPIO_MODE_OUTPUT_PP,
		.Pull = GPIO_PULLUP,
		.Speed = GPIO_SPEED_FREQ_LOW
	};

	HAL_GPIO_Init( (GPIO_TypeDef *)xLedPort, &pin_config );

	/* Create task */
	xReturned = xTaskCreate( LedTask__::xsvTaskEntryPoint, xLedTaskParams.p_name,
			xLedTaskParams.stackDepth, this, xLedTaskParams.priority, &xHandle );

	/* Delete task if not created successfully */
	if( xReturned != pdPASS )
	{
		vTaskDelete( xHandle );

		/* Halt if LED Flasher task is not started */
		for( ; ; );
	}
	else
	{
		/* Can do some initial processing if needed */
	}
}


/**
 * @function
 *
 * @brief		LED Task Entry function
 *
 * <i>Imp Note:</i>
 */
void LedTask__ :: xvTaskEntry( void *pvParams )
{
	/* Not using */
	(void)pvParams;

	/* Local Variables */
    TickType_t xLastWakeTime = 0;
    const TickType_t xFrequency = 500;

    float count = 0.0f;

    /* Initialize the xLastWakeTime variable with the current time. */
    xLastWakeTime = xTaskGetTickCount();

    /* Task execution entry */
    for( ; ; )
    {
    	/* LED Toggle operation */
		HAL_GPIO_TogglePin( (GPIO_TypeDef *)xLedPort, xLedPin );

		/* Delay for 500ms */
		vTaskDelayUntil( &xLastWakeTime, xFrequency );

		logger << "LED Blinking Task Running, Count = " << count << "\r\n" << logger.endl;
		count += 0.15f;
	}

	/* Should never reach here, if so the delete then task and free memory */
	vTaskDelete( NULL );
}


/********************************** End of File *******************************/
