/*
 * EXTI_interface.h
 *
 * Created: 10/27/2023 6:45:31 PM
 *  Author: Sarah saeed
 */ 


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_
#include "EXTI_config.h"
#include "EXTI_private.h"

void M_EXTI_voidEnable(u8 id,u8 trigger);
void M_EXTI_voidDisable(void);
void M_EXTI_voidSetCallback(void (*callback_fn)(void),u8 id);



#endif /* EXTI_INTERFACE_H_ */