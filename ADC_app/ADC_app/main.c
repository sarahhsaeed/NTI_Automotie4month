/*
 * main.c
 *
 * Created: 10/24/2023 9:39:24 AM
 *  Author: Sarah saeed
 */ 

#include <xc.h>

#include "DIO_private.h"
#include "Std_types.h"
#include "LCD.h"
#include "ADC.h"
#include "SEVEN_SEG.h"
#include "util/delay.h"
volatile GPIO_peripherals* PeripheralD =(volatile GPIO_peripherals*)0x30;
volatile GPIO_peripherals* PeripheralC =(volatile GPIO_peripherals*)0x33;
volatile GPIO_peripherals* PeripheralB =(volatile GPIO_peripherals*)0x36;
volatile GPIO_peripherals* PeripheralA =(volatile GPIO_peripherals*)0x39;
int main(void)
{
	ADC_Init();
	SEVEN_SEG_init();
	//DIO_voidSetPinDirection(PeripheralA,0,0);
	CLRBIT(DDRA,0);
	u16 x=0;
    while(1)
    {
		x = ADC_getDigitalValueSynchNonBlocking();
		if(x != 0){
			_delay_ms(1);
			sevseg_4num(x);
			while(x == ADC_getDigitalValueSynchNonBlocking());
			//_delay_ms(1);
		}
	
    }
}