/*
 * main.c
 *
 * Created: 11/8/2023 10:31:16 AM
 *  Author: Sarah Saeed
 */ 
#include "HAL/CoolingSystem/CoolSys.h"
#include "util/delay.h"


int main(void)
{
	u8 speed;
	System_init();
	while(1)
	{
		get_temp_contol_speed();
	}
}


