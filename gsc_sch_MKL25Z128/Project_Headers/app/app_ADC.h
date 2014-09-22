/*
 * app_ADC.h
 *
 *  Created on: Sep 7, 2014
 *      Author: Lopex_
 */

#ifndef APP_ADC_H_
#define APP_ADC_H_


void ADC0_IRQ();
void app_InitADCs();
float app_ReadPot(uint8_t Channel);
float app_ReadBatteryVoltage();
void app_ServoAndPot();
void app_StartADCConvertion();
void app_ADCCheck();


#endif /* APP_ADC_H_ */
