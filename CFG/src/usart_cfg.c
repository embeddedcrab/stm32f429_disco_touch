/******************************************************************************
* Copyright (c) 2019 - Hemant Sharma - All Rights Reserved
*
* Feel free to use this Code at your own risk for your own purposes.
*
*******************************************************************************/
/******************************************************************************
* Title:		USART Configuration Source
* Filename:		usart_cfg.c
* Author:		HS
* Origin Date:	26-May-2020
* Version:
* Notes:
*
* Change History
* --------------
*
*******************************************************************************/

/** @file:	usart_cfg.c
 *  @brief:
 */

/******************************************************************************
* Includes
*******************************************************************************/
#include "stm32f4xx.h"

/* Include Peripheral Configuration file */
#include "usart_cfg.h"

#include <cmsis_os.h>
#include <semphr.h>


/******************************************************************************
* Variables
*******************************************************************************/

extern SemaphoreHandle_t xlog_event_sem;


/* DMA channel for UART 4 */
DMA_HandleTypeDef UART4_DMA_Tx_Handle =
{
	.Instance = DMA1_Stream4,
	.Init = {
		DMA_CHANNEL_4, DMA_MEMORY_TO_PERIPH, DMA_PINC_DISABLE, DMA_MINC_ENABLE,
		DMA_PDATAALIGN_BYTE, DMA_MDATAALIGN_BYTE/*DMA_MDATAALIGN_WORD*/, DMA_NORMAL, DMA_PRIORITY_VERY_HIGH,
		DMA_FIFOMODE_DISABLE, DMA_FIFO_THRESHOLD_FULL, DMA_MBURST_INC16, DMA_PBURST_INC16
	}
};

/* UAART Channel 4 Configurations */
UART_HandleTypeDef UART4_Handle =
{
	.Instance = UART4,
	.Init = {
		115200, UART_WORDLENGTH_8B, UART_STOPBITS_1, UART_PARITY_NONE,
		UART_MODE_TX_RX, UART_HWCONTROL_NONE, UART_OVERSAMPLING_16
	},
	.hdmatx = &UART4_DMA_Tx_Handle,
	.hdmarx = NULL
};


/******************************************************************************/
/*            	  	    UART Interrupt Routines		                          */
/******************************************************************************/


/**
  * @brief  UART MSP Init, Overridden function
  * @param  huart  Pointer to a UART_HandleTypeDef structure that contains
  *                the configuration information for the specified UART module.
  * @retval None
  */
void UART4_HAL_init( void )
{
	/* Local Variables */
	GPIO_InitTypeDef UART4_Pins =
	{
		.Pin = GPIO_PIN_0,
		.Mode = GPIO_MODE_AF_PP,
		.Pull = GPIO_PULLUP,
		.Speed = GPIO_SPEED_FREQ_LOW,
		.Alternate = GPIO_AF8_UART4
	};

	/* Enable UART Channel 4 Clock */
	__HAL_RCC_UART4_CLK_ENABLE();
	__HAL_RCC_DMA1_CLK_ENABLE();
	/* Enable GPIOs clock */
	__HAL_RCC_GPIOA_CLK_ENABLE();

	/* Initialize GPIO pins for UART Channel 4 */
	HAL_GPIO_Init( GPIOA, &UART4_Pins );
	UART4_Pins.Pin = GPIO_PIN_1;
	HAL_GPIO_Init( GPIOA, &UART4_Pins );

	/* Initialize DMA and Link it with UART channel */
	HAL_DMA_Init( &UART4_DMA_Tx_Handle );
	UART4_DMA_Tx_Handle.Parent = (void *)&UART4_Handle;

	/* STM HAL layer function */
	HAL_UART_Init( &UART4_Handle );

    /* Enable the UART Parity Error Interrupt */
//    __HAL_UART_ENABLE_IT( &UART4_Handle, UART_IT_PE );
    /* Enable the UART Error Interrupt: (Frame error, noise error, overrun error) */
    __HAL_UART_ENABLE_IT( &UART4_Handle, UART_IT_ERR );
	/* Enable the UART Data Register not empty Interrupt */
	__HAL_UART_ENABLE_IT( &UART4_Handle, UART_IT_RXNE );

	/* NVIC configuration for DMA transfer complete interrupt (USARTx_TX) */
	HAL_NVIC_SetPriority( DMA1_Stream4_IRQn, 5, 1 );
	HAL_NVIC_EnableIRQ( DMA1_Stream4_IRQn );

	/* NVIC configuration for UART Interrupts */
	HAL_NVIC_SetPriority( UART4_IRQn, 5, 0 );
	HAL_NVIC_EnableIRQ( UART4_IRQn );
}


/**
  * @brief  UART4_IRQHandler
  * @param  NA
  *
  * @retval None
  */
void UART4_IRQHandler( void )
{
	/* Local variables */
//	BaseType_t xHigherPriorityTaskWoken = pdFALSE;

	/* Call Handler */
	HAL_UART_IRQHandler( &UART4_Handle );

	/* Trigger semaphore indicating that log data has been transmitted FromISR */
	if( xSemaphoreGiveFromISR( xlog_event_sem, NULL/* &xHigherPriorityTaskWoken */ ) != pdPASS )
	{
		__asm("NOP"); /* For Debug */
	}

	/* Direct Receive from ISR */
	if( ( ((UART4_Handle.Instance->SR) & USART_SR_RXNE) != RESET ) &&
		( ((UART4_Handle.Instance->CR1) & USART_CR1_RXNEIE) != RESET )
		)
	{
		/* Read some received character if available */
		if( UART4_Handle.RxState != HAL_UART_STATE_BUSY_RX)
		{
			__HAL_UART_DISABLE_IT( &UART4_Handle, UART_IT_RXNE );

			if( UART4_Handle.Init.Parity == UART_PARITY_NONE )
			{
			}
			else
			{
			}

			/* Enable Receiver interrupt */
			__HAL_UART_ENABLE_IT( &UART4_Handle, UART_IT_RXNE );
		}
	}
}


/**
  * @brief  UART4 DMA Stream Handler
  * @param  NA
  *
  * @retval None
  */
void DMA1_Stream4_IRQHandler( void )
{
	HAL_DMA_IRQHandler( UART4_Handle.hdmatx );
}

