/*
 * app_TFC.h
 *
 *  Created on: Sep 7, 2014
 *      Author: Lopex_
 */


#ifndef APP_TFC_H_
#define APP_TFC_H_


#define CORE_CLOCK				 (48000000)
#define FTM1_CLOCK               (CORE_CLOCK)
#define PERIPHERAL_BUS_CLOCK     (CORE_CLOCK/2)

#include <stdint.h>
#include "derivative.h"
#include "driver\driver_arm_cm0.h"
#include "driver\driver_ADC.h"
#include "app\app_GPIO.h"
#include "app\app_LineScanCamera.h"
#include "app\app_Servos.h"
#include "app\app_ADC.h"




void app_InitAll();

#endif
