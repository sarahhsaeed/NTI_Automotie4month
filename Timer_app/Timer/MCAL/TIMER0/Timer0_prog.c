/*
 * Timer0_prog.c
 *
 * Created: 10/27/2023 9:42:59 AM
 *  Author: Sarah saeed
 */ 
#include "Timer0_interface.h"
void(*ptr_to_callback_fns[2])(void) = {NULL, NULL};

void Timer_Init(timer0_init_struct*input)//configure mode and wave generated output
{
	//configure mode
	switch(input->mode)
	{
		case (NORMAL): 
		{
		CLRBIT(TCCR0_REG,WGM01_BIT);
		CLRBIT(TCCR0_REG,WGM00_BIT);	
		break;
		}
		case (CTC):
		{
			SETBIT(TCCR0_REG,WGM01_BIT);
			CLRBIT(TCCR0_REG,WGM00_BIT);
			break;
		}
		case (PHASE_CORRECT):
		{
			CLRBIT(TCCR0_REG,WGM01_BIT);
			SETBIT(TCCR0_REG,WGM00_BIT);
			//configure compare on mach
			
			break;
		}
		case (FAST):
		{
			SETBIT(TCCR0_REG,WGM01_BIT);
			SETBIT(TCCR0_REG,WGM00_BIT);
			break;
		}
	}
	
	//configure compare on match
	switch(input->compare_output_mode)
	{
		case(NORMAL_OPERATION):
		{
			CLRBIT(TCCR0_REG,COM00_BIT);
			CLRBIT(TCCR0_REG,COM01_BIT);
			break;
		}
		case(TOGGLE):
		{
			SETBIT(TCCR0_REG,COM00_BIT);
			CLRBIT(TCCR0_REG,COM01_BIT);
			break;
		}
		case(CLEAR):
		{
			CLRBIT(TCCR0_REG,COM00_BIT);
			SETBIT(TCCR0_REG,COM01_BIT);
			break;
		}
		case(SET):
		{
			SETBIT(TCCR0_REG,COM00_BIT);
			SETBIT(TCCR0_REG,COM01_BIT);
			break;
		}
	}
	//configure prescaler 
	TCCR0_REG = (TCCR0_REG & 0b11111000) | input->prescaler;
}

void Timer_start(timer0_init_struct*input )
{
	TCCR0_REG = (TCCR0_REG & 0b11111000) | input->prescaler;
}
void Timer_stop()
{
	CLRBIT(TCCR0_REG,CS00_BIT);
	CLRBIT(TCCR0_REG,CS01_BIT);
	CLRBIT(TCCR0_REG,CS02_BIT);
}
void EnableInt(interrupt_src int_src)
{
	switch(int_src)
	{
		case OVERFLOW:
		{
			SETBIT(TIMSK_REG,TOIE0_BIT);
			break;
		}
		case COMPARE_ON_MATCH:
		{
			SETBIT(TIMSK_REG,OCIE0_BIT);
			break;
		}
	}
}
void DisableInt(interrupt_src int_src)
{
	switch(int_src)
	{
		case OVERFLOW:
		{
			CLRBIT(TIMSK_REG,TOIE0_BIT);
			break;
		}
		case COMPARE_ON_MATCH:
		{
			CLRBIT(TIMSK_REG,OCIE0_BIT);
			break;
		}
	}
	
}
void EXTI_setCallBack(void(*ptr_to_fn)(void),interrupt_src int_src)
{
	switch(int_src):
	{
		case OVERFLOW:
		{
			ptr_to_callback_fns[0] = ptr_to_fn;/*********************/

			break;
		}
		case COMPARE_ON_MATCH:
		{
			ptr_to_callback_fns[1] = ptr_to_fn;/*********************/
			break;
		}
	}
}
ISR(INT0_vect)
{  
	if(!ptr_to_callback_fns[0]==NULL){
		ptr_to_callback_fns[0]();
	}
}


ISR(INT1_vect)
{
	
	if(!ptr_to_callback_fns[1]==NULL){
		ptr_to_callback_fns[1]();
	}

}
void Timer_setDelayTimeMilliSec()
{
		
}