

#include <logger_test.h>

#include "stm32f4xx.h"
#include <semphr.h>


SemaphoreHandle_t LoggerTest__::task_sem;


void LoggerTest__::LoggerTest_Task1( void *pvParams )
{
	/* Not using */
	(void)pvParams;

	unsigned long count = 0;

    /* Task execution entry */
    for( ; ; )
    {
    	if( xSemaphoreTake( task_sem, portMAX_DELAY ) == pdPASS )
		{
			logger<< count << ' ' << "Task 1 Logger Task---------------------------------------------\r\n" << logger.endl;
			count += 1;
			logger<< "---------------------------------------------------------------\r\n" << logger.endl;
	    	xSemaphoreGive( task_sem );
		}
    	taskYIELD();
	}

	/* Should never reach here, if so the delete then task and free memory */
	vTaskDelete( NULL );
}

void LoggerTest__::LoggerTest_Task2( void *pvParams )
{
	/* Not using */
	(void)pvParams;

	unsigned long count = 0;

    /* Task execution entry */
    for( ; ; )
    {
    	if( xSemaphoreTake( task_sem, portMAX_DELAY ) == pdPASS )
		{
    		logger<< count << ' ' << "Task 2 Logger Task---------------------------------------------\r\n" << logger.endl;
			count += 1;
			logger<< "---------------------------------------------------------------\r\n" << logger.endl;
	    	xSemaphoreGive( task_sem );
		}
    	taskYIELD();
	}

	/* Should never reach here, if so the delete then task and free memory */
	vTaskDelete( NULL );
}

void LoggerTest__::LoggerTest_Task3( void *pvParams )
{
	/* Not using */
	(void)pvParams;

	unsigned long count = 0;

    /* Task execution entry */
    for( ; ; )
    {
    	if( xSemaphoreTake( task_sem, portMAX_DELAY ) == pdPASS )
		{
    		logger<< count << ' ' << "Task 3 Logger Task---------------------------------------------\r\n" << logger.endl;
			count += 1;
			logger<< "---------------------------------------------------------------\r\n" << logger.endl;
	    	xSemaphoreGive( task_sem );
		}
    	taskYIELD();
	}

	/* Should never reach here, if so the delete then task and free memory */
	vTaskDelete( NULL );
}

void LoggerTest__::LoggerTest_Task4( void *pvParams )
{
	/* Not using */
	(void)pvParams;

	unsigned long count = 0;

    /* Task execution entry */
    for( ; ; )
    {
    	if( xSemaphoreTake( task_sem, portMAX_DELAY ) == pdPASS )
		{
    		logger<< count << ' ' << "Task 4 Logger Task---------------------------------------------\r\n" << logger.endl;
			count += 1;
			logger<< "---------------------------------------------------------------\r\n" << logger.endl;
	    	xSemaphoreGive( task_sem );
		}
    	taskYIELD();
	}

	/* Should never reach here, if so the delete then task and free memory */
	vTaskDelete( NULL );
}

