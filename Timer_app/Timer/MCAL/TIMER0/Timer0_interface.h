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
void Timer_Init(timer0_init_struct*input);//configure mode and wave generated output
void Timer_start(timer0_init_struct*input );
void Timer_stop();
void Timer_GetCounts();void Timer_setDelayTimeMilliSec();
void EnableInt(interrupt_src int_src);
void DisableInt(interrupt_src int_src);
void EXTI_setCallBack(void(*ptr_to_fn)(void),interrupt_src int_src);
void setFastPWM(u8 frequency ,u8 duty);
void setphaseCorrectPWM(u8 frequency , u8 duty);

#endif /* TIMER0_INTERFACE_H_*/

/*,
in delay in ms , i'm sticking at it as long c<numofflows, else i will go out
*/