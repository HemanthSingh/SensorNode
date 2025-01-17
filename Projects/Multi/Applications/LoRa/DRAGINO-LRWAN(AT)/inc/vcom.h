/*
 / _____)             _              | |
( (____  _____ ____ _| |_ _____  ____| |__
 \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 _____) ) ____| | | || |_| ____( (___| | | |
(______/|_____)_|_|_| \__)_____)\____)_| |_|
    (C)2013 Semtech

Description: virtual com port driver

License: Revised BSD License, see LICENSE.TXT file include in the project

Maintainer: Miguel Luis and Gregory Cristian
*/
 /******************************************************************************
  * @file    vcom.h
  * @author  MCD Application Team
  * @version V1.1.2
  * @date    08-September-2017
  * @brief   Header for vcom.c module
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics International N.V. 
  * All rights reserved.</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __VCOM_H__
#define __VCOM_H__

#ifdef __cplusplus
 extern "C" {
#endif
   
/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* External variables --------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */ 

/** 
* @brief  Init the VCOM.
* @param  None
* @return None
*/
void vcom_Init(void);

   /** 
* @brief  DeInit the VCOM.
* @param  None
* @return None
*/
void vcom_DeInit(void);

   /** 
* @brief  Init the VCOM IOs.
* @param  None
* @return None
*/
void vcom_IoInit(void);
  
   /** 
* @brief  DeInit the VCOM IOs.
* @param  None
* @return None
*/
void vcom_IoDeInit(void);
void vcom_Send_f(const char *format, ...);  
/** 
* @brief  Records string on circular Buffer and set SW interrupt
* @note   Set NVIC to call vcom_Send
* @param  string
* @return None
*/
void vcom_Send(const char *format, ...);

/** 
* @brief  Sends circular Buffer on com port in IT mode
* @note   called from low Priority interrupt
* @param  None
* @return None
*/
void vcom_Print( void);

/** 
* @brief  Records string on circular Buffer
* @note   To be called only from critical section from low power section
*         Other wise use vcom_Send
* @param  string
* @return None
*/
void vcom_Send_Lp( char *format, ... );

/**
 * @brief  Checks if a new character has been received on com port
 * @param  None
 * @retval Returns SET if new character has been received on com port, RESET otherwise
 */
FlagStatus IsNewCharReceived(void);

/**
 * @brief  Gets new received characters on com port
 * @param  None
 * @retval Returns the character
 */
uint8_t GetNewChar(void);

/**
 * @brief  Takes one character that has been received and save it in uart_context.buffRx
 * @param  received character
 */
static void receive(char rx);

/**
 * @brief  Init the VCOM RX
 * @param  None
 * @retval None
 */
void vcom_ReceiveInit(void);

/**
 * @brief  vcom IRQ Handler
 * @param  None
 * @retval None
 */
void vcom_IRQHandler(UART_HandleTypeDef *huart);

/* Exported macros -----------------------------------------------------------*/
#if 1
#define PRINTF(...)            vcom_Send(__VA_ARGS__)
#define PRINTF_F(...)     vcom_Send_f(__VA_ARGS__)
#else
#define PRINTF(...)
#endif


#ifdef __cplusplus
}
#endif

#endif /* __VCOM_H__*/

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
