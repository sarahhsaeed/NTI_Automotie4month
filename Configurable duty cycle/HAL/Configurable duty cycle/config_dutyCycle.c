/*
 * config_dutyCycle.c
 *
 * Created: 11/8/2023 7:00:39 PM
 *  Author: Sarah saeed
 */ 
#include "config_dutyCycle.h"
#include "util/delay.h"
void  SystemInit(void)
{
	KEYPAD_init();
	H_LCD_void_Init();
	DcMotor_init();
	pwm_init_();
}
void pwm_init_(void)
{
	DIO_voidSetPinDirection(PERIPHERAL_B_BASE,3,1);
	timer0_init_struct timer0_obj;  // Declare a non-pointer variable
	timer0_obj.mode=FAST ;
	timer0_obj.tim0_prescaler= TIMER0_PRESCALER_64;
	timer0_obj.compare_output_mode=CLEAR;
	Timer0_Init(&timer0_obj);
}

u8 read_duty_from_keypad(void)
{
	static u8 flag=0,duty_value=0;
	u8 keypad_value[2];
	u8 i=0,key=0;
	if (flag==0)
	{
		H_LCD_void_sendString("enter duty value: ");
		_delay_ms(5000);
		H_LCD_void_sendCommand(CLEAR_DISPLAY);
		while(1)
		{
			key=KEYPAD_read();
			if (key!=0)
			{
				keypad_value[i]=key-48;
				i++;
				if (i==2)
				{
					break;
				}
				while(key==KEYPAD_read());
			}
			
		}
		
		duty_value=keypad_value[0]*10+keypad_value[1];
		flag++;
	}
	
	if (KEYPAD_read()=='*')
	{
		H_LCD_void_sendCommand(CLEAR_DISPLAY);
		flag=0;
	}
	return duty_value;
}
void displaySpeed(u8 duty)
{
	H_LCD_void_sendString("duty value is : ");
	H_LCD_void_sendIntNum(duty);
	H_LCD_void_sendCommand(OVER_WRITE);
	_delay_ms(10);
}

