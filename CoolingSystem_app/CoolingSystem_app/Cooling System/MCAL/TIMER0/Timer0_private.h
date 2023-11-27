/*
 * Timer0_private.h
 *
 * Created: 10/27/2023 9:41:18 AM
 *  Author: Sarah saeed
 */ 


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_
#include "../../Std_types.h"

#define  TCCR0_REG (*( (volatile u8 *) 0x53))
#define  TCNT0_REG (*( (volatile u8 *) 0x52))
#define  OCR0_REG  (*( (volatile u8 *) 0x5C))
#define  TIMSK_REG (*( (volatile u8 *) 0x59))
#define  TIFR_REG  (*( (volatile u8 *) 0x58))

#define CS00_BIT  (u8)  0
#define CS01_BIT  (u8)  1
#define CS02_BIT  (u8)  2
#define WGM01_BIT (u8)  3
#define COM00_BIT (u8)  4
#define COM01_BIT (u8)  5
#define WGM00_BIT (u8)  6
#define FOC0_BIT  (u8)  7

#define TOIE0_BIT  (u8)  0
#define OCIE0_BIT  (u8)  1
#define TOIE1_BIT  (u8)  2
#define OCIE1B_BIT (u8)  3
#define OCIE1A_BIT (u8)  4
#define TICIE1_BIT (u8)  5
#define TOIE2_BIT  (u8)  6
#define OCIE2_BIT  (u8)  7

#define NULL (void*) 0

#define TIMER0_NORMAL_MODE				1
#define TIMER0_CTC_MODE					2
#define TIMER0_FAST_PWM_MODE			3
#define TIMER0_PHASE_CORRECT_PWM_MODE   4

#define TIMER0_NON_INVERTING_PWM_MODE	1
#define TIMER0_INVERTING_PWM_MODE		2

#endif /* TIMER0_PRIVATE_H_ */