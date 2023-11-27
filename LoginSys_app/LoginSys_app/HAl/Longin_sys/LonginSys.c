/*
 * LonginSys_prog.c
 *
 * Created: 11/9/2023 1:05:22 PM
 *  Author: Sarah saeed
 */ 
#include "LoginSys.h"
#include "util/delay.h"

volatile static u32 distance;
volatile static u8 flag;
volatile static u8 successful_login;
volatile static u16 counter;
volatile static u16 ovf_counter;

volatile static u8 blocking;
volatile u8 user_password[]={1,2,3,4};
void SysInit(void)
{
	init_leds_relay();
	H_LCD_void_Init();
	Ultrasonic_init();
	KEYPAD_init();
	enable_GIE();
	timer0_init_struct timer0_obj;
	timer0_obj.mode=CTC;
	timer0_obj.tim0_prescaler=TIMER0_PRESCALER_1024;
	Timer0_Set_Comp_Match(249);
	Timer0_Init(&timer0_obj);
	
}
void init_leds_relay(void)
{
	DIO_voidSetPinDirection(PERIPHERAL_A_BASE,7,1);
	DIO_voidSetPinDirection(PERIPHERAL_A_BASE,6,1);
	DIO_voidSetPinDirection(PERIPHERAL_A_BASE,5,1);
	DIO_voidSetPinDirection(PERIPHERAL_A_BASE,4,1);
}
void control_leds(void)
{
	u8 key_pressed=0;
	key_pressed=KEYPAD_read();
	if (key_pressed=='+')
	{
		LED_RED_ON;
		while(key_pressed==KEYPAD_read());
	}
	if (key_pressed=='-')
	{
		LED_RED_OFF;
		while(key_pressed==KEYPAD_read());
	}
	if (key_pressed=='=')
	{
		LED_BLUE_ON;
		while(key_pressed==KEYPAD_read());
	}
	if (key_pressed=='c')
	{
		LED_BLUE_OFF;
		while(key_pressed==KEYPAD_read());
	}
}

void start_locking(void)
{
	blocking=1;
	timer0_intrupt_src_struct int_src_obj;
	int_src_obj.int_src=COMPARE_ON_MATCH;
	EnableInt(&int_src_obj);
	EXTI_setCallBack(timer_callback,&int_src_obj);
	LED_GREEN_ON;
	H_LCD_void_sendString(" Wait for 10 seconds");
	_delay_ms(500);
	H_LCD_void_sendCommand(CLEAR_DISPLAY);
	while (blocking==1)
	{
		H_LCD_void_sendCommand(OVER_WRITE);
		H_LCD_void_sendIntNum(ovf_counter);
		if (ovf_counter==10)
		{
			LED_GREEN_OFF;
			DisableInt(&int_src_obj);
			blocking=0;
			ovf_counter=0;
		}
	}
}
void timer_callback(void)
{
	counter++;
	if (counter==62)//every 1s
	{
		ovf_counter++;
		counter=0;	
	}
}
void login(void)
{
	u8 entered_password[4];
	distance=read_distance();
	print_distance(distance);
	H_LCD_void_gotoXY(2,1);
	if (distance>=0 &&distance<=15)
	{
		H_LCD_void_sendString(" Welcome  ");
		H_LCD_void_sendCommand(OVER_WRITE);
		if (KEYPAD_read()=='*' && flag<MAX_NUMBER_OF_TRY)
		{
			H_LCD_void_sendCommand(CLEAR_DISPLAY);
			enter_password();
		}
		if(KEYPAD_read()=='*' && flag==MAX_NUMBER_OF_TRY)
		{
			H_LCD_void_sendCommand(CLEAR_DISPLAY);
			H_LCD_void_sendString(" Locked");
			_delay_ms(1000);
			H_LCD_void_sendCommand(CLEAR_DISPLAY);
			start_locking();
			H_LCD_void_sendString("__ Unlocked");
			_delay_ms(1000);
			H_LCD_void_sendCommand(CLEAR_DISPLAY);
			flag=0;
		}
		if (successful_login==1)
			{
				control_leds();
			}
		}
		else
		{
			H_LCD_void_sendString(" No object");
			H_LCD_void_sendCommand(OVER_WRITE);
		}
	
}
void print_distance(u32 dis)
{
	H_LCD_void_sendString(" Distance is ");
	H_LCD_void_sendIntNum(distance);
}
void enter_password(void)
{
	u8 i=0;
	static u8 password[PASSWORD_SIZE];
	u8 key=0;
	H_LCD_void_sendString(" Enter password: ");
	_delay_ms(300);
	H_LCD_void_sendCommand(CLEAR_DISPLAY);
	while(1)
	{
		key=KEYPAD_read();
		if (key!=0)
		{
			password[i]=key-48;
			i++;
			while(key==KEYPAD_read());
			H_LCD_void_sendString("*");
			if (i==4)
			{
				i=0;
				break;
			}
		}
			
		}
	_delay_ms(10);	
	validate_password(&password[0]);
}

void validate_password(u8 *ptr_password)
{
	static u8 counter=0;
	for (u8 i=0;i<PASSWORD_SIZE;i++)
	{
		if (ptr_password[i]==user_password[i])
		{
			
			counter++;
		}
		
	}
	H_LCD_void_sendCommand(CLEAR_DISPLAY);
	if (counter==PASSWORD_SIZE)
	{
		RELAY_CLOSE;
		H_LCD_void_sendString(" Welcome sarah! ");
		successful_login=1;
		flag=0;
	}
	else
	{
		RELAY_OPEN;
		H_LCD_void_sendString(" Try again ");
		successful_login=0;
		flag++;
	}
	_delay_ms(300);
	H_LCD_void_sendCommand(CLEAR_DISPLAY);
	counter=0;
}