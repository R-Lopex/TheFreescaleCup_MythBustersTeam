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
/* DESCRIPTION :  Definition of functions to use the GPIO pins                */
/*============================================================================*/
/* FUNCTION COMMENT : Add here the user functions to use the GPIO pins        */
/* initialized (like buttons, LEDs, digital sensors, etc.)                    */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 03/Sep/2014 |                               | Lopex_           */
/* This file was created based on TFC_BoardSupport.c and contain the          */
/* definition of the GPIO pins and a function to check them.                  */
/*============================================================================*/



#include "app\app_GPIO.h"


//set I/O for H-BRIDGE enables, switches, buttons and LEDs
void app_InitGPIO()
{
	//enable Clocks to all ports

	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK |
                 SIM_SCGC5_PORTB_MASK |
                 SIM_SCGC5_PORTC_MASK |
                 SIM_SCGC5_PORTD_MASK |
                 SIM_SCGC5_PORTE_MASK;


	/**Setup Pins as GPIO **/

	/// Setup the input pins
	// Ports for Pushbuttons
	PORTC_PCR13 = PORT_PCR_MUX(1);
	PORTC_PCR17 = PORT_PCR_MUX(1);

	// Ports for DIP Switches
	PORTE_PCR2  = PORT_PCR_MUX(1);
	PORTE_PCR3  = PORT_PCR_MUX(1);
	PORTE_PCR4  = PORT_PCR_MUX(1);
	PORTE_PCR5  = PORT_PCR_MUX(1);

	/// Setup the output pins
	// Ports for Enable H Bridge
	PORTE_PCR21 = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;
	PORTE_PCR20 = PORT_PCR_MUX(1);

	// Ports for LEDs
	PORTB_PCR8  = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;
	PORTB_PCR9  = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;
	PORTB_PCR10 = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;
	PORTB_PCR11 = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;

	//Ports for RGB LED
    PORTB_PCR18 = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK; //R
    PORTB_PCR19 = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK; //G
    PORTD_PCR1  = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK; //B


	/** Setup the output of the output pins **/

    GPIOB_PDDR =  app_BAT_LED0_LOC	        |
                  app_BAT_LED1_LOC          |
                  app_BAT_LED2_LOC          |
                  app_BAT_LED3_LOC          |
                  app_RGB_LED_GREEN_LOC     |
                  app_RGB_LED_RED_LOC;
    GPIOD_PDDR =  app_RGB_LED_BLUE_LOC;
    GPIOE_PDDR =  app_HBRIDGE_EN_LOC;

    app_HBRIDGE_DISABLE;
    app_BAT_LED0_OFF;
    app_BAT_LED1_OFF;
    app_BAT_LED2_OFF;
    app_BAT_LED3_OFF;
    app_RGB_LED_BLUE_OFF;
    app_RGB_LED_GREEN_OFF;
    app_RGB_LED_RED_OFF;

}


/// My functions

void app_Check_GPIO(void)
{
    
    if (app_DIP_SWITCH0_PRESSED)
        app_BAT_LED0_ON;
    else
        app_BAT_LED0_OFF;

    if (app_DIP_SWITCH1_PRESSED)
        app_BAT_LED1_ON;
    else
        app_BAT_LED1_OFF;

    if (app_DIP_SWITCH2_PRESSED)
        app_BAT_LED2_ON;
    else
        app_BAT_LED2_OFF;

    if (app_DIP_SWITCH3_PRESSED)
        app_BAT_LED3_ON;
    else
        app_BAT_LED3_OFF;


    if(app_PUSH_BUTTON_A_PRESSED)
    {
    	app_RGB_LED_RED_ON;
    	app_RGB_LED_GREEN_OFF;
    	app_RGB_LED_BLUE_OFF;
    }
    else if(app_PUSH_BUTTON_B_PRESSED)
    {
    	app_RGB_LED_RED_OFF;
		app_RGB_LED_GREEN_ON;
		app_RGB_LED_BLUE_OFF;
    }
    else
    {
    	app_RGB_LED_RED_OFF;
		app_RGB_LED_GREEN_OFF;
		app_RGB_LED_BLUE_ON;
    }
        
}



/// Default functions

void app_SetBatteryLED_Level(uint8_t BattLevel)
{
	switch(BattLevel)
	{
		default:
		case 0:
			GPIOB_PCOR = 0xF<<8;
		break;

		case 1:
			GPIOB_PSOR = 0x01<<8;
			GPIOB_PCOR = ~(0x01<<8) & (0xF<<8);
		break;

		case 2:
			GPIOB_PSOR = 0x03<<8;
			GPIOB_PCOR = ~(0x03<<8) & (0xF<<8) ;
		break;

		case 3:
			GPIOB_PSOR = 0x07<<8;
			GPIOB_PCOR = ~(0x07<<8) & (0xF<<8);
		break;

		case 4:
			GPIOB_PSOR = 0x0F<<8;
		break;

	}
}


uint8_t app_GetDIP_Switch()
{
	uint8_t DIP_Val=0;

	DIP_Val = (GPIOE_PDIR>>2) & 0xF;

	return DIP_Val;
}
