/******************************************************************************
* Copyright (c) 2019 - Hemant Sharma - All Rights Reserved
*
* Feel free to use this Code at your own risk for your own purposes.
*
*******************************************************************************/
/******************************************************************************
* Title:		Memory Header file
* Filename:		dri_mem.h
* Author:		HS
* Origin Date:	10/04/2019
* Version:		1.0.0
* Notes:
*******************************************************************************/

/** @file:	dri_mem.h
 *  @brief:	This file contains memory allocation operator wrappers for FreeRTOS
 *  		environment
 */
#ifndef DRI_MEM_H_
#define DRI_MEM_H_


/******************************************************************************
* Includes
*******************************************************************************/
#include <FreeRTOS.h>

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


/******************************************************************************
* Function Prototypes
 *******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @function
 *
 * @brief
 *
 * @param[in]
 *
 * @param[out]
 *
 * @return
 *
 * \par<b>Description:</b><br>
 *
 * <i>Imp Note:</i>
 *
 */
int memcmp( const void *, const void *, size_t );


/**
 * @function
 *
 * @brief
 *
 * @param[in]
 *
 * @param[out]
 *
 * @return
 *
 * \par<b>Description:</b><br>
 *
 * <i>Imp Note:</i>
 *
 */
void *memcpy( void *, const void *, size_t );


/**
 * @function
 *
 * @brief
 *
 * @param[in]
 *
 * @param[out]
 *
 * @return
 *
 * \par<b>Description:</b><br>
 *
 * <i>Imp Note:</i>
 *
 */
void *memset( void *, int, size_t );


/**
 * @function
 *
 * @brief
 *
 * @param[in]
 *
 * @param[out]
 *
 * @return
 *
 * \par<b>Description:</b><br>
 *
 * <i>Imp Note:</i>
 *
 */
void *malloc( size_t size );


/**
 * @function
 *
 * @brief
 *
 * @param[in]
 *
 * @param[out]
 *
 * @return
 *
 * \par<b>Description:</b><br>
 *
 * <i>Imp Note:</i>
 *
 */
void free( void * p_arg );


/**
 * @function
 *
 * @brief
 *
 * @param[in]
 *
 * @param[out]
 *
 * @return
 *
 * \par<b>Description:</b><br>
 *
 * <i>Imp Note:</i>
 *
 */

void *realloc( void * p_arg, size_t size );


/**
 * @function
 *
 * @brief
 *
 * @param[in]
 *
 * @param[out]
 *
 * @return
 *
 * \par<b>Description:</b><br>
 *
 * <i>Imp Note:</i>
 *
 */
void *calloc( size_t nmemb , size_t size );


/**
 * @function
 *
 * @brief
 *
 * @param[in]
 *
 * @param[out]
 *
 * @return
 *
 * \par<b>Description:</b><br>
 *
 * <i>Imp Note:</i>
 *
 */
void *memalign( size_t alignment, size_t size );


/**
 * @function
 *
 * @brief
 *
 * @param[in]
 *
 * @param[out]
 *
 * @return
 *
 * \par<b>Description:</b><br>
 *
 * <i>Imp Note:</i>
 *
 */
int strcmp( const char *, const char * );


/**
 * @function
 *
 * @brief
 *
 * @param[in]
 *
 * @param[out]
 *
 * @return
 *
 * \par<b>Description:</b><br>
 *
 * <i>Imp Note:</i>
 *
 */
int strncmp( const char *, const char *, size_t );


/**
 * @function
 *
 * @brief
 *
 * @param[in]
 *
 * @param[out]
 *
 * @return
 *
 * \par<b>Description:</b><br>
 *
 * <i>Imp Note:</i>
 *
 */
char * strcpy( char *__restrict, const char *__restrict );


/**
 * @function
 *
 * @brief
 *
 * @param[in]
 *
 * @param[out]
 *
 * @return
 *
 * \par<b>Description:</b><br>
 *
 * <i>Imp Note:</i>
 *
 */
char *strncpy( char *, const char *, size_t );


/**
 * @function
 *
 * @brief
 *
 * @param[in]
 *
 * @param[out]
 *
 * @return
 *
 * \par<b>Description:</b><br>
 *
 * <i>Imp Note:</i>
 *
 */
size_t strlen( const char * );


#ifdef __cplusplus
}
#endif	/* extern "C" linkage */


#ifdef __cplusplus

/**
 * @function	Operator overloading for new
 *
 * @brief		This function is a C++ wrapper for portmalloc from FreeRTOS
 *
 * @param[in]	Size of data
 *
 * @param[out]	Memory allocated address
 *
 * @return  	Memory allocated for variables address
 *
 * \par<b>Description:</b><br>
 * 				These kind of wrappers can be used for any RTOS which provide
 * 				memory allocation in C standard
 *
 * <i>Imp Note:</i>
 *
 */
inline void * operator new( size_t size )
{
	return pvPortMalloc( size );
}


/**
 * @function	Operator overloading for new with array of elements
 *
 * @brief		This function is a C++ wrapper for portmalloc from FreeRTOS
 *
 * @param[in]	Size of data and array
 *
 * @param[out]	Memory allocated address
 *
 * @return  	Memory allocated for variables address
 *
 * \par<b>Description:</b><br>
 * 				These kind of wrappers can be used for any RTOS which provide
 * 				memory allocation in C standard
 *
 * <i>Imp Note:</i>
 *
 */
inline void * operator new[]( size_t size )
{
	return pvPortMalloc( size );
}


/**
 * @function	operator overloading for delete
 *
 * @brief		This function deallocates previously allocated memory from heap
 *
 * @param[in]	Memory address
 *
 * @param[out]	NA
 *
 * @return  	NA
 *
 * \par<b>Description:</b><br>
 * 				These kind of wrappers can be used for any RTOS which provide
 * 				memory allocation in C standard
 *
 * <i>Imp Note:</i>
 *
 */
inline void operator delete( void * p_arg )
{
	vPortFree( p_arg );
}


/**
 * @function	operator overloading for delete with array
 *
 * @brief		This function deallocates previously allocated memory from heap
 *
 * @param[in]	Memory address
 *
 * @param[out]	NA
 *
 * @return  	NA
 *
 * \par<b>Description:</b><br>
 * 				These kind of wrappers can be used for any RTOS which provide
 * 				memory allocation in C standard
 *
 * <i>Imp Note:</i>
 *
 */
inline void operator delete[]( void * p_arg )
{
	vPortFree( p_arg );
}


#ifdef _HAVE_STD_CXX

inline void * operator new( size_t size, std::nothrow_t ) noexcept
{
	return operator new( size );
}

inline void operator delete( void *p,  std::nothrow_t ) noexcept
{
	operator delete( p );
}

inline void* operator new[]( size_t size, std::nothrow_t ) noexcept
{
	return operator new( size );
}

inline void operator delete[]( void *p,  std::nothrow_t ) noexcept
{
	operator delete( p );
}

#endif	/* _HAVE_STD_CXX */

#endif	/* __cplusplus */


#endif /* DRI_MEM_H_ */

/********************************** End of File *******************************/
