/*
 * logger_test.h
 *
 *  Created on: 28-Aug-2020
 *      Author: hp
 */

#ifndef LOGGER_TEST_H_
#define LOGGER_TEST_H_


#include <logger.h>

/* RTOS headers inclusion */
#include <rtos_wrappers.h>


class LoggerTest_
{
public:
	static void init()
	{
		vSemaphoreCreateBinary( task_sem );
		configASSERT( LoggerTest_::task_sem );
		/* Create logger test Tasks */
		RTOS_WRAPPER__::create( LoggerTest_::LoggerTest_Task1, (const char *)"LTest1", configMINIMAL_STACK_SIZE << 1, NULL, osPriorityBelowNormal, NULL );
		RTOS_WRAPPER__::create( LoggerTest_::LoggerTest_Task2, (const char *)"LTest2", configMINIMAL_STACK_SIZE << 1, NULL, osPriorityBelowNormal, NULL );
		RTOS_WRAPPER__::create( LoggerTest_::LoggerTest_Task3, (const char *)"LTest3", configMINIMAL_STACK_SIZE << 1, NULL, osPriorityBelowNormal, NULL );
		RTOS_WRAPPER__::create( LoggerTest_::LoggerTest_Task4, (const char *)"LTest4", configMINIMAL_STACK_SIZE << 1, NULL, osPriorityBelowNormal, NULL );
	}

private:

	static SemaphoreHandle_t task_sem;

	static void LoggerTest_Task1( void *pvParams );
	static void LoggerTest_Task2( void *pvParams );
	static void LoggerTest_Task3( void *pvParams );
	static void LoggerTest_Task4( void *pvParams );
};



#endif /* APP_INC_LOGGER_TEST_H_ */
