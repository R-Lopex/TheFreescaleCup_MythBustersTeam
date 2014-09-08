/*
 * app_ADC.c
 *
 *  Created on: Sep 7, 2014
 *      Author: Lopex_
 */


#include "app\app_TFC.h"


volatile uint16_t PotADC_Value[2];
volatile uint16_t BatSenseADC_Value;
static   uint8_t  CurrentADC_State=ADC_STATE_INIT;	
volatile uint8_t  CurrentLineScanPixel=0;
volatile uint8_t  CurrentLineScanChannel=0;


#define app_POT_0_ADC_CHANNEL		13
#define app_POT_1_ADC_CHANNEL		12
#define app_BAT_SENSE_CHANNEL		4
#define app_LINESCAN0_ADC_CHANNEL	6
#define app_LINESCAN1_ADC_CHANNEL	7

#define ADC_MAX_CODE    (4095)

#define ADC0_irq_no   57
#define ADC1_irq_no   58

#define ADC0_CHANA    19                                    // set to desired ADC0 channel trigger A    
#define ADC0_CHANB    20                                    // set to desired ADC0 channel trigger B    

#define ADC1_CHANA    20                                    // set to desired ADC1 channel trigger A  20 defaults to potentiometer in TWRK60     
#define ADC1_CHANB    20                                    // set to desired ADC1 channel trigger B

#define ADC0_DLYA     0x2000                                // ADC0 trigger A delay 
#define ADC0_DLYB     0x4000                                // ADC0 trigger B delay 
#define ADC1_DLYA     0x6000                                // ADC1 trigger A delay
#define ADC1_DLYB     0x7fff                                // ADC1 trigger B delay 


#define ADC0A_DONE   0x01       
#define ADC0B_DONE   0x02       
#define ADC1A_DONE   0x04       
#define ADC1B_DONE   0x08       



void PIT_IRQHandler()
{
	PIT_TFLG0 = PIT_TFLG_TIF_MASK; //Turn off the Pit 0 Irq flag 
	
	TAOS_SI_HIGH;
	//Prime the ADC pump and start capturing POT 0
	CurrentADC_State = ADC_STATE_CAPTURE_POT_0;
	
	ADC0_CFG2  &= ~ADC_CFG2_MUXSEL_MASK; //Select the A side of the mux
	ADC0_SC1A  =  app_POT_0_ADC_CHANNEL | ADC_SC1_AIEN_MASK;  //Start the State machine at POT0
}



