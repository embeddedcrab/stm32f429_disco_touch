/******************************************************************************
* Copyright (c) 2019 - Hemant Sharma - All Rights Reserved
*
* Feel free to use this Code at your own risk for your own purposes.
*
*******************************************************************************/
/******************************************************************************
* Title:		Logger API Header
* Filename:		logger.h
* Author:		HS
* Origin Date:	11/09/2019
* Version:		1.0.0
* Notes:
*******************************************************************************/

/** @file:	logger.h
 *  @brief:	This file contains API function declarations
 *  		for Logger which can use any hardware for logging
 */
#ifndef LOGGER_H_
#define LOGGER_H_


/******************************************************************************
* Includes
*******************************************************************************/
#include "stm32f4xx.h"
#include <cmsis_os.h>
#include <semphr.h>
#include <dri_mem.h>


/******************************************************************************
* Preprocessor Constants
*******************************************************************************/


/******************************************************************************
* Configuration Constants
*******************************************************************************/

/* For Data conversion and storing into buffer */
constexpr unsigned char g_logger_buffers = 3;

/* Logger buffer size */
constexpr unsigned long sg_logger_buffer_size = 512;


/******************************************************************************
* Macros
*******************************************************************************/

#define LOGGER_COMM_CHANNEL( channel )			((UART_HandleTypeDef *)channel)

/* Shall be used for different interface for different class objects */
#define LOGGER_COMM_INTERFACE( interface )


/******************************************************************************
* Typedefs
*******************************************************************************/

typedef HAL_StatusTypeDef (*logger_out)(UART_HandleTypeDef*, uint8_t*, uint16_t);
/* typedef and some respective implementations shall be changed for generic nature of class,
 * so that any interface could be used which accepts arguments as follows:
 * 1 -> void * (shall be type-casted in virtual function of derived class for y other interface
 * 2 and 3 may remain same
 * */
typedef long (*logger_out_)(void *, uint8_t*, uint16_t);


/******************************************************************************
* Function Prototypes
*******************************************************************************/


/******************************************************************************
* Variables
*******************************************************************************/

extern "C"
{
	extern SemaphoreHandle_t xlog_event_sem;
	extern SemaphoreHandle_t xlog_tx_mutex;
}


/******************************************************************************
 *
 * @brief	Class for Logger__ Instance
 *
 * \par<b>Description:</b><br>	This logger class can be interfaced with any
 * 	peripheral like; UART, SD Card, Network
 *
 * 	<i>Imp Note:</i>	Initialization of peripheral is not taken care
 *
 ******************************************************************************/

class Logger__
{
/* public members */
public:

	/** Constructors and Destructors */
	explicit Logger__( void * p_channel_interface, const logger_out &comm_fcn )
		: p_channel_( p_channel_interface ), p_fcn_comm_(comm_fcn)
	{
		if( (nullptr == p_channel_interface) || (nullptr == comm_fcn) )
		{
			for( ; ; )
			{
				__asm("NOP");
			}
		}
		else
		{
			/* Class members initialization */
			memset( (void *)buffer_, '\0', ::sg_logger_buffer_size );
			index_ = 0;
		}

		/* Create semaphore for Logging */
		vSemaphoreCreateBinary( xlog_event_sem );
		xlog_tx_mutex = xSemaphoreCreateMutex();
		configASSERT( xlog_event_sem );
		configASSERT( xlog_tx_mutex );
	}

	virtual ~Logger__()
	{
		__asm("NOP");
	}

	Logger__( const Logger__& ) = delete;
	Logger__& operator=( const Logger__& ) = delete;

	/******* API Member functions *******/

	/**
	 * @function	<< operator overloading for different values
	 *
	 * @brief		These functions will fill buffer with input data for logging
	 *
	 * @param[in]	value
	 *
	 * @param[out]	NA
	 *
	 * @return		object reference
	 *
	 * \par<b>Description:</b><br>
	 *
	 * <i>Imp Note:</i>
	 *
	 */
	/* Library dependencies */
	Logger__& operator<<( const signed short& value );
	Logger__& operator<<( const unsigned short& value );

