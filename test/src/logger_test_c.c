
#include "stm32f4xx.h"
#include "cmsis_os.h"


extern void (*p_Logger__)( unsigned char *, unsigned short );


/* For Logger test to be used in C files */
const osThreadAttr_t Task_attributes = {
	.name = "Task",
	.attr_bits = 0,
	.cb_mem = NULL,
	.cb_size = 0,
	.stack_mem = NULL,
	.stack_size = configMINIMAL_STACK_SIZE,
	.priority = (osPriority_t) osPriorityBelowNormal,
	.tz_module = 0
};


void dummy_freeRTOS_task( void *pvParams )
{
	(void) pvParams;
	unsigned char * p_data = (unsigned char *)"Hello World\r\n";

	for( ; ; )
	{
		p_Logger__( p_data, 13 );
		vTaskDelay(200);
	}
}


void logger_test_c( void )
{
	osThreadNew( dummy_freeRTOS_task, NULL, &Task_attributes);
}
