/*
 * main.c
 *
 * Created: 11/8/2023 10:31:16 AM
 *  Author: Sarah Saeed
 */ 
#include "HAL/Configurable duty cycle/config_dutyCycle.h"
#include "util/delay.h"


int main(void)
{
	u8 speed;
	SystemInit();
	while(1)
	{
		speed=read_duty_from_keypad();
		controlMotor(speed,CW);
		displaySpeed(speed);
	}
}


