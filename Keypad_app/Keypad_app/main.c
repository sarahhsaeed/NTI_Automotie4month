/*
 * main.c
 *
 * Created: 10/21/2023 8:44:35 PM
 *  Author: Sarah saeed
 */ 

#include <xc.h>
#include "hal/Keypad_interface.h"
#include "sevSeg_interface.h"
#include "util/delay.h"
int main(void)
{
	u8 x;
	SEVEN_SEG_init();
	KEYPAD_init();
   while(1)
   {  
	    x = KEYPAD_read();
	    if(x != 0){
		    SEVEN_SEG_write(x-48);
		    while(x == KEYPAD_read());
		    _delay_ms(1);
	    }
	   
   }
}
