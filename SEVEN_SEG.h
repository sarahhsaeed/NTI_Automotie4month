/*
 * SEVEN_SEG.h
 *
 * Created: 8/13/2022 12:53:05 PM
 *  Author: safifi
 */ 


#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_

#include "Std_types.h"
#include "DIO_private.h"
void SEVEN_SEG_init(void);
void SEVEN_SEG_one_number(u8 data);
void SEVEN_SEG_two_numbers(u8 data);
#endif /* SEVEN_SEG_H_ */