/*
 * main.c
 *
 * Created: 10/25/2023 3:55:33 PM
 *  Author: Sarah saeed
 */ 

#include <xc.h>
#include "DIO_interface.h"
#include "util/delay.h"
int main(void)
{
	DIO_voidSetPinDirection(PERIPHERAL_B_BASE,7,1);
	
    while(1)
    {
		_delay_ms(500);
		DIO_voidSetPinValue(PERIPHERAL_B_BASE,7,1);
		_delay_ms(500);
		DIO_voidSetPinValue(PERIPHERAL_B_BASE,7,0);
        //TODO:: Please write your application code 
    }
}