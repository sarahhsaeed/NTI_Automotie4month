/*
 * Timer0_prog.c
 *
 * Created: 10/27/2023 9:42:59 AM
 *  Author: Sarah saeed
 */ 
#include "Timer0_interface.h"
void(*ptr_to_callback_fns[2])(void) = {NULL, NULL};
volatile static u32 ovf_flag,OVF_Num,counter;
#include "avr/io.h"
#include "../../HAL/LCD/LCD_interface.h"
//void (*timer0_ctc_isr)(void);

void Timer0_Init(timer0_init_struct *input)//configure mode and wave generated output
{
	TCCR0 = (TCCR0 & 0b11111000) | (input->tim0_prescaler);
	//configure mode
	switch(input->mode)
	{
		case (NORMAL):
		{
			CLRBIT(TCCR0,WGM01);
			CLRBIT(TCCR0,WGM00);
			
			break;
		}
		case (CTC):
		{
			SETBIT(TCCR0,WGM01);
			CLRBIT(TCCR0,WGM00);
			break;
		}
		case (PHASE_CORRECT):
		{
			CLRBIT(TCCR0,WGM01);
			SETBIT(TCCR0,WGM00);
			break;
		}
		case (FAST):
		{
			SETBIT(TCCR0,WGM01);
			SETBIT(TCCR0,WGM00);
			break;
		}
		default:
		break;
	}
	//
	//configure compare on match
	switch(input->compare_output_mode)
	{
		case(NORMAL_OPERATION):
		{
			CLRBIT(TCCR0,COM00);
			CLRBIT(TCCR0,COM01);
			break;
		}
		case(TOGGLE):
		{
			SETBIT(TCCR0,COM00);
			CLRBIT(TCCR0,COM01);
			break;
		}
		case(CLEAR)://non inverting
		{
			CLRBIT(TCCR0,COM00);
			SETBIT(TCCR0,COM01);
			break;
		}
		case(SET):
		{
			SETBIT(TCCR0,COM00);
			SETBIT(TCCR0,COM01);
			break;
		}
		default:
		break;
	}
	 
}


void Timer_start(timer0_init_struct*input )
{
	TCCR0 = (TCCR0 & 0b11111000) | input->tim0_prescaler;
}
void Timer_stop()
{
	CLRBIT(TCCR0,CS00);
	CLRBIT(TCCR0,CS01);
	CLRBIT(TCCR0,CS02);
}
void EnableInt(timer0_intrupt_src_struct *int_source)
{
	switch(int_source->int_src)
	{
		case OVERFLOW:
		{
			
			SETBIT(TIMSK,TOIE0);
			break;
		}
		case COMPARE_ON_MATCH:
		{
			SETBIT(TIMSK,OCIE0);
			break;
		}
	}
}
void DisableInt(timer0_intrupt_src_struct *int_source)
{
	switch(int_source->int_src)
	{
		case OVERFLOW:
		{
			
			CLRBIT(TIMSK,TOIE0);
			break;
		}
		case COMPARE_ON_MATCH:
		{
			CLRBIT(TIMSK,OCIE0);
			break;
		}
	}
	
}
void EXTI_setCallBack(void(*ptr_to_fn)(void),timer0_intrupt_src_struct *int_source)
{
	
	switch(int_source->int_src)
	{
		case OVERFLOW:
		{
			ptr_to_callback_fns[0] = ptr_to_fn;
			break;
		}
		case COMPARE_ON_MATCH:
		{
			
			ptr_to_callback_fns[1] = ptr_to_fn;
			break;
		}
	}
}
ISR(TIMER0_OVF_vect)
{  
	if(!ptr_to_callback_fns[0]==NULL){
		
		ptr_to_callback_fns[0]();
	}
}


ISR(TIMER0_COMP_vect)
{
	
	if(!ptr_to_callback_fns[1]==NULL){
		ptr_to_callback_fns[1]();
		
	}

}

u32 Timer_GetCounts(void)
{
	return counter;
}
void call_fn_delay(void)
{
	static u32 c=0;
	c++;	
	if (c==OVF_Num)
	{
		ovf_flag=1;
		c=0;
	}
}

void Timer_setDelayTimeMilliSec(u32 time)
{
u32 counter1=0;
u32 tick=1024/16;//tick in us
counter1=(time *1000)/tick;
OVF_Num=counter1/256;
u32 OVF_Rem=counter1%256;
if (OVF_Rem !=0)
{
	OVF_Num++;
	TCNT0_REG=256-OVF_Rem;
}
timer0_intrupt_src_struct int_src_ob;
int_src_ob.int_src=OVERFLOW;
EXTI_setCallBack(call_fn_delay,&int_src_ob);
while(ovf_flag==0);
ovf_flag=0;
}
void Timer0_Set_Comp_Match(u8 copy_u9_compare_val)
{
	OCR0 = copy_u9_compare_val;
}

void setFastPWM(u8 duty)
{
	#if (TIMER0_PWM_MODE == TIMER0_NON_INVERTING_PWM_MODE)
	OCR0=255*(duty/100);
	#elif (TIMER0_PWM_MODE == TIMER0_INVERTING_PWM_MODE)
	OCR0=255*(1-(duty/100));
	#endif
}

void setphaseCorrectPWM(u8 duty)
{ 
	#if (TIMER0_PWM_MODE == TIMER0_NON_INVERTING_PWM_MODE)
	OCR0_REG=255*(duty/100);
	#elif (TIMER0_PWM_MODE == TIMER0_INVERTING_PWM_MODE)
	OCR0_REG=(510-510*(duty/100))/2;
	#endif
}
void Timer0_PWM_Set_Duty(u8 Duty)
{
	#if (TIMER0_PWM_MODE == TIMER0_NON_INVERTING_PWM_MODE)
	if (Duty <=100)
	{
		OCR0 = (((u8)Duty * 255)/100);
	}
	#elif (TIMER0_PWM_MODE == TIMER0_INVERTING_PWM_MODE)
	if (Duty <=100){
	OCR0 = 255 - ((((u8)Duty * 255)/100 ));}
	
	#endif

}