/*
 * app_ADC.h
 *
 *  Created on: Sep 7, 2014
 *      Author: Lopex_
 */

#ifndef APP_ADC_H_
#define APP_ADC_H_



void PIT0_IRQ();
void ADC0_IRQ();
void app_InitADCs();
float app_ReadPot(uint8_t Channel);
float app_ReadBatteryVoltage();
void app_ServoAndPot();

#endif /* APP_ADC_H_ */
