/*
 * EXTI_private.h
 *
 * Created: 10/27/2023 6:44:48 PM
 *  Author: Sarah saeed
 */ 


#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_
#include "../../Std_types.h"

#define  GIFR_REG   (*(volatile u8*)(0x5A))   
#define  GICR_REG   (*(volatile u8*)(0x5B))
#define  MCUCR_REG  (*(volatile u8*)(0x55))
#define  MCUCSR_REG (*(volatile u8*)(0x54))

#define NULL ((void*)0)

#define EXT0_ID  6
#define EXT1_ID  7
#define EXT2_ID  5

#define LOW_LEVEL			0
#define ANY_LOGICAL_CHANGE  1
#define FALLING_EDGE		2
#define RISING_EDGE         3
void M_EXTI_voidEnable(u8 id,u8 trigger);
void M_EXTI_voidDisable(void);
void M_EXTI_voidSetCallback(void (*callback_fn)(void),u8 id);



#endif /* EXTI_PRIVATE_H_ */