/******************************************************************************
* Copyright (c) 2021 - Hemant Sharma - All Rights Reserved
*
* Feel free to use this Code at your own risk for your own purposes.
*
*******************************************************************************/
/******************************************************************************
* Title:		Logger API Source
* Filename:		logger.cpp
* Author:		HS
* Origin Date:		02/23/2021
* Version:		1.1.0
* Notes:
*
* Change History
* --------------
*
*******************************************************************************/

/** @file:	logger.cpp
 *  @brief:	This source file contains API function definitions for
 *  		Logger class.
 *
 *  		Optimization can be done by using different ways to change data into char array
 */


/******************************************************************************
* Includes
*******************************************************************************/

/* Include class headers */
#include <logger.h>

/* For basic string functions */
#include <string>


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

typedef void (*logger_fp) ( unsigned char *p_data, unsigned short length );


/******************************************************************************
* Variables
*******************************************************************************/

/* UART Channel 4 Handle */
extern "C"
{
	extern UART_HandleTypeDef UART4_Handle;

	SemaphoreHandle_t xlog_event_sem = NULL;
	SemaphoreHandle_t xlog_tx_mutex = NULL;
}


/* Logger instance */
UART_Logger__ logger( &UART4_Handle, &HAL_UART_Transmit_DMA );


extern "C"
{
	void (*p_Logger__) ( unsigned char *p_data, unsigned short length ) = UART_Logger__::write;
	// or
//	void (*p_Logger__1) ( unsigned char *p_data, unsigned short length ) = logger.write; /* Above is better */
//	logger_fp p_Logger__ = logger.write;
}


/******************************************************************************
* Function Definitions
*******************************************************************************/


/******* Public Member function for UART_Logger__ class *******/


/**
 * @function
 *
 * @brief
 *
 * <i>Imp Note:</i>
 */
UART_Logger__& UART_Logger__::operator<<( const signed short& value )
{
	/* Fill stream with input data */
	std::string string_l = std::to_string( value );
	unsigned long size_l = string_l.length();

	GET_BIT_LOCK(log_buffer_mutex_);
	{
		/* Cross check index */
		if( size_l > ( ::sg_logger_buffer_size - index_ ) )
		{
			/* Send buffer data to output first */
			_write( buffer_, index_ );
			memset( (void *)buffer_, '\0', ::sg_logger_buffer_size );
			index_ = 0;
		}

		/* Fill buffer with the char values from string */
		_copy( (char *)(buffer_ + index_), string_l.c_str(), size_l );
		/* Update index value */
		index_ += size_l;
	}
	RELEASE_BIT_LOCK(log_buffer_mutex_);

	/* return for cascading */
	return *this;
}


/**
 * @function
 *
 * @brief
 *
 * <i>Imp Note:</i>
 */
UART_Logger__& UART_Logger__::operator<<( const unsigned short& value )
{
	/* Fill stream with input data */
	std::string string_l = std::to_string( value );
	unsigned long size_l = string_l.length();

	/* Take Buffer Mutex and fill data into Buffer */
	GET_BIT_LOCK(log_buffer_mutex_);
	{
		/* Cross check index */
		if( size_l > ( ::sg_logger_buffer_size - index_ ) )
		{
			/* Send buffer data to output first */
			_write( buffer_, index_ );
			memset( (void *)buffer_, '\0', ::sg_logger_buffer_size );
			index_ = 0;
		}

		/* Fill buffer with the char values from string */
		_copy( (char *)(buffer_ + index_), string_l.c_str(), size_l );
		/* Update index value */
		index_ += size_l;
	}
	RELEASE_BIT_LOCK(log_buffer_mutex_);

	/* return for cascading */
	return *this;
}


/**
 * @function
 *
 * @brief
 *
 * <i>Imp Note:</i>
 */
UART_Logger__& UART_Logger__::operator<<( const signed int& value )
{
	/* Fill stream with input data */
	std::string string_l = std::to_string( value );
	unsigned long size_l = string_l.length();

	/* Take Buffer Mutex and fill data into Buffer */
	GET_BIT_LOCK(log_buffer_mutex_);
	{
		/* Cross check index */
		if( size_l > ( ::sg_logger_buffer_size - index_ ) )
		{
			/* Send buffer data to output first */
			_write( buffer_, index_ );
			memset( (void *)buffer_, '\0', ::sg_logger_buffer_size );
			index_ = 0;
		}

		/* Fill buffer with the char values from string */
		_copy( (char *)(buffer_ + index_), string_l.c_str(), size_l );
		/* Update index value */
		index_ += size_l;
	}
	RELEASE_BIT_LOCK(log_buffer_mutex_);

	/* return for cascading */
	return *this;
}


/**
 * @function
 *
 * @brief
 *
 * <i>Imp Note:</i>
 */
UART_Logger__& UART_Logger__::operator<<( const unsigned int& value )
{
	/* Fill stream with input data */
	std::string string_l = std::to_string( value );
	unsigned long size_l = string_l.length();

	/* Take Buffer Mutex and fill data into Buffer */
	GET_BIT_LOCK(log_buffer_mutex_);
	{
		/* Cross check index */
		if( size_l > ( ::sg_logger_buffer_size - index_ ) )
		{
			/* Send buffer data to output first */
			_write( buffer_, index_ );
			memset( (void *)buffer_, '\0', ::sg_logger_buffer_size );
			index_ = 0;
		}

		/* Fill buffer with the char values from string */
		_copy( (char *)(buffer_ + index_), string_l.c_str(), size_l );
		/* Update index value */
		index_ += size_l;
	}
	RELEASE_BIT_LOCK(log_buffer_mutex_);

	/* return for cascading */
	return *this;
}


/**
 * @function
 *
 * @brief
 *
 * <i>Imp Note:</i>
 */
UART_Logger__& UART_Logger__::operator<<( const signed long& value )
{
	/* Fill stream with input data */
	std::string string_l = std::to_string( value );
	unsigned long size_l = string_l.length();

	/* Take Buffer Mutex and fill data into Buffer */
	GET_BIT_LOCK(log_buffer_mutex_);
	{
		/* Cross check index */
		if( size_l > ( ::sg_logger_buffer_size - index_ ) )
		{
			/* Send buffer data to output first */
			_write( buffer_, index_ );
			memset( (void *)buffer_, '\0', ::sg_logger_buffer_size );
			index_ = 0;
		}

		/* Fill buffer with the char values from string */
		_copy( (char *)(buffer_ + index_), string_l.c_str(), size_l );
		/* Update index value */
		index_ += size_l;
	}
	RELEASE_BIT_LOCK(log_buffer_mutex_);

	/* return for cascading */
	return *this;
}


/**
 * @function
 *
 * @brief
 *
 * <i>Imp Note:</i>
 */
UART_Logger__& UART_Logger__::operator<<( const signed long long& value )
{
	/* Fill stream with input data */
	std::string string_l = std::to_string( value );
	unsigned long size_l = string_l.length();

	/* Take Buffer Mutex and fill data into Buffer */
	GET_BIT_LOCK(log_buffer_mutex_);
	{
		/* Cross check index */
		if( size_l > ( ::sg_logger_buffer_size - index_ ) )
		{
			/* Send buffer data to output first */
			_write( buffer_, index_ );
			memset( (void *)buffer_, '\0', ::sg_logger_buffer_size );
			index_ = 0;
		}

		/* Fill buffer with the char values from string */
		_copy( (char *)(buffer_ + index_), string_l.c_str(), size_l );
		/* Update index value */
		index_ += size_l;
	}
	RELEASE_BIT_LOCK(log_buffer_mutex_);

	/* return for cascading */
	return *this;
}


/**
 * @function
 *
 * @brief
 *
 * <i>Imp Note:</i>
 */
UART_Logger__& UART_Logger__::operator<<( const unsigned long& value )
{
	/* Fill stream with input data */
	std::string string_l = std::to_string( value );
	unsigned long size_l = string_l.length();

	/* Take Buffer Mutex and fill data into Buffer */
	GET_BIT_LOCK(log_buffer_mutex_);
	{
		/* Cross check index */
		if( size_l > ( ::sg_logger_buffer_size - index_ ) )
		{
			/* Send buffer data to output first */
			_write( buffer_, index_ );
			memset( (void *)buffer_, '\0', ::sg_logger_buffer_size );
			index_ = 0;
		}

		/* Fill buffer with the char values from string */
		_copy( (char *)(buffer_ + index_), string_l.c_str(), size_l );
		/* Update index value */
		index_ += size_l;
	}
	RELEASE_BIT_LOCK(log_buffer_mutex_);

	/* return for cascading */
	return *this;
}


/**
 * @function
 *
 * @brief
 *
 * <i>Imp Note:</i>
 */
UART_Logger__& UART_Logger__::operator<<( const unsigned long long& value )
{
	/* Fill stream with input data */
	std::string string_l = std::to_string( value );
	unsigned long size_l = string_l.length();

	/* Take Buffer Mutex and fill data into Buffer */
	GET_BIT_LOCK(log_buffer_mutex_);
	{
		/* Cross check index */
		if( size_l > ( ::sg_logger_buffer_size - index_ ) )
		{
			/* Send buffer data to output first */
			_write( buffer_, index_ );
			memset( (void *)buffer_, '\0', ::sg_logger_buffer_size );
			index_ = 0;
		}

		/* Fill buffer with the char values from string */
		_copy( (char *)(buffer_ + index_), string_l.c_str(), size_l );
		/* Update index value */
		index_ += size_l;
	}
	RELEASE_BIT_LOCK(log_buffer_mutex_);

	/* return for cascading */
	return *this;
}


