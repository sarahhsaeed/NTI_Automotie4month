/*
 * Timer0_config.h
 *
 * Created: 10/27/2023 9:42:16 AM
 *  Author: Sarah saeed
 */ 


#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_
#include "../../Std_types.h"
		

#define TIMER0_PWM_MODE			TIMER0_INVERTING_PWM_MODE
typedef enum {
	NORMAL,PHASE_CORRECT,CTC,FAST
}wave_generation_mode;

typedef enum {
	NORMAL_OPERATION,TOGGLE,CLEAR,SET
}compare_output_mode;

typedef struct 
{
	u8 prescaler;
	wave_generation_mode mode;
	compare_output_mode compare_output_mode;
}timer0_init_struct;

typedef enum
{
	INT2 = 5,
	INT0,
	INT1
}INT_ID;

typedef enum
{
	OVERFLOW,
	COMPARE_ON_MATCH
}interrupt_src;


#endif /* TIMER0_CONFIG_H_ */