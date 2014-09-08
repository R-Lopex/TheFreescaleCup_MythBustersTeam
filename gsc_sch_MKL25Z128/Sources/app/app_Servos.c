/*============================================================================*/
/*                         MYTHBUSTERS_TEAM_1                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================//
// C Source:       app_Servos.c                                               //
// version:        1.0                                                        //
// created_by:     Lopex_                                                     //
// date_created:   September 05 2014                                          */
/*============================================================================*/
/* DESCRIPTION :   Definition of functions to use the servo motors            */
/*============================================================================*/
/* FUNCTION COMMENT : Add here the user functions to use the servomotors,     */
/* Here you can find the initialized of the PWM module and its configuration  */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 05/Sep/2014 |                               | Lopex_           */
/* This file was created based on TFC_Servos.c and contain the                */
/* definition of the Servomotors functions and the users function             */
/* to use the servos                                                          */
/*============================================================================*/


#include "app\app_TFC.h"




//Position is -1.0 to 1.0.   Use SERVO_X_MIN_DUTY_CYCLE and SERVO_MAX_DUTY_CYCLE  to calibrate the extremes
void app_SetServo(uint8_t ServoNumber, float Position)
{
   app_SetServoDutyCycle(ServoNumber ,
   (((Position + 1.0)/2)*(SERVO_MAX_DUTY_CYCLE - SERVO_MIN_DUTY_CYCLE))+SERVO_MIN_DUTY_CYCLE);
}


void app_SetServoDutyCycle(uint8_t ServoNumber, float DutyCycle)
{
    switch(ServoNumber)
    {
        default:
        case 0:
            TPM1_C0V = TPM1_MOD * DutyCycle;
            break;
        case 1:
            TPM1_C1V = TPM1_MOD * DutyCycle;
            break;
    }
}


/******************************************* Function to control Interrupt ************************************/
//volatile unsigned char ServoTickVar;


void FTM1_IRQHandler()
{
    //Clear the overflow mask if set.   According to the reference manual, we clear by writing a logic one!
    if(TPM1_SC & TPM_SC_TOF_MASK)
        TPM1_SC |= TPM_SC_TOF_MASK;

    //if servo tick less than 255 count up...
//    if (ServoTickVar < 0xff)
//        ServoTickVar++;

}


void app_InitServos()
{
    //Clock Setup for the TPM requires a couple steps.


    //1st,  set the clock mux
    //See Page 124 of f the KL25 Sub-Family Reference Manual, Rev. 3, September 2012
    SIM_SOPT2 |= SIM_SOPT2_PLLFLLSEL_MASK;// We Want MCGPLLCLK/2 (See Page 196 of the KL25 Sub-Family Reference Manual, Rev. 3, September 2012)
    SIM_SOPT2 &= ~(SIM_SOPT2_TPMSRC_MASK);
    SIM_SOPT2 |= SIM_SOPT2_TPMSRC(1); //We want the MCGPLLCLK/2 (See Page 196 of the KL25 Sub-Family Reference Manual, Rev. 3, September 2012)


    //Enable the Clock to the FTM0 Module
    //See Page 207 of f the KL25 Sub-Family Reference Manual, Rev. 3, September 2012
    SIM_SCGC6 |= SIM_SCGC6_TPM1_MASK;

    //The TPM Module has Clock.  Now set up the peripheral

    //Blow away the control registers to ensure that the counter is not running
    TPM1_SC = 0;
    TPM1_CONF = 0;

    //While the counter is disabled we can setup the prescaler

    TPM1_SC = TPM_SC_PS(FTM1_CLK_PRESCALE);
    TPM1_SC |= TPM_SC_TOIE_MASK; //Enable Interrupts for the Timer Overflow

    //Setup the mod register to get the correct PWM Period

    TPM1_MOD = FTM1_CLOCK/(1<<(FTM1_CLK_PRESCALE+1))/FTM1_OVERFLOW_FREQUENCY;

    //Setup Channels 0 and 1

    TPM1_C0SC = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSB_MASK;
    TPM1_C1SC = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSB_MASK;

    //Enable the Counter

    //Set the Default duty cycle to servo neutral
    app_SetServo(0, 0.0);
    app_SetServo(1, 0.0);

    //Enable the TPM COunter
    TPM1_SC |= TPM_SC_CMOD(1);

    //Enable TPM1 IRQ on the NVIC
    enable_irq (INT_TPM1-16);

    //Enable the FTM functions on the the port

    PORTB_PCR0 = PORT_PCR_MUX(3);
    PORTB_PCR1 = PORT_PCR_MUX(3);

}



void app_CheckServo(void)
{
	static float ServoValue=-0.9;
	if(ServoValue>0.8)
	{
		ServoValue=-0.8;
	}
	else
	{
		ServoValue+=0.1;
	}
	app_SetServo(1,ServoValue);
}


