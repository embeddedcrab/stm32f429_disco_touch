
#include "stm32f4xx.h"
#include "cmsis_os.h"

#include <sync.h>


/* Extern declaration for pointer to logger function */
extern void (*p_Logger__)( unsigned char *, unsigned short );


/* Variable for Thread Synchronization using Mutex test */
static sync_mutex_t volatile sync_bits = { .byte = 0 };


/* For Logger test to be used in C files */
const osThreadAttr_t Task_attributes = {
	.name = "Task",
	.attr_bits = 0,
	.cb_mem = NULL,
	.cb_size = 0,
	.stack_mem = NULL,
	.stack_size = configMINIMAL_STACK_SIZE * 2,
	.priority = (osPriority_t) osPriorityNormal,
	.tz_module = 0
};


/*------- Thread Functions Definitions  -------*/


void thread_1( void * p_arg )
{
    sync_mutex_t volatile * const p_bits = (sync_mutex_t volatile * const)p_arg;
    unsigned char * p_data = (unsigned char *)"******* I am in Thread 1 *******\r\n";
    double dummy = 0.0;

    for( ; ; )
    {
        if( 0 == lock_bit( &(p_bits->byte) ) )
        {
        	dummy += 1.5;
            if( 0 == p_bits->sync )
            {
            	p_Logger__( p_data, 34 );
                p_bits->sync = 1;
            }
            unlock_bit( &(p_bits->byte) );
        }
        else
        {
        	/* For Debugging only, remove it once confirmed */
        	__asm("NOP");
        }
        taskYIELD();
    }

    vTaskDelete( NULL );
}


void thread_2( void * p_arg )
{
	sync_mutex_t volatile * const p_bits = (sync_mutex_t volatile * const)p_arg;
	unsigned char * p_data = (unsigned char *)"******* I am in Thread 2 *******\r\n";
	double dummy = 0.0;

    for( ; ; )
    {
        if( 0 == lock_bit( &(p_bits->byte) ) )
        {
        	dummy += 1.5;
            if( 1 == p_bits->sync )
            {
            	p_Logger__( p_data, 34 );
                p_bits->sync = 0;
            }
            unlock_bit( &(p_bits->byte) );
        }
        else
        {
        	/* For Debugging only, remove it once confirmed */
        	__asm("NOP");
        }
        taskYIELD();
    }

    vTaskDelete( NULL );
}


void thread_3( void * p_arg )
{
    sync_mutex_t volatile * const p_bits = (sync_mutex_t volatile * const)p_arg;
    unsigned char * p_data = (unsigned char *)"******* I am in Thread 3 *******\r\n";
    double dummy = 0.0;

    for( ; ; )
    {
        if( 0 == lock_bit( &(p_bits->byte) ) )
        {
            p_Logger__( p_data, 34 );
        	dummy += 1.5;
            unlock_bit( &(p_bits->byte) );
        }
        else
        {
        	/* For Debugging only, remove it once confirmed */
        	__asm("NOP");
        }
        taskYIELD();
    }

    vTaskDelete( NULL );
}


void thread_4( void * p_arg )
{
    sync_mutex_t volatile * const p_bits = (sync_mutex_t volatile * const)p_arg;
    unsigned char * p_data = (unsigned char *)"******* I am in Thread 4 *******\r\n";
    double dummy = 0.0;

    for( ; ; )
    {
        if( 0 == lock_bit( &(p_bits->byte) ) )
        {
        	p_Logger__( p_data, 34 );
        	dummy += 1.5;
            unlock_bit( &(p_bits->byte) );
        }
        else
        {
        	/* For Debugging only, remove it once confirmed */
        	__asm("NOP");
        }
        taskYIELD();
    }

    vTaskDelete( NULL );
}


void thread_test( void )
{
	osThreadNew( thread_1, (void *)&sync_bits, &Task_attributes);
	osThreadNew( thread_2, (void *)&sync_bits, &Task_attributes);
	osThreadNew( thread_3, (void *)&sync_bits, &Task_attributes);
	osThreadNew( thread_4, (void *)&sync_bits, &Task_attributes);
}


/********************************** End of File *******************************/
