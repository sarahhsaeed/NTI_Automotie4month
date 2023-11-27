/*
 * SmallOs.c
 *
 * Created: 11/11/2023 3:18:49 PM
 *  Author: Sarah saeed
 */ 
#include "SmallOs.h"
#include "util/delay.h"
volatile static u16 counter;
volatile static u8 ovf_counter;
TaskFunction tasks[]={task1,task2,task3};
volatile static u8 task1_ready_flag;
volatile static u8 task2_ready_flag;
volatile static u8 task3_ready_flag;

void System_init(void)
{
	H_LCD_void_Init();
	enable_GIE();
	timer0_init_struct timer0_obj;
	timer0_obj.mode=CTC;
	timer0_obj.tim0_prescaler=TIMER0_PRESCALER_1024;
	Timer0_Set_Comp_Match(249);
	Timer0_Init(&timer0_obj);
	init_leds_PushBs();
	timer0_intrupt_src_struct int_src_obj;
	int_src_obj.int_src=COMPARE_ON_MATCH;
	EnableInt(&int_src_obj);
	EXTI_setCallBack(Scheduler,&int_src_obj);
}
void init_leds_PushBs(void)
{
	DIO_voidSetPinDirection(PERIPHERAL_A_BASE,4,1);//green led
	DIO_voidSetPinDirection(PERIPHERAL_A_BASE,5,1);//blue led
	DIO_voidSetPinDirection(PERIPHERAL_A_BASE,7,1);//red led
	DIO_voidSetPinDirection(PERIPHERAL_A_BASE,1,0);//PB1
	DIO_voidSetPinValue(PERIPHERAL_A_BASE,1,1);//pull up PB1
	
}
void task1(void)//every 1s
{
	DIO_voidSetPinValue(PERIPHERAL_A_BASE,7,1);
	_delay_ms(45);
	DIO_voidSetPinValue(PERIPHERAL_A_BASE,7,0);
}
void task2(void)//every 0.5s
{	
	 static u8 prev_state,new_state = 0;
	 
	 if (DIO_voidGetPinValue(PERIPHERAL_A_BASE, 1) == 0)
	 {
		 prev_state = !prev_state; 
		 DIO_voidSetPinValue(PERIPHERAL_A_BASE, 5, prev_state);
		 H_LCD_void_sendIntNum(prev_state);
	 }
	 
}
void task3(void)//every 3 sec
{
	DIO_voidSetPinValue(PERIPHERAL_A_BASE,4,1);
	_delay_ms(45);
	DIO_voidSetPinValue(PERIPHERAL_A_BASE,4,0);
}
void work_on_tasks(void)
{
	
	if (task2_ready_flag==1)
	{
		tasks[1]();
		task2_ready_flag=0;
	}
	if (task1_ready_flag==1)
	{
		tasks[0]();
		task1_ready_flag=0;
	}
	if (task3_ready_flag==1)
	{
		tasks[2]();
		task3_ready_flag=0;
	}
}

void Scheduler(void)
{
	counter++;
	if (counter==31)//every 500ms
	{
		ovf_counter++;
		counter=0;
		task2_ready_flag=1;//task2 every 0.5 seconds
		
	}
	if (ovf_counter%6==0  && ovf_counter!=0)
	{
		task3_ready_flag=1;//task3 every 3 seconds
	}
	if (ovf_counter%2==0 && ovf_counter!=0)
	{
		task1_ready_flag=1;//task1 every 1 second
	}
	if (ovf_counter==7)
	{
		ovf_counter=0;
	}
}