/**
 * @function
 *
 * @brief
 *
 * <i>Imp Note:</i>
 */
UART_Logger__& UART_Logger__::operator<<( const float& value )
{
	/* Fill stream with input data */
	std::string string_l = std::to_string( value );
	unsigned long size_l = string_l.length();

	/* Take Buffer Mutex and fill data into Buffer */
	GET_BIT_LOCK(log_buffer_mutex_);
	{
		/* Cross check index */
		if( size_l > ( ::sg_logger_buffer_size - index_ ) )
		{
			/* Send buffer data to output first */
			_write( buffer_, index_ );
			memset( (void *)buffer_, '\0', ::sg_logger_buffer_size );
			index_ = 0;
		}

		/* Fill buffer with the char values from string */
		_copy( (char *)(buffer_ + index_), string_l.c_str(), size_l );
		/* Update index value */
		index_ += size_l;
	}
	RELEASE_BIT_LOCK(log_buffer_mutex_);

	/* return for cascading */
	return *this;
}


/**
 * @function
 *
 * @brief
 *
 * <i>Imp Note:</i>
 */
UART_Logger__& UART_Logger__::operator<<( const double& value )
{
	/* Fill stream with input data */
	std::string string_l = std::to_string( value );
	unsigned long size_l = string_l.length();

	/* Take Buffer Mutex and fill data into Buffer */
	GET_BIT_LOCK(log_buffer_mutex_);
	{
		/* Cross check index */
		if( size_l > ( ::sg_logger_buffer_size - index_ ) )
		{
			/* Send buffer data to output first */
			_write( buffer_, index_ );
			memset( (void *)buffer_, '\0', ::sg_logger_buffer_size );
			index_ = 0;
		}

		/* Fill buffer with the char values from string */
		_copy( (char *)(buffer_ + index_), string_l.c_str(), size_l );
		/* Update index value */
		index_ += size_l;
	}
	RELEASE_BIT_LOCK(log_buffer_mutex_);

	/* return for cascading */
	return *this;
}


/**
 * @function
 *
 * @brief
 *
 * <i>Imp Note:</i>
 */
UART_Logger__& UART_Logger__::operator<<( const long double& value )
{
	/* Fill stream with input data */
	std::string string_l = std::to_string( value );
	unsigned long size_l = string_l.length();

	/* Take Buffer Mutex and fill data into Buffer */
	GET_BIT_LOCK(log_buffer_mutex_);
	{
		/* Cross check index */
		if( size_l > ( ::sg_logger_buffer_size - index_ ) )
		{
			/* Send buffer data to output first */
			_write( buffer_, index_ );
			memset( (void *)buffer_, '\0', ::sg_logger_buffer_size );
			index_ = 0;
		}

		/* Fill buffer with the char values from string */
		_copy( (char *)(buffer_ + index_), string_l.c_str(), size_l );
		/* Update index value */
		index_ += size_l;
	}
	RELEASE_BIT_LOCK(log_buffer_mutex_);

	/* return for cascading */
	return *this;
}


/**
 * @function
 *
 * @brief
 *
 * <i>Imp Note:</i>
 */
UART_Logger__& UART_Logger__::operator<<( const char& value )
{
	/* Take Buffer Mutex and fill data into Buffer */
	GET_BIT_LOCK(log_buffer_mutex_);
	{
		/* Cross check index */
		if( ::sg_logger_buffer_size == index_ )
		{
			/* Send data to output */
			_write( buffer_, index_ );
			memset( (void *)buffer_, '\0', ::sg_logger_buffer_size );
			index_ = 0;
		}

		/* Fill buffer with the char values from string */
		_copy( (char *)(buffer_ + index_), &value, 1 );
		/* Update index value */
		index_ += 1;
	}
	RELEASE_BIT_LOCK(log_buffer_mutex_);

	/* return for cascading */
	return *this;
}


/**
 * @function
 *
 * @brief
 *
 * <i>Imp Note:</i>
 */
UART_Logger__& UART_Logger__::operator<<( const signed char& value )
{
	/* Take Buffer Mutex and fill data into Buffer */
	GET_BIT_LOCK(log_buffer_mutex_);
	{
		/* Cross check index */
		if( ::sg_logger_buffer_size == index_ )
		{
			/* Send data to output */
			_write( buffer_, index_ );
			memset( (void *)buffer_, '\0', ::sg_logger_buffer_size );
			index_ = 0;
		}

		/* Fill buffer with the char values from string */
		_copy( (char *)(buffer_ + index_), &value, 1 );
		/* Update index value */
		index_ += 1;
	}
	RELEASE_BIT_LOCK(log_buffer_mutex_);

	/* return for cascading */
	return *this;
}


