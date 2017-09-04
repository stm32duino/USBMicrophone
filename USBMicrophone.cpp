/**
******************************************************************************
* @file    USBMicrophone.cpp
* @author  WI6LABS
* @version V0.0.1
* @date    27-July-2017
* @brief   This file provides the USB Audio class for Microphone.
*******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT(c) 2017 STMicroelectronics</center></h2>
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *   3. Neither the name of STMicroelectronics nor the names of its contributors
 *      may be used to endorse or promote products derived from this software
 *      without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************
 */


#ifdef USBCON
#include "usbd_audio_if.h"
#include "usbd_audio_in.h"
#include "usbd_desc_microphone.h"
#include "USBMicrophone.h"

USBMicrophone::USBMicrophone(void)
{

}

void USBMicrophone::begin(uint32_t frequency, uint8_t channels)
{
  /* Initialize USB descriptor basing on channels number and sampling frequency */
  USBD_AUDIO_Init_Microphone_Descriptor(&hUSBD_Device, frequency, channels);

  /* Init Device Library */
  USBD_Init(&hUSBD_Device, &AUDIO_Desc, 0);

  /* Add Supported Class */
  USBD_RegisterClass(&hUSBD_Device, &USBD_AUDIO);

  /* Add Interface callbacks for AUDIO Class */
  USBD_AUDIO_RegisterInterface(&hUSBD_Device, &USBD_AUDIO_fops);

  /* Start Device Process */
  USBD_Start(&hUSBD_Device);
}

void USBMicrophone::end(void)
{
  /* Start Device Process */
  USBD_Stop(&hUSBD_Device);
}

void USBMicrophone::send(int16_t *PCMData, uint16_t PCMSamples)
{
  Send_Audio_to_USB(&hUSBD_Device, PCMData, PCMSamples);
}

USBMicrophone USBMicro;

#endif //USBCON
