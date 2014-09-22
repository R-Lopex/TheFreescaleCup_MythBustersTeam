/*
 * app_LineScanCamera.h
 *
 *  Created on: Sep 7, 2014
 *      Author: Lopex_
 */




#ifndef APP_LINESCANCAMERA_H_
#define APP_LINESCANCAMERA_H_


void app_InitLineScanCamera();

void app_SetLineScanExposureTime(uint32_t  TimeIn_uS);


#define TAOS_CLK_HIGH  GPIOE_PSOR = (1<<1)  
#define TAOS_CLK_LOW   GPIOE_PCOR = (1<<1)  
#define TAOS_SI_HIGH   GPIOD_PSOR = (1<<7)
#define TAOS_SI_LOW    GPIOD_PCOR =	(1<<7)

extern volatile uint16_t  *LineScanImage0WorkingBuffer;
extern volatile uint16_t  *LineScanImage1WorkingBuffer;
extern volatile uint16_t  *LineScanImage0;
extern volatile uint16_t  *LineScanImage1;
extern volatile uint16_t  LineScanImage0Buffer[2][128];
extern volatile uint16_t  LineScanImage1Buffer[2][128];
extern volatile uint8_t   LineScanWorkingBuffer;
extern volatile uint8_t   LineScanImageReady;

#endif /* APP_LINESCANCAMERA_H_ */

