/******************************************************************************
* Copyright (c) 2019 - Hemant Sharma - All Rights Reserved
*
* Feel free to use this Code at your own risk for your own purposes.
*
*******************************************************************************/
/******************************************************************************
* Title:		Logger API Source
* Filename:		logger.cpp
* Author:		HS
* Origin Date:	11/09/2019
* Version:		1.0.0
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
//#include <cstring>


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
extern "C" UART_HandleTypeDef UART4_Handle;

/* Logger instance */
Logger__ logger( &UART4_Handle, &HAL_UART_Transmit_DMA );

extern "C"
{
	SemaphoreHandle_t xlog_event_sem = NULL;
	SemaphoreHandle_t xlog_tx_mutex = NULL;
	void (*p_Logger__) ( unsigned char *p_data, unsigned short length ) = Logger__::write;
	// or
//	void (*p_Logger__1) ( unsigned char *p_data, unsigned short length ) = logger.write; /* Above is better */
//	logger_fp p_Logger__ = logger.write;
}


/******************************************************************************
* Function Definitions
*******************************************************************************/


/******* Public Member function for Logger__ class *******/


/**
 * @function
 *
 * @brief
 *
 * <i>Imp Note:</i>
 */
Logger__& Logger__::operator<<( const signed short& value )
{
	/* Fill stream with input data */
	std::string string_l = std::to_string( value );
	unsigned long size_l = string_l.length();

	/* Fill buffer with the char values from string */
	_copy( (char *)(buffer_ + index_), string_l.c_str(), size_l );

	/* Update index value */
	index_ += size_l;
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
Logger__& Logger__::operator<<( const unsigned short& value )
{
	/* Fill stream with input data */
	std::string string_l = std::to_string( value );
	unsigned long size_l = string_l.length();

	/* Fill buffer with the char values from string */
	_copy( (char *)(buffer_ + index_), string_l.c_str(), size_l );
	/* Update index value */
	index_ += size_l;
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
Logger__& Logger__::operator<<( const signed int& value )
{
	/* Fill stream with input data */
	std::string string_l = std::to_string( value );
	unsigned long size_l = string_l.length();

	/* Fill buffer with the char values from string */
	_copy( (char *)(buffer_ + index_), string_l.c_str(), size_l );
	/* Update index value */
	index_ += size_l;

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
Logger__& Logger__::operator<<( const unsigned int& value )
{
	/* Fill stream with input data */
	std::string string_l = std::to_string( value );
	unsigned long size_l = string_l.length();

	/* Fill buffer with the char values from string */
	_copy( (char *)(buffer_ + index_), string_l.c_str(), size_l );
	/* Update index value */
	index_ += size_l;

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
Logger__& Logger__::operator<<( const signed long& value )
{
	/* Fill stream with input data */
	std::string string_l = std::to_string( value );
	unsigned long size_l = string_l.length();

	/* Fill buffer with the char values from string */
	_copy( (char *)(buffer_ + index_), string_l.c_str(), size_l );
	/* Update index value */
	index_ += size_l;

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
Logger__& Logger__::operator<<( const signed long long& value )
{
	/* Fill stream with input data */
	std::string string_l = std::to_string( value );
	unsigned long size_l = string_l.length();

	/* Fill buffer with the char values from string */
	_copy( (char *)(buffer_ + index_), string_l.c_str(), size_l );
	/* Update index value */
	index_ += size_l;

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
Logger__& Logger__::operator<<( const unsigned long& value )
{
	/* Fill stream with input data */
	std::string string_l = std::to_string( value );
	unsigned long size_l = string_l.length();

	/* Fill buffer with the char values from string */
	_copy( (char *)(buffer_ + index_), string_l.c_str(), size_l );
	/* Update index value */
	index_ += size_l;

//	char buf[20];
//
//	sprintf( buf, "%lu", value );
//	size_l = strlen( buf );
//	_copy( (char *)(buffer_ + index_), buf, size_l );
//	index_ += size_l;

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
Logger__& Logger__::operator<<( const unsigned long long& value )
{
	/* Fill stream with input data */
	std::string string_l = std::to_string( value );
	unsigned long size_l = string_l.length();

	/* Fill buffer with the char values from string */
	_copy( (char *)(buffer_ + index_), string_l.c_str(), size_l );
	/* Update index value */
	index_ += size_l;

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
Logger__& Logger__::operator<<( const float& value )
{
	/* Fill stream with input data */
	std::string string_l = std::to_string( value );
	unsigned long size_l = string_l.length();

	/* Fill buffer with the char values from string */
	_copy( (char *)(buffer_ + index_), string_l.c_str(), size_l );
	/* Update index value */
	index_ += size_l;

//	char buf[20];
//	sprintf( buf, "%f", value );
//	unsigned long size_l = strlen( buf );
//	_copy( (char *)(buffer_ + index_), buf, size_l );
//	index_ += size_l;

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
Logger__& Logger__::operator<<( const double& value )
{
	/* Fill stream with input data */
	std::string string_l = std::to_string( value );
	unsigned long size_l = string_l.length();

	/* Fill buffer with the char values from string */
	_copy( (char *)(buffer_ + index_), string_l.c_str(), size_l );
	/* Update index value */
	index_ += size_l;

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
Logger__& Logger__::operator<<( const long double& value )
{
	/* Fill stream with input data */
	std::string string_l = std::to_string( value );
	unsigned long size_l = string_l.length();

	/* Fill buffer with the char values from string */
	_copy( (char *)(buffer_ + index_), string_l.c_str(), size_l );
	/* Update index value */
	index_ += size_l;

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
Logger__& Logger__::operator<<( const char& value )
{
	/* Cross check index */
	if( index_ < (::sg_logger_buffer_size - 1) )
	{
		/* Fill buffer with the char values from string */
		_copy( (char *)(buffer_ + index_), &value, 1 );
		/* Update index value */
		index_ += 1;
	}
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
Logger__& Logger__::operator<<( const signed char& value )
{
	if( index_ < (::sg_logger_buffer_size - 1) )
	{
		/* Fill buffer with the char values from string */
		_copy( (char *)(buffer_ + index_), &value, 1 );
		/* Update index value */
		index_ += 1;
	}
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
Logger__& Logger__::operator<<( const unsigned char& value )
{
	if( index_ < (::sg_logger_buffer_size - 1) )
	{
		/* Fill buffer with the char values from string */
		_copy( (char *)(buffer_ + index_), &value, 1 );
		/* Update index value */
		index_ += 1;
	}
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
Logger__& Logger__::operator<<( const char * p_value )
{

	if( NULL == p_value )
	{
		return *this;
	}

	unsigned long size_l = strlen(p_value);

	/* Fill buffer with the char values from string */
	_copy( (char *) (buffer_ + index_), p_value, size_l );
	/* Update index value */
	index_ += size_l;

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
Logger__& Logger__::operator<<( const signed char * p_value )
{
	if( NULL == p_value )
	{
		return *this;
	}

	unsigned long size_l = strlen((const char *)p_value);
	/* Fill buffer with the char values from string */
	_copy( (char *)(buffer_ + index_), p_value, size_l );
	/* Update index value */
	index_ += size_l;

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
Logger__& Logger__::operator<<( const unsigned char * p_value )
{
	if( NULL == p_value )
	{
		return *this;
	}

	unsigned long size_l = strlen((const char *)p_value);
	/* Fill buffer with the char values from string */
	_copy( (char *)(buffer_ + index_), p_value, size_l );
	/* Update index value */
	index_ += size_l;

	/* return for cascading */
	return *this;
}


/********************************** End of File *******************************/
