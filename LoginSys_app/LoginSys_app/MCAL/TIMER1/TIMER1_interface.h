/*
 * TIMER1_interface.h
 *
 * Created: 10/28/2023 1:56:29 PM
 *  Author: Sarah saeed
 */ 


#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_
#include "TIMER1_private.h"
#include "TIMER1_config.h"
#include "../../BIT_MATH.h"
#define F_CPU 16000000
#define MAX_VALUE_TIMER1 65537 
typedef enum
{
	TIMER1_NORMAL_OPERATION,TIMER1_TOGGLE,TIMER1_CLEAR,TIMER1_SET
}timer1_compare_output_mode;
typedef enum
{
	TIMER1_NO_CLOCK_SRC,
	TIMER1_NO_PRESCALING,
	TIMER1_PRESCALER_8,
	TIMER1_PRESCALER_64,
	TIMER1_PRESCALER_256,
	TIMER1_PRESCALER_1024,
	TIMER1_EXT_CLOCK_FALLING_EDGE,
	TIMER1_EXT_CLOCK_RISING_EDGE
}timer1_Prescaler;

typedef enum{
	Normal_Mode=0,
	PhaseCorrect_PWM_8bit_Mode,
	PhaseCorrect_PWM_9bit_Mode,
	PhaseCorrect_PWM_10bit_Mode,
	CTC_OCRA1_Mode,
	Fast_PWM_8bit_Mode,
	Fast_PWM_9bit_Mode,
	Fast_PWM_10bit_Mode,
	Phase_Frequency_Correct_ICR1_MODE,
	Phase_Frequency_Correct_OCR1A_MODE,
	PWM_PhaseCorrect_ICR1,
	PWM_PhaseCorrect_OCR1A,
	CTC_ICR1_MODE,
	RESERVED,
	Fast_PWM_ICR1_MODE,
	Fast_PWM_OCR1A_MODE
}Timer1_modes;
typedef struct
{
	timer1_Prescaler prescaler;
	Timer1_modes wave_generation_mode ;
	timer1_compare_output_mode com1A;
	timer1_compare_output_mode com1B;
}timer1_init_struct;

typedef enum
{
	OVERFLOW_IE,
	COMPARE_B_MATCH_IE,
	COMPARE_A_MATCH_IE,
	INPUT_CAPTURE_IE
}Timer1_interrupt_src;
typedef enum
{
	FALLING=0,
	RISING
}icu_trigger;

typedef struct {
	icu_trigger edge_select;
	timer1_Prescaler prescaler_value;
	
}ICU_ConfigType;

void Timer1_Init(timer1_init_struct*input);


#endif /* TIMER1_INTERFACE_H_ */