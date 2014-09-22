/*
 * app_TFC.c
 *
 *  Created on: Sep 7, 2014
 *      Author: Lopex_
 */

#include "app\app_TFC.h"

void app_InitAll()
{
	app_InitGPIO();
	app_InitServos();
	app_InitLineScanCamera();
	app_InitADCs();
}
