/*
 * TIMER1_prog.c
 *
 * Created: 10/28/2023 11:06:27 PM
 *  Author: Sarah saeed
 */ 
#include "TIMER1_interface.h"
#include "../../HAl/LCD/LCD_interface.h"
void(*Timer1_ptr_to_callback_fns[4])(void) = {NULL, NULL,NULL,NULL};

void Timer1_Init(timer1_init_struct*input)//configure mode and wave generated output
{
	//handle prescaler
	TCCR1B=(TCCR1B&0b11111000)| (input->prescaler);
	//handle mode
	TCCR1A=(TCCR1A&0b11111100)| (input->wave_generation_mode & 0b0011);
	TCCR1B=(TCCR1B&0b11100111)| ((input->wave_generation_mode & 0b1100)<<1);
	//handle compare mode1A,1B
	TCCR1A=(TCCR1A&0b11001111)| ((input->com1B)<<4);
	TCCR1A=(TCCR1A&0b11001111)| ((input->com1A)<<6);
}
void ICU_init(ICU_ConfigType * a_configPtr)
{
	/*set prescaler*/
	TCCR1B=(TCCR1B&0b11111000)| (a_configPtr->prescaler_value);
	TCCR1B=(TCCR1B& 0b10111111)|((a_configPtr->edge_select)<<6);
	/*initially the timer value is 0*/
	TCNT1=0;
	/*initially the ICR1 value is 0*/
	ICR1=0;
	/*force output compare to nonPwm mode*/
	TCCR1A=(1<<FOC1A)|(1<<FOC1B);
}

void ICU_setEdgeDetectionType(icu_trigger a_edgeType){
	if(a_edgeType == RISING){
		SETBIT(TCCR1B,ICES1);
	}
	else{
		CLRBIT(TCCR1B,ICES1);
	}
}
void ICU_clearTimerValue(void){
	TCNT1 = 0;
}
u16 ICU_getInputCaptureValue(void){
	return ICR1;
}
void ICU_deInit(void){
	/* Clear All Timer1 Registers */
	ICU_clearTimerValue();
	TCCR1A = 0;
	TCCR1B = 0;
	ICR1 = 0;

	/*Disable Input Capture Interrupt*/
	CLRBIT(TIMSK,TICIE1);
}

void Timer1_EnableInt(Timer1_interrupt_src int_src)
{
	switch(int_src)
	{
		case OVERFLOW_IE:
		{
			SETBIT(TIMSK,TOIE0);
			break;
		}
		case COMPARE_B_MATCH_IE:
		{
			SETBIT(TIMSK,OCIE1B);
			break;
		}
		case COMPARE_A_MATCH_IE:
		{
			SETBIT(TIMSK,OCIE1A);
			break;
		}
		case INPUT_CAPTURE_IE:
		{
			SETBIT(TIMSK,TICIE1);
			break;
		}
	}
}
void Timer1_DisableInt(Timer1_interrupt_src int_src)
{
	switch(int_src)
	{
		case OVERFLOW_IE:
		{
			CLRBIT(TIMSK,TOIE0);
			break;
		}
		case COMPARE_B_MATCH_IE:
		{
			
			CLRBIT(TIMSK,OCIE1B);
			break;
		}
		case COMPARE_A_MATCH_IE:
		{
			CLRBIT(TIMSK,OCIE1A);
			break;
		}
		case INPUT_CAPTURE_IE:
		{
			SETBIT(TIMSK,TICIE1);
			break;
		}
	}
	
}
void Timer1_EXTI_setCallBack(void(*ptr_to_fn)(void),Timer1_interrupt_src int_src)
{
	
	switch(int_src)
	{
		case OVERFLOW_IE:
		{
			SETBIT(TIMSK,TOIE1);
			Timer1_ptr_to_callback_fns[0] = ptr_to_fn;
			break;
		}
		case COMPARE_B_MATCH_IE:
		{
			SETBIT(TIMSK,OCIE1B);
			Timer1_ptr_to_callback_fns[1] = ptr_to_fn;
			break;
		}
		case COMPARE_A_MATCH_IE:
		{
			SETBIT(TIMSK,OCIE1A);
			Timer1_ptr_to_callback_fns[2] = ptr_to_fn;
			break;
		}
		case INPUT_CAPTURE_IE:
		{
			SETBIT(TIMSK,TICIE1);
			Timer1_ptr_to_callback_fns[3] = ptr_to_fn;
			break;
		}
	}
}
ISR(TIMER1_OVF_vect)
{
	if(!Timer1_ptr_to_callback_fns[0]==NULL){
		Timer1_ptr_to_callback_fns[0]();
	}
}


ISR(TIMER1_OCB_vect)
{
	
	if(!Timer1_ptr_to_callback_fns[1]==NULL){
		Timer1_ptr_to_callback_fns[1]();
	}

}
ISR(TIMER1_OCA_vect)
{
	
	if(!Timer1_ptr_to_callback_fns[2]==NULL){
		Timer1_ptr_to_callback_fns[2]();
	}
}

