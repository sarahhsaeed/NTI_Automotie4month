/*
 * main.c
 *
 * Created: 10/21/2023 8:44:35 PM
 *  Author: Sarah saeed
 */ 

#include <xc.h>
#define F_CPU 16000000
#include "KEYPAD.h"
#include "DIO_private.h"
#include "SEVEN_SEG.h"
#include "Std_types.h"
#include "util/delay.h"
volatile GPIO_peripherals* PeripheralD =(volatile GPIO_peripherals*)0x30;
volatile GPIO_peripherals* PeripheralC =(volatile GPIO_peripherals*)0x33;
volatile GPIO_peripherals* PeripheralB =(volatile GPIO_peripherals*)0x36;
volatile GPIO_peripherals* PeripheralA =(volatile GPIO_peripherals*)0x39;
int main(void)
{
   //KEYPAD_init();
   SEVEN_SEG_init();
   u8 num=0;
   
   while(1)
   {  
	   
		   SEVEN_SEG_two_numbers(i);

	   
   }
}