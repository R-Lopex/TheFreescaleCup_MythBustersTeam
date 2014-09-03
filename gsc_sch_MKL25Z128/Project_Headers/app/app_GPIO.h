/*============================================================================*/
/*                         MYTHBUSTERS_TEAM_1                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/* C Source:        app_GPIO.cpp                                              */
/* version:         1.0                                                       */
/* created_by:      Lopex_                                                    */
/* date_created:    September 03 2014                                         */
/*============================================================================*/
/* DESCRIPTION :  This file contains the GPIO prototype functions to          */
/* initialize the GPIO pins and the user functions to use them                */
/*============================================================================*/
/* FUNCTION COMMENT : Main header for app_GPIO module                         */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 03/Sep/2014 |                               | Lopex_           */
/* This file is created based on TFC_BoardSupport.h for the                   */
/* app_GPIO.cpp file                                                          */
/*============================================================================*/


#include <stdint.h>
#include "derivative.h"

#ifndef APP_GPIO_H_
#define APP_GPIO_H_


/// Output Definitions
// H Bridge
#define app_HBRIDGE_EN_LOC			(uint32_t)(1<<21)
#define app_HBRIDGE_FAULT_LOC     	(uint32_t)(1<<20)

#define app_HBRIDGE_ENABLE			GPIOE_PSOR = app_HBRIDGE_EN_LOC
#define app_HBRIDGE_DISABLE			GPIOE_PCOR = app_HBRIDGE_EN_LOC

// LEDs
#define app_BAT_LED0_LOC			((uint32_t)(1<<8))
#define app_BAT_LED1_LOC			((uint32_t)(1<<9))
#define app_BAT_LED2_LOC			((uint32_t)(1<<10))
#define app_BAT_LED3_LOC			((uint32_t)(1<<11))

#define app_BAT_LED0_ON				GPIOB_PSOR = app_BAT_LED0_LOC
#define app_BAT_LED1_ON				GPIOB_PSOR = app_BAT_LED1_LOC
#define app_BAT_LED2_ON				GPIOB_PSOR = app_BAT_LED2_LOC
#define app_BAT_LED3_ON				GPIOB_PSOR = app_BAT_LED3_LOC

#define app_BAT_LED0_OFF			GPIOB_PCOR = app_BAT_LED0_LOC
#define app_BAT_LED1_OFF			GPIOB_PCOR = app_BAT_LED1_LOC
#define app_BAT_LED2_OFF			GPIOB_PCOR = app_BAT_LED2_LOC
#define app_BAT_LED3_OFF			GPIOB_PCOR = app_BAT_LED3_LOC

#define app_BAT_LED0_TOGGLE			GPIOB_PTOR = app_BAT_LED0_LOC
#define app_BAT_LED1_TOGGLE			GPIOB_PTOR = app_BAT_LED1_LOC
#define app_BAT_LED2_TOGGLE			GPIOB_PTOR = app_BAT_LED2_LOC
#define app_BAT_LED3_TOGGLE			GPIOB_PTOR = app_BAT_LED3_LOC

// RGB LED
#define app_RGB_LED_RED_LOC			((uint32_t)(1<<18))
#define app_RGB_LED_GREEN_LOC		((uint32_t)(1<<19))
#define app_RGB_LED_BLUE_LOC		((uint32_t)(1<<1))

#define app_RGB_LED_RED_ON			GPIOB_PCOR = app_RGB_LED_RED_LOC
#define app_RGB_LED_GREEN_ON		GPIOB_PCOR = app_RGB_LED_GREEN_LOC
#define app_RGB_LED_BLUE_ON			GPIOD_PCOR = app_RGB_LED_BLUE_LOC

#define app_RGB_LED_RED_OFF			GPIOB_PSOR = app_RGB_LED_RED_LOC
#define app_RGB_LED_GREEN_OFF		GPIOB_PSOR = app_RGB_LED_GREEN_LOC
#define app_RGB_LED_BLUE_OFF		GPIOD_PSOR = app_RGB_LED_BLUE_LOC

#define app_RGB_LED_RED_TOGGLE		GPIOB_PTOR = app_RGB_LED_RED_LOC
#define app_RGB_LED_GREEN_TOGGLE	GPIOB_PTOR = app_RGB_LED_GREEN_LOC
#define app_RGB_LED_BLUE_TOGGLE		GPIOD_PTOR = app_RGB_LED_BLUE_LOC

/// Input Definitions
// Dip Switch
#define app_DIP_SWITCH0_LOC			((uint32_t)(1<<2))
#define app_DIP_SWITCH1_LOC			((uint32_t)(1<<3))
#define app_DIP_SWITCH2_LOC			((uint32_t)(1<<4))
#define app_DIP_SWITCH3_LOC			((uint32_t)(1<<5))

#define app_DIP_SWITCH0_PRESSED     ((GPIOE_PDIR & app_DIP_SWITCH0_LOC)>0)
#define app_DIP_SWITCH1_PRESSED     ((GPIOE_PDIR & app_DIP_SWITCH1_LOC)>0)
#define app_DIP_SWITCH2_PRESSED     ((GPIOE_PDIR & app_DIP_SWITCH2_LOC)>0)
#define app_DIP_SWITCH3_PRESSED     ((GPIOE_PDIR & app_DIP_SWITCH3_LOC)>0)

// Push buttons
#define app_PUSH_BUTTON_A_LOC		((uint32_t)(1<<13))
#define app_PUSH_BUTTON_B_LOC		((uint32_t)(1<<17))

#define app_PUSH_BUTTON_A_PRESSED	((GPIOC_PDIR & app_PUSH_BUTTON_A_LOC)>0)
#define app_PUSH_BUTTON_B_PRESSED	((GPIOC_PDIR & app_PUSH_BUTTON_B_LOC)>0)


void    app_InitGPIO(void);
void    app_Check_GPIO(void);
void    app_SetBatteryLED_Level(uint8_t BattLevel);
uint8_t app_GetDIP_Switch(void);


#endif /* APP_GPIO_H_ */