/**
 * @function
 *
 * @brief
 *
 * <i>Imp Note:</i>
 */
UART_Logger__& UART_Logger__::operator<<( const unsigned char& value )
{
	/* Take Buffer Mutex and fill data into Buffer */
	GET_BIT_LOCK(log_buffer_mutex_);
	{
		/* Cross check index */
		if( ::sg_logger_buffer_size == index_ )
		{
			/* Send data to output */
			_write( buffer_, index_ );
			memset( (void *)buffer_, '\0', ::sg_logger_buffer_size );
			index_ = 0;
		}

		/* Fill buffer with the char values from string */
		_copy( (char *)(buffer_ + index_), &value, 1 );
		/* Update index value */
		index_ += 1;
	}
	RELEASE_BIT_LOCK(log_buffer_mutex_);

	/* return for cascading */
	return *this;
}


/**
 * @function
 *
 * @brief
 *
 * <i>Imp Note:</i>
 */
UART_Logger__& UART_Logger__::operator<<( const char * p_value )
{

	if( NULL == p_value )
	{
		return *this;
	}

	unsigned long size_l = strlen(p_value);

	/* Take Buffer Mutex and fill data into Buffer */
	GET_BIT_LOCK(log_buffer_mutex_);
	{
		/* Cross check index */
		if( size_l > ( ::sg_logger_buffer_size - index_ ) )
		{
			/* Send buffer data to output first */
			_write( buffer_, index_ );
			memset( (void *)buffer_, '\0', ::sg_logger_buffer_size );
			index_ = 0;
		}

		/* Fill buffer with the char values from string */
		_copy( (char *) (buffer_ + index_), p_value, size_l );
		/* Update index value */
		index_ += size_l;
	}
	RELEASE_BIT_LOCK(log_buffer_mutex_);

	/* return for cascading */
	return *this;
}


/**
 * @function
 *
 * @brief
 *
 * <i>Imp Note:</i>
 */
UART_Logger__& UART_Logger__::operator<<( const signed char * p_value )
{
	if( NULL == p_value )
	{
		return *this;
	}

	unsigned long size_l = strlen((const char *)p_value);

	/* Take Buffer Mutex and fill data into Buffer */
	GET_BIT_LOCK(log_buffer_mutex_);
	{
		/* Cross check index */
		if( size_l > ( ::sg_logger_buffer_size - index_ ) )
		{
			/* Send buffer data to output first */
			_write( buffer_, index_ );
			memset( (void *)buffer_, '\0', ::sg_logger_buffer_size );
			index_ = 0;
		}

		/* Fill buffer with the char values from string */
		_copy( (char *)(buffer_ + index_), p_value, size_l );
		/* Update index value */
		index_ += size_l;
	}
	RELEASE_BIT_LOCK(log_buffer_mutex_);

	/* return for cascading */
	return *this;
}


/**
 * @function
 *
 * @brief
 *
 * <i>Imp Note:</i>
 */
UART_Logger__& UART_Logger__::operator<<( const unsigned char * p_value )
{
	if( NULL == p_value )
	{
		return *this;
	}

	unsigned long size_l = strlen((const char *)p_value);

	/* Take Buffer Mutex and fill data into Buffer */
	GET_BIT_LOCK(log_buffer_mutex_);
	{
		/* Cross check index */
		if( size_l > ( ::sg_logger_buffer_size - index_ ) )
		{
			/* Send buffer data to output first */
			_write( buffer_, index_ );
			memset( (void *)buffer_, '\0', ::sg_logger_buffer_size );
			index_ = 0;
		}

		/* Fill buffer with the char values from string */
		_copy( (char *)(buffer_ + index_), p_value, size_l );
		/* Update index value */
		index_ += size_l;
	}
	RELEASE_BIT_LOCK(log_buffer_mutex_);

	/* return for cascading */
	return *this;
}


/**
 * @function
 *
 * @brief
 *
 * <i>Imp Note:</i>
 */
UART_Logger__& UART_Logger__::operator<<( UART_Logger__& (*)(UART_Logger__&) )
{
	GET_BIT_LOCK(log_buffer_mutex_ );
	log_buffer_mutex_.write = 0;
	log_buffer_mutex_.sync = 0;
	log_buffer_mutex_.read = 1;
	_write( (unsigned char *)buffer_, index_ );
	log_buffer_mutex_.read = 0;
	RELEASE_BIT_LOCK(log_buffer_mutex_);

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
		GET_BIT_LOCK(log_buffer_mutex_ );
		memset( (void *)buffer_, '\0', ::sg_logger_buffer_size );
		index_ = 0;
		RELEASE_BIT_LOCK(log_buffer_mutex_);
	}
	/* Return object reference */
	return *this;
}

/********************************** End of File *******************************/
