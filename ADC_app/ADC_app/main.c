/*
 * main.c
 *
 * Created: 10/24/2023 9:39:24 AM
 *  Author: Sarah saeed
 */ 

#include <xc.h>

#include "MCAL/ADC/ADC_interface.h"
#include "MCAL/DIO/DIO_interface.h"
#include "util/delay.h"
int main(void)
{
	ADC_Init();
	//DIO_voidSetPinDirection(PeripheralA,0,0);
	CLRBIT(DDRA,0);
	u16 x=0;
    while(1)
    {
		x = ADC_getDigitalValueSynchNonBlocking();
		if(x != 0){
			_delay_ms(1);
			//sevseg_4num(x);
			while(x == ADC_getDigitalValueSynchNonBlocking());
			//_delay_ms(1);
		}
	
    }
}