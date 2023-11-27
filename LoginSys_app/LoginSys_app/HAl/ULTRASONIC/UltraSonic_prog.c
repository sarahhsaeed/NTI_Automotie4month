/*
 * UltraSonic_prog.c
 *
 * Created: 11/9/2023 1:12:10 PM
 *  Author: Sarah saeed
 */ 
#include "UltraSonic_interface.h"
#include "../../MCAL/TIMER1/TIMER1_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../LCD/LCD_interface.h"
#include "util/delay.h"
volatile static u32 ovf_num = 0;


void Ultrasonic_init(void){
	ICU_ConfigType Config; 
	Config.prescaler_value=TIMER1_NO_PRESCALING;
	DIO_voidSetPinDirection(PERIPHERAL_D_BASE, 7, 1);//trigger pin as output
	DIO_voidSetPinDirection(PERIPHERAL_D_BASE, 6, 0);//echo pin as input
	ICU_init(&Config);
	Timer1_EXTI_setCallBack(increment_overflow,OVERFLOW_IE);
	
}
void increment_overflow(void)
{
	ovf_num++;
}
u32 timer1_init_input_capture_usec(void){
	u32 t1, t2;
	ovf_num = 0;
	TCCR1A = 0;
	ICU_setEdgeDetectionType(RISING);                 // detect rising edge
	TIFR |= 1<<ICF1;                                 // clear ICU flag bit
	while(READBIT(TIFR,ICF1) == 0 );                // wait until first rising edge detect
	t1 = ICR1;									   // store value of first rising edge
	ICU_setEdgeDetectionType(FALLING);            // detect failing edge
	TIFR |= 1<<ICF1;                             // clear IC flag
	while(READBIT(TIFR,ICF1) == 0);             // wait until first falling edge detect
	t2 = ICR1;                                 // store value of first falling edge
	TIFR |= 1<<ICF1;                         // clear IC flag
	ICR1 = 0;
	TCNT1 = 0;
	
	return ((ovf_num * MAX_VALUE_TIMER1)  + (t2 - t1));
}
void trigger_ultrasonic(void)
{
	DIO_voidSetPinValue(PERIPHERAL_D_BASE, 7, 1);
	_delay_ms(50);
	DIO_voidSetPinValue(PERIPHERAL_D_BASE, 7, 0);
}
u32 read_distance(void)
{
	u32 time=0,distance=0;
	trigger_ultrasonic();
	time=timer1_init_input_capture_usec();
	distance = (time * 34600) / (F_CPU * 2) ;
	return distance;
}

