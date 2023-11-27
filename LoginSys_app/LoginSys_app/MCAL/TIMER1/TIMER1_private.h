/*
 * TIMER1_private.h
 *
 * Created: 10/28/2023 1:55:28 PM
 *  Author: Sarah saeed
 */ 


#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_
#include "../../Std_types.h"
#include "MemMap.h"

#define ICR1_REG         (*(volatile u16*)0x46)
#define ICR1L_REG        (*(volatile u8*)0x46)
#define ICR1H_REG        (*(volatile u8*)0x47)
#define OCR1B_REG        (*(volatile u16*)0x48)
#define OCR1BL_REG       (*(volatile u8*)0x48)
#define OCR1BH_REG       (*(volatile u8*)0x49)
#define OCR1A_REG        (*(volatile u16*)0x4A)
#define OCR1AL_REG       (*(volatile u8*)0x4A)
#define OCR1AH_REG       (*(volatile u8*)0x4B)
#define TCNT1_REG        (*(volatile u16*)0x4C)
#define TCNT1L_REG       (*(volatile u8*)0x4C)
#define TCNT1H_REG       (*(volatile u8*)0x4D)
#define TCCR1B_REG       (*(volatile u8*)0x4E)
#define TCCR1A_REG       (*(volatile u8*)0x4F)
#define SFIOR_REG        (*(volatile u8*)0x50)
#define OSCCAL_REG       (*(volatile u8*)0x51)

#define NULL (void*) 0


#endif /* TIMER1_PRIVATE_H_ */