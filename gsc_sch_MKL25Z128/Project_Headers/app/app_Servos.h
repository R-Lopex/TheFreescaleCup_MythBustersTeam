/*============================================================================*/
/*                         MYTHBUSTERS_TEAM_1                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================//
// C Source:      app_Servos.h                                                //
// version:       1.0                                                         //
// created_by:    Lopex_                                                      //
// date_created:  September 05 2014                                           */
/*============================================================================*/
/* DESCRIPTION :  This file contains the Servo's prototype functions          */
/* and the definitions to initialize the PWM module and use it                */
/*============================================================================*/
/* FUNCTION COMMENT : Main header for app_Servos module                       */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 05/Sep/2014 |                               | Lopex_           */
/* This file is created based on TFC_Servos.h for the app_Servos.c file       */
/*============================================================================*/




#ifndef APP_SERVOS_H_
#define APP_SERVOS_H_

#include "app\app_TFC.h"


#define CORE_CLOCK                     (48000000)
#define FTM1_CLOCK                     (CORE_CLOCK)
// Prescale Selector value - see comments in Status Control (SC) section for more details
#define FTM1_CLK_PRESCALE              6
// Desired Frequency of PWM Signal - Here 50Hz => 20ms period
#define FTM1_OVERFLOW_FREQUENCY        50
// use these to dial in servo steering to your particular servo
// The number here should be be *pulse width* in seconds to move servo to its left limit
#define SERVO_MIN_DUTY_CYCLE           (float)(.0010*FTM1_OVERFLOW_FREQUENCY)
// The number here should be be *pulse width* in seconds to move servo to its Right limit
#define SERVO_MAX_DUTY_CYCLE           (float)(.0020*FTM1_OVERFLOW_FREQUENCY)



void app_SetServo(uint8_t ServoNumber, float Position);
void app_SetServoDutyCycle(uint8_t ServoNumber, float DutyCycle);
void FTM1_IRQHandler();
void app_InitServos();
void app_CheckServo();


#endif /* APP_SERVOS_H_ */
