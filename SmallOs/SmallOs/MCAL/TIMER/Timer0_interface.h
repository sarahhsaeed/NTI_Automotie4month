/*
 * Timer0_interface.h
 *
 * Created: 10/27/2023 9:42:00 AM
 *  Author: Sarah saeed
 */ 
#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_
#include "Timer0_config.h"
#include "Timer0_private.h"
#include "MemMap.h"
#include "../../BIT_MATH.h"

#define TIMER0_PWM_MODE			TIMER0_NON_INVERTING_PWM_MODE
typedef enum
{
	TIMER0_NO_CLOCK_SRC,
	TIMER0_NO_PRESCALING=1,
	TIMER0_PRESCALER_8,
	TIMER0_PRESCALER_64,
	TIMER0_PRESCALER_256,
	TIMER0_PRESCALER_1024,
	TIMER0_EXT_CLOCK_FALLING_EDGE,
	TIMER0_EXT_CLOCK_RISING_EDGE
}Timer0_Prescaler; 
typedef enum {
	NORMAL,PHASE_CORRECT,CTC,FAST
}wave_generation_mode;

typedef enum {
	NORMAL_OPERATION,TOGGLE,CLEAR,SET
}compare_output_mode;

typedef struct 
{
	Timer0_Prescaler tim0_prescaler;
	wave_generation_mode mode;
	compare_output_mode compare_output_mode;
}timer0_init_struct;

typedef enum
{
	OVERFLOW,
	COMPARE_ON_MATCH
}interrupt_src;
typedef struct{
	interrupt_src int_src;
}timer0_intrupt_src_struct;

//////////////////////////////////////////////////////////

#define TIMER0_NO_CLOCK_SRC             0
#define TIMER0_NO_PRESCALING            1
#define TIMER0_PRESCALER_8              2
#define TIMER0_PRESCALER_64             3
#define TIMER0_PRESCALER_256            4
#define TIMER0_PRESCALER_1024           5
#define TIMER0_EXT_CLOCK_FALLING_EDGE   6
#define TIMER0_EXT_CLOCK_RISING_EDGE    7

#define TIMER0_PRESCALER TIMER0_NO_PRESCALING

#define NORMAL             0
#define PHASE_CORRECT      1
#define CTC                2
#define FAST               3

#define TIMER0_MODE       NORMAL 

#define NORMAL_OPERATION   0
#define TOGGLE             1
#define CLEAR              2
#define SET                3
#define TIMER0_COMP_OUT   NORMAL_OPERATION

#define OVERFLOW           0
#define COMPARE_ON_MATCH   1

#define INTRUPT_SRC   OVERFLOW


void Timer0_Init(timer0_init_struct *input);//configure mode and wave generated output
void Timer_start(timer0_init_struct*input);
void Timer_stop();
u32 Timer_GetCounts(void);void Timer_setDelayTimeMilliSec();
void EnableInt(timer0_intrupt_src_struct *int_src);
void DisableInt(timer0_intrupt_src_struct *int_src);
void EXTI_setCallBack(void(*ptr_to_fn)(void),timer0_intrupt_src_struct *int_src);
void Timer0_Set_Comp_Match(u8 copy_u9_compare_val);
void setFastPWM(u8 duty);
void setphaseCorrectPWM(u8 duty);

#endif /* TIMER0_INTERFACE_H_*/
