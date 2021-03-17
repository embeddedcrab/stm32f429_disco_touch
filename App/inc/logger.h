/******************************************************************************
* Copyright (c) 2021 - Hemant Sharma - All Rights Reserved
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
#include <sync.h>


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
 * @brief	Class Logger__
 *
 * \par<b>Description:</b><br>	This logger class can be inherited for creating
 * 	Logging using UART, SD Card or over Network
 *
 * 	<i>Imp Note:</i>
 *
 ******************************************************************************/

class Logger__
{
/* public members */
public:

	Logger__(){}
	Logger__( const Logger__& ) = delete;
	Logger__& operator=( const Logger__& ) = delete;

	virtual ~Logger__(){}


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
	virtual Logger__& operator<<( const signed short& value ) = 0;
	virtual Logger__& operator<<( const unsigned short& value ) = 0;

	virtual Logger__& operator<<( const signed int& value ) = 0;
	virtual Logger__& operator<<( const unsigned int& value ) = 0;

	virtual Logger__& operator<<( const signed long& value ) = 0;
	virtual Logger__& operator<<( const signed long long& value ) = 0;
	virtual Logger__& operator<<( const unsigned long& value ) = 0;
	virtual Logger__& operator<<( const unsigned long long& value ) = 0;

	virtual Logger__& operator<<( const float& value ) = 0;
	virtual Logger__& operator<<( const double& value ) = 0;
	virtual Logger__& operator<<( const long double& value ) = 0;

	virtual Logger__& operator<<( const char& value ) = 0;
	virtual Logger__& operator<<( const signed char& value ) = 0;
	virtual Logger__& operator<<( const unsigned char& value ) = 0;

	virtual Logger__& operator<<( const char * p_value ) = 0;
	virtual Logger__& operator<<( const signed char * p_value ) = 0;
	virtual Logger__& operator<<( const unsigned char * p_value ) = 0;


	virtual Logger__& operator<<( Logger__& (*)(Logger__&) )
	{
		/* Call _write function to send data */
		return *this;
	}


/* private members */
private:


/* protected members, if any */
protected:

	__attribute__((always_inline))virtual inline void _copy( void *p_dest, const void *p_src, size_t size )
	{
		memcpy( p_dest, p_src, size );
	}

	virtual void _write( unsigned char *p_data, unsigned short length )
	{
		(void) p_data;
		(void) length;

		/* Send buffer data to any terminal */
	}
};


/*---------------------------------------------------------------------------*/


/******************************************************************************
 *
 * @brief	Class UART_Logger__
 *
 * \par<b>Description:</b><br>
 *
 * 	<i>Imp Note:</i>
 *
 ******************************************************************************/

class UART_Logger__
{
/* public members */
public:

	UART_Logger__() = delete;
	UART_Logger__( const UART_Logger__& ) = delete;
	UART_Logger__& operator=( const UART_Logger__& ) = delete;

	/** Constructors and Destructors */
	explicit UART_Logger__( void * p_channel_interface, const logger_out &comm_fcn )
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
			memset( (void* )&log_buffer_mutex_, 0, sizeof( unsigned char ) );
			index_ = 0;
		}

		/* Create semaphore for Logging */
		if( (NULL == xlog_event_sem) && (NULL == xlog_tx_mutex) )
		{
			vSemaphoreCreateBinary( xlog_event_sem );
			xlog_tx_mutex = xSemaphoreCreateMutex();
			configASSERT( xlog_event_sem );
			configASSERT( xlog_tx_mutex );
		}
	}

	virtual ~UART_Logger__()
	{
		free( xlog_event_sem );
		free( xlog_tx_mutex );
		xlog_event_sem = NULL;
		xlog_tx_mutex = NULL;
		p_channel_ = nullptr;
		p_fcn_comm_ = nullptr;
	}

	virtual UART_Logger__& operator<<( const signed short& value );
	virtual UART_Logger__& operator<<( const unsigned short& value );

	virtual UART_Logger__& operator<<( const signed int& value );
	virtual UART_Logger__& operator<<( const unsigned int& value );

	virtual UART_Logger__& operator<<( const signed long& value );
	virtual UART_Logger__& operator<<( const signed long long& value );
	virtual UART_Logger__& operator<<( const unsigned long& value );
	virtual UART_Logger__& operator<<( const unsigned long long& value );

	virtual UART_Logger__& operator<<( const float& value );
	virtual UART_Logger__& operator<<( const double& value );
	virtual UART_Logger__& operator<<( const long double& value );

	virtual UART_Logger__& operator<<( const char& value );
	virtual UART_Logger__& operator<<( const signed char& value );
	virtual UART_Logger__& operator<<( const unsigned char& value );

	virtual UART_Logger__& operator<<( const char * p_value );
	virtual UART_Logger__& operator<<( const signed char * p_value );
	virtual UART_Logger__& operator<<( const unsigned char * p_value );


	/* Functions for endl functionality,
	 * Which is responsible to trigger the send operation
	 * */
	static UART_Logger__& endl( UART_Logger__& stream )
	{
		return stream;
	}

	/* Function entry to send data to destination,
	 * This can be overridden for transferring data to hardware device
	 *
	 * <i>Imp Note:</i> For every transfer of data buffers and parameters needs to be reset for fresh transfer
	 * */
	virtual UART_Logger__& operator<<( UART_Logger__& (*)(UART_Logger__&) );


	/* Write function which could be called from C file functions */
	static inline void write( unsigned char *p_data, unsigned short length );


/* private members */
private:
	/** Data Members **/
	void * p_channel_;
	logger_out p_fcn_comm_;

	unsigned char buffer_[::sg_logger_buffer_size];
	unsigned short index_;
	volatile sync_mutex_t log_buffer_mutex_;/* Will take 2 bytes of memory (space!) here */

/* protected members, if any */
protected:

	__attribute__((always_inline))virtual inline void _copy( void *p_dest, const void *p_src, size_t size )
	{
		memcpy( p_dest, p_src, size );
	}

	void _write( unsigned char *p_data, unsigned short length )
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

};


/******************************************************************************
* Variables
*******************************************************************************/
extern UART_Logger__ logger;


/* Can move it to source file also! */
void UART_Logger__::write( unsigned char *p_data, unsigned short length )
{
	const void *p_object = &logger;
	((UART_Logger__*)p_object)->_write( p_data, length );
	/* Wait for Semaphore for this much time at-least and move on!(taken for test only) */
	xSemaphoreTake( xlog_event_sem, pdMS_TO_TICKS(200) );
}


#endif /* LOGGER_H_ */

/********************************** End of File *******************************/
