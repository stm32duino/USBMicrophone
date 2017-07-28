/**
  ******************************************************************************
  * @file    usbd_desc_microphone.c
  * @author  Wi6Labs
  * @version V1.0.0
  * @date    27-July-2017
  * @brief   This file provides the USBD descriptors and string formating method.
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
#ifdef USBCON
/* Includes ------------------------------------------------------------------*/
#include "usbd_core.h"
#include "usbd_desc.h"
#include "usbd_desc_microphone.h"
#include "usbd_conf.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define USBD_AUDIO_PRODUCT_FS_STRING        "STM32 AUDIO Streaming in FS Mode"
#define USBD_AUDIO_SERIALNUMBER_FS_STRING   "00000000034F"
#define USBD_AUDIO_CONFIGURATION_FS_STRING  "AUDIO Config"
#define USBD_AUDIO_INTERFACE_FS_STRING      "AUDIO Interface"
/* Private macro -------------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/
static uint8_t *USBD_AUDIO_ProductStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length);
static uint8_t *USBD_AUDIO_ConfigStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length);
static uint8_t *USBD_AUDIO_InterfaceStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length);
#ifdef USB_SUPPORT_USER_STRING_DESC
static uint8_t *USBD_AUDIO_USRStringDesc(USBD_SpeedTypeDef speed, uint8_t idx, uint16_t *length);
#endif /* USB_SUPPORT_USER_STRING_DESC */

/* Private variables ---------------------------------------------------------*/
USBD_DescriptorsTypeDef AUDIO_Desc = {
  USBD_DeviceDescriptor,
  USBD_LangIDStrDescriptor,
  USBD_ManufacturerStrDescriptor,
  USBD_AUDIO_ProductStrDescriptor,
  USBD_SerialStrDescriptor,
  USBD_AUDIO_ConfigStrDescriptor,
  USBD_AUDIO_InterfaceStrDescriptor,
};

#if defined ( __ICCARM__ ) /*!< IAR Compiler */
  #pragma data_alignment=4
#endif
__ALIGN_BEGIN static uint8_t USBD_StrDesc[USBD_MAX_STR_DESC_SIZ] __ALIGN_END;

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Returns the product string descriptor.
  * @param  speed: Current device speed
  * @param  length: Pointer to data length variable
  * @retval Pointer to descriptor buffer
  */
uint8_t *USBD_AUDIO_ProductStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length)
{
  UNUSED(speed);
  USBD_GetString((uint8_t *)USBD_AUDIO_PRODUCT_FS_STRING, USBD_StrDesc, length);
  return USBD_StrDesc;
}

/**
  * @brief  Returns the configuration string descriptor.
  * @param  speed: Current device speed
  * @param  length: Pointer to data length variable
  * @retval Pointer to descriptor buffer
  */
uint8_t *USBD_AUDIO_ConfigStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length)
{
  UNUSED(speed);
  USBD_GetString((uint8_t *)USBD_AUDIO_CONFIGURATION_FS_STRING, USBD_StrDesc, length);
  return USBD_StrDesc;
}

/**
  * @brief  Returns the interface string descriptor.
  * @param  speed: Current device speed
  * @param  length: Pointer to data length variable
  * @retval Pointer to descriptor buffer
  */
uint8_t *USBD_AUDIO_InterfaceStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length)
{
  UNUSED(speed);
  USBD_GetString((uint8_t *)USBD_AUDIO_INTERFACE_FS_STRING, USBD_StrDesc, length);
  return USBD_StrDesc;
}

#endif // USBCON
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