void ADC0_IRQHandler()
{
	uint8_t Junk;
	switch(CurrentADC_State)
	{
		default:
			Junk =  ADC0_RA;
		break;
		
		case ADC_STATE_CAPTURE_POT_0:
				
				PotADC_Value[0] = ADC0_RA;
				ADC0_CFG2  &= ~ADC_CFG2_MUXSEL_MASK; //Select the A side of the mux
				ADC0_SC1A  =  app_POT_1_ADC_CHANNEL | ADC_SC1_AIEN_MASK;
				CurrentADC_State = ADC_STATE_CAPTURE_POT_1;
				
			break;
		
		case ADC_STATE_CAPTURE_POT_1:
		
				PotADC_Value[1] = ADC0_RA;
				ADC0_CFG2  |= ADC_CFG2_MUXSEL_MASK; //Select the B side of the mux
				//ADC0_SC1A  =  app_BAT_SENSE_CHANNEL| ADC_SC1_AIEN_MASK;
				ADC0_SC1A  =  app_POT_1_ADC_CHANNEL| ADC_SC1_AIEN_MASK;
				//CurrentADC_State = ADC_STATE_CAPTURE_BATTERY_LEVEL;
				CurrentADC_State = ADC_STATE_CAPTURE_POT_1;
				
			break;
		
		case ADC_STATE_CAPTURE_BATTERY_LEVEL:
			
				BatSenseADC_Value = ADC0_RA;
				
				//Now we will start the sequence for the Linescan camera
				
				TAOS_CLK_HIGH;
				
				for(Junk = 0;Junk<50;Junk++)
				{
				}
				
				TAOS_SI_LOW;

				
				CurrentLineScanPixel = 0;
				CurrentLineScanChannel = 0;
				CurrentADC_State = ADC_STATE_CAPTURE_LINE_SCAN;
				ADC0_CFG2  |= ADC_CFG2_MUXSEL_MASK; //Select the B side of the mux
				ADC0_SC1A  =  app_LINESCAN0_ADC_CHANNEL | ADC_SC1_AIEN_MASK;
				
				break;
		
		case ADC_STATE_CAPTURE_LINE_SCAN:
					
					if(CurrentLineScanPixel<128)
					{
						if(CurrentLineScanChannel == 0)
						{
							LineScanImage0WorkingBuffer[CurrentLineScanPixel] = ADC0_RA;
							ADC0_SC1A  =  app_LINESCAN1_ADC_CHANNEL | ADC_SC1_AIEN_MASK;
							CurrentLineScanChannel = 1;
							
						}
						else
						{
							LineScanImage1WorkingBuffer[CurrentLineScanPixel] = ADC0_RA;
							ADC0_SC1A  =  app_LINESCAN0_ADC_CHANNEL | ADC_SC1_AIEN_MASK;
							CurrentLineScanChannel = 0;
							CurrentLineScanPixel++;
							
							TAOS_CLK_LOW;
								for(Junk = 0;Junk<50;Junk++)
									{
									}
							TAOS_CLK_HIGH;
							
						}
						
					}
					else
					{
						// done with the capture sequence.  we can wait for the PIT0 IRQ to restart
					
						TAOS_CLK_HIGH;
											
						for(Junk = 0;Junk<50;Junk++)
							{
							}
						
						TAOS_CLK_LOW;
						CurrentADC_State = ADC_STATE_INIT;	 
						
						//swap the buffer
						
						if(LineScanWorkingBuffer == 0)
						{
							LineScanWorkingBuffer = 1;
							
							LineScanImage0WorkingBuffer = &LineScanImage0Buffer[1][0];
							LineScanImage1WorkingBuffer = &LineScanImage1Buffer[1][0];
							
							LineScanImage0 = &LineScanImage0Buffer[0][0];
							LineScanImage1 = &LineScanImage1Buffer[0][0];
						}
						else
						{
							LineScanWorkingBuffer = 0;
							LineScanImage0WorkingBuffer = &LineScanImage0Buffer[0][0];
							LineScanImage1WorkingBuffer = &LineScanImage1Buffer[0][0];
							
							LineScanImage0 = &LineScanImage0Buffer[1][0];
							LineScanImage1 = &LineScanImage1Buffer[1][0];
						}
						
						LineScanImageReady = TRUE;
					}
					
					break;
	
	}

}

//Pot Reading is Scaled to return a value of -1.0 to 1.0
float app_ReadPot(uint8_t Channel)
{
    if(Channel == 0)
        return ((float)PotADC_Value[0]/-((float)ADC_MAX_CODE/2.0))+1.0;
    else
        return ((float)PotADC_Value[1]/-((float)ADC_MAX_CODE/2.0))+1.0;
}

float app_ReadBatteryVoltage()
{
    return (((float)BatSenseADC_Value/(float)(ADC_MAX_CODE)) * 3.0);// * ((47000.0+10000.0)/10000.0);
}


void app_InitADCs()
{

	 InitADC0();

	
	//All Adc processing of the Pots and linescan will be done in the ADC0 IRQ!
	//A state machine will scan through the channels.
	//This is done to automate the linescan capture on Channel 0 to ensure that timing is very even
	CurrentADC_State =	ADC_STATE_INIT;	

    //The pump will be primed with the PIT interrupt.  upon timeout/interrupt it will set the SI signal high
	//for the camera and then start the conversions for the pots.
	
	//Enable clock to the PIT
	SIM_SCGC6 |= SIM_SCGC6_PIT_MASK;
	
	//We will use PIT0
	app_SetLineScanExposureTime(app_DEFAULT_LINESCAN_EXPOSURE_TIME_uS);
	//enable PIT0 and its interrupt
	PIT_TCTRL0 = PIT_TCTRL_TEN_MASK | PIT_TCTRL_TIE_MASK;

	PIT_MCR |= PIT_MCR_FRZ_MASK; // stop the pit when in debug mode
	//Enable the PIT module
	PIT_MCR &= ~PIT_MCR_MDIS_MASK;
	
	enable_irq(INT_PIT-16);
	enable_irq(INT_ADC0-16);
	
}

void app_ServoAndPot()
{
	app_SetServo(1,app_ReadPot(1));
}


