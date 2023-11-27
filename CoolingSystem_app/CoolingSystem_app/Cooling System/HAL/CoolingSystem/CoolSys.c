/*
 * CoolSys.c
 *
 * Created: 11/8/2023 10:48:00 AM
 *  Author: Sarah saeed
 */ 
#include "CoolSys.h"
#include "util/delay.h"
void System_init(void)
{	
	//LCD init 
	H_LCD_void_Init();
	//ADC init
	DIO_voidSetPinDirection(PERIPHERAL_A_BASE,0,0);//A0 is input that takes analog signal
	init_adc_struct adc_obj;
	adc_obj.adc_en=ADC_ENABLE;
	adc_obj.vref=AVCC;
	adc_obj.prescaler=ADC_PRESCALER_128;
	ADC_Init(&adc_obj);
	//DC motor init
	DcMotor_init();
	//PWM init
	pwm_init();
	
}

void pwm_init(void)
{
	DIO_voidSetPinDirection(PERIPHERAL_B_BASE,3,1);
	timer0_init_struct timer0_obj;  // Declare a non-pointer variable
	timer0_obj.mode=FAST ;
	timer0_obj.tim0_prescaler= TIMER0_PRESCALER_64;
	timer0_obj.compare_output_mode=CLEAR;
	Timer0_Init(&timer0_obj);
}
void get_temp_contol_speed(void)
{
	u8 temp=LM35_getTemperature();
	u8 speed=0;
	if (temp<=25)
	{
		speed=0;
		controlMotor(speed,CW);
	}
	else if (temp>25 && temp<35)
	{
		speed=50;
		controlMotor(speed,CW);
	}
	else 
	{
		speed=80;
		controlMotor(speed,CW);
	}
	
	displayTempAndSpeed(temp,speed);
		
}
void displayTempAndSpeed(u8 temp, u8 speed)
{	
	H_LCD_void_sendString("Temp: ");										
	H_LCD_void_sendIntNum(temp);	
	H_LCD_void_sendCommand(OVER_WRITE);			
	H_LCD_void_sendCommand(NEXT_LINE);
	H_LCD_void_sendString("Motor speed: ");
	H_LCD_void_sendIntNum(speed);	
	H_LCD_void_sendCommand(0x80);	
	_delay_ms(100);
}






