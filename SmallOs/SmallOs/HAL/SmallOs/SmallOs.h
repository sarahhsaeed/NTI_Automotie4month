/*
 * SmallOs.h
 *
 * Created: 11/11/2023 3:19:09 PM
 *  Author: Sarah saeed
 */ 


#ifndef SMALLOS_H_
#define SMALLOS_H_
#include "../../HAL/LCD/LCD_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIMER/Timer0_interface.h"
#include "../../MCAL/GIE/GIE_interface.h"

typedef void(*TaskFunction)(void);
void task1(void);
void task2(void);
void task3(void);

void Scheduler(void);
#endif /* SMALLOS_H_ */