/*
 * driver_ADC.h
 *
 *  Created on: Sep 7, 2014
 *      Author: Lopex_
 */

#ifndef DRIVER_ADC_H_
#define DRIVER_ADC_H_


#define app_DEFAULT_LINESCAN_EXPOSURE_TIME_uS	50000


typedef struct adc_cfg {
  uint8_t  CONFIG1; 
  uint8_t  CONFIG2; 
  uint16_t COMPARE1; 
  uint16_t COMPARE2; 
  uint8_t  STATUS2;
  uint8_t  STATUS3; 
  uint8_t  STATUS1A; 
  uint8_t  STATUS1B;
  uint32_t PGA;
  } *tADC_ConfigPtr, tADC_Config ;  
  

#define CAL_BLK_NUMREC 18 

typedef struct adc_cal {
 
uint16_t  OFS;
uint16_t  PG;
uint16_t  MG;
uint8_t   CLPD;
uint8_t   CLPS;
uint16_t  CLP4;
uint16_t  CLP3;
uint8_t   CLP2;
uint8_t   CLP1;
uint8_t   CLP0;
uint8_t   dummy;
uint8_t   CLMD;
uint8_t   CLMS;
uint16_t  CLM4;
uint16_t  CLM3;
uint8_t   CLM2;
uint8_t   CLM1;
uint8_t   CLM0;
} tADC_Cal_Blk ; 

// function prototypes:

uint8_t ADC_Cal(ADC_MemMapPtr);

void ADC_Config_Alt(ADC_MemMapPtr, tADC_ConfigPtr);

void ADC_Read_Cal(ADC_MemMapPtr, tADC_Cal_Blk *);

#define ADC_STATE_INIT							0
#define ADC_STATE_CAPTURE_POT_0			        1
#define ADC_STATE_CAPTURE_POT_1			        2
#define ADC_STATE_CAPTURE_BATTERY_LEVEL			3
#define ADC_STATE_CAPTURE_LINE_SCAN		        4




/*
extern volatile uint16_t PotADC_Value[2];
extern volatile uint16_t BatSenseADC_Value;
extern static uint8_t 	CurrentADC_State =	ADC_STATE_INIT;	

extern volatile uint8_t CurrentLineScanPixel = 0;
extern volatile uint8_t CurrentLineScanChannel = 0;
*/

void InitADC0();




#endif /* DRIVER_ADC_H_ */
