

#include <logger_test.h>

#include "stm32f4xx.h"
#include <semphr.h>


SemaphoreHandle_t LoggerTest_::task_sem;

extern "C" SemaphoreHandle_t xlog_event_sem;
extern "C" UART_HandleTypeDef UART4_Handle;


void LoggerTest_::LoggerTest_Task1( void *pvParams )
{
	/* Not using */
	(void)pvParams;

	unsigned long count = 0;

    /* Task execution entry */
    for( ; ; )
    {
    	if( xSemaphoreTake( task_sem, portMAX_DELAY ) == pdPASS )
		{
//    		logger<< "Task 1 Logger Task---------------------------------------------\r\n" << logger.endl;
			logger<< count << ' ' << "Task 1 Logger Task---------------------------------------------\r\n" << logger.endl;
			count += 1;
	    	xSemaphoreGive( task_sem );
		}
    	taskYIELD();
//    	vTaskDelay(100);
	}

	/* Should never reach here, if so the delete then task and free memory */
	vTaskDelete( NULL );
}

void LoggerTest_::LoggerTest_Task2( void *pvParams )
{
	/* Not using */
	(void)pvParams;

	unsigned long count = 0;

    /* Task execution entry */
    for( ; ; )
    {
    	if( xSemaphoreTake( task_sem, portMAX_DELAY ) == pdPASS )
		{
//    		logger<< "Task 2 Logger Task---------------------------------------------\r\n" << logger.endl;
    		logger<< count << ' ' << "Task 2 Logger Task---------------------------------------------\r\n" << logger.endl;
			count += 1;
	    	xSemaphoreGive( task_sem );
		}
    	taskYIELD();
//    	vTaskDelay(100);
	}

	/* Should never reach here, if so the delete then task and free memory */
	vTaskDelete( NULL );
}

void LoggerTest_::LoggerTest_Task3( void *pvParams )
{
	/* Not using */
	(void)pvParams;

	unsigned long count = 0;

    /* Task execution entry */
    for( ; ; )
    {
    	if( xSemaphoreTake( task_sem, portMAX_DELAY ) == pdPASS )
		{
//    		logger<< "Task 3 Logger Task---------------------------------------------\r\n" << logger.endl;
    		logger<< count << ' ' << "Task 3 Logger Task---------------------------------------------\r\n" << logger.endl;
			count += 1;
	    	xSemaphoreGive( task_sem );
		}
    	taskYIELD();
//    	vTaskDelay(100);
	}

	/* Should never reach here, if so the delete then task and free memory */
	vTaskDelete( NULL );
}

void LoggerTest_::LoggerTest_Task4( void *pvParams )
{
	/* Not using */
	(void)pvParams;

	unsigned long count = 0;

    /* Task execution entry */
    for( ; ; )
    {
    	if( xSemaphoreTake( task_sem, portMAX_DELAY ) == pdPASS )
		{
//    		logger<< "Task 4 Logger Task---------------------------------------------\r\n" << logger.endl;
    		logger<< count << ' ' << "Task 4 Logger Task---------------------------------------------\r\n" << logger.endl;
			count += 1;
	    	xSemaphoreGive( task_sem );
		}
    	taskYIELD();
//    	vTaskDelay(100);
	}

	/* Should never reach here, if so the delete then task and free memory */
	vTaskDelete( NULL );
}