	Logger__& operator<<( const signed int& value );
	Logger__& operator<<( const unsigned int& value );

	Logger__& operator<<( const signed long& value );
	Logger__& operator<<( const signed long long& value );
	Logger__& operator<<( const unsigned long& value );
	Logger__& operator<<( const unsigned long long& value );

	Logger__& operator<<( const float& value );
	Logger__& operator<<( const double& value );
	Logger__& operator<<( const long double& value );

	/* Working fine without additional libraries */
	Logger__& operator<<( const char& value );
	Logger__& operator<<( const signed char& value );
	Logger__& operator<<( const unsigned char& value );

	Logger__& operator<<( const char * p_value );
	Logger__& operator<<( const signed char * p_value );
	Logger__& operator<<( const unsigned char * p_value );

	/* Functions for endl functionality,
	 * Which is responsible to trigger the send operation
	 * */
	static Logger__& endl( Logger__& stream )
	{
		return stream;
	}

	/* Function entry to send data to destination,
	 * This can be overridden for transferring data to hardware device
	 *
	 * <i>Imp Note:</i> For every transfer of data buffers and parameters needs to be reset for fresh transfer
	 * */
	virtual Logger__& operator<<( Logger__& end(Logger__&) )
	{
		/* Write data to hw driver */
		_write( (unsigned char *)buffer_, index_ );
		/* Wait for data transfer completion using Semaphore */
		if( xSemaphoreTake( xlog_event_sem, pdMS_TO_TICKS(200) ) != pdPASS )
		{
			/* If data sent confirmation is not there then take it into next cycle of transmission,
			 * But if data goes beyond buffer size then buffer will be overwritten.
			 * Buffer size is kept according to embedded applications and shall work fine. */
			/* for Debugging only */
			__asm("NOP");/* Oops, Data not reliably sent! */
		}
		else
		{
			memset( (void *)buffer_, '\0', ::sg_logger_buffer_size );
			index_ = 0;
		}
		/* Return object reference */
		return *this;
	}


	/* Write function which could be called from C file functions */
	static inline void write( unsigned char *p_data, unsigned short length );


/* private members */
private:
	/** Data Members **/
	void * p_channel_;
	logger_out p_fcn_comm_;

	unsigned char buffer_[::sg_logger_buffer_size];
	unsigned short index_;


	/******* Private Member Functions *******/

	__attribute__((always_inline))inline void _copy( void *p_dest, const void *p_src, size_t size )
	{
		memcpy( p_dest, p_src, size );
	}

	virtual void _write( unsigned char *p_data, unsigned short length )
	{
		BaseType_t mutex_ret = pdFALSE;
		/* Take Mutex */
		mutex_ret = xSemaphoreTake( xlog_tx_mutex, portMAX_DELAY );
		if( pdTRUE == mutex_ret )
		{
			/* Send data to output using HW layer */
			p_fcn_comm_( LOGGER_COMM_CHANNEL(p_channel_), p_data, length );
		}
		if( pdTRUE == mutex_ret )
		{
			/* Release Mutex */
			xSemaphoreGive( xlog_tx_mutex );
		}
	}


/* protected members, if any */
protected:

};


/******************************************************************************
* Variables
*******************************************************************************/
extern Logger__ logger;


/* Can move it to source file also! */
void Logger__::write( unsigned char *p_data, unsigned short length )
{
	const void *p_object = &logger;
	((Logger__*)p_object)->_write( p_data, length );
	/* Wait for Semaphore for this much time at-least and move on!(taken for test only) */
	xSemaphoreTake( xlog_event_sem, pdMS_TO_TICKS(200) );
}


#endif /* LOGGER_H_ */

/********************************** End of File *******************************/
