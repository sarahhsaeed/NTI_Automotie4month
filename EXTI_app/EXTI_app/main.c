/*
 * main.c
 *
 * Created: 10/27/2023 6:42:11 PM
 *  Author: Sarah saeed
 */ 

#include <xc.h>
#include "MCAL/EXTI/EXTI_interface.h"
#include "MCAL/GIE/GIE_interface.h"
#include "MCAL/DIO/DIO_interface.h"
#include "util/delay.h"
void foo(void);
int main(void)
{
	//create a pointer to function
	
	enable_GIE();
	DIO_voidSetPinDirection(PERIPHERAL_A_BASE,6,1); //ouput
	DIO_voidSetPinDirection(PERIPHERAL_D_BASE,2,0); //input
	M_EXTI_voidEnable(6,0);//int0, low level
	M_EXTI_voidSetCallback(foo,0);
    while(1)
    {
		DIO_voidSetPinValue(PERIPHERAL_D_BASE,2,1);
		//DIO_voidSetPinValue(PERIPHERAL_D_BASE,2,1);
		//_delay_ms(1000);
		//DIO_voidSetPinValue(PERIPHERAL_D_BASE,2,0);
		
		
    }
}
void foo(void)
{
	DIO_voidSetPinValue(PERIPHERAL_A_BASE,6,1);
}