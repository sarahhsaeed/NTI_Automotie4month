/*
 * DcMotor_interface.h
 *
 * Created: 11/8/2023 4:16:35 PM
 *  Author: Sarah saeed
 */ 


#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_
#include "DcMotor_config.h"
#include "DcMotor_private.h"
#include "../../Std_types.h"

#define IN1 0
#define IN2 1

typedef enum 
{
	OFF,CW,A_CW
}DcMotor_state;

void DcMotor_init(void);
void controlMotor(u8 speed,DcMotor_state state);





#endif /* DCMOTOR_INTERFACE_H_ */