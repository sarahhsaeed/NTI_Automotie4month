/*
 * main.c
 *
 * Created: 10/25/2023 6:40:42 PM
 *  Author: Sarah saeed
 */ 

#include <xc.h>
#include "HAL/sevSeg_interface.h"
#include "MCAL/Std_types.h"
#include "util/delay.h"
int main(void)
{
	SEVEN_SEG_init();	
	int i=0;
    while(1)
    {
			SEVEN_SEG_write(i);
			i++;
			if (i==100)
			{
				i=0;
			}
			_delay_ms(500);

			
    }
}