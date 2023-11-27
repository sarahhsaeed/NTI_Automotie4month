/*
 * DcMotor_prog.c
 *
 * Created: 11/8/2023 4:16:05 PM
 *  Author: Sarah saeed
 */ 
#include "DcMotor_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"

void DcMotor_init(void)
{
	DIO_voidSetPinDirection(PERIPHERAL_B_BASE,IN1,1);
	DIO_voidSetPinDirection(PERIPHERAL_B_BASE,IN2,1);
	//stop at the begging
	DIO_voidSetPinValue(PERIPHERAL_B_BASE,IN1,0);
	DIO_voidSetPinValue(PERIPHERAL_B_BASE,IN2,0);
}

void controlMotor(u8 speed,DcMotor_state state)
{
	if (state==OFF)
	{
		DIO_voidSetPinValue(PERIPHERAL_B_BASE,IN1,0);
		DIO_voidSetPinValue(PERIPHERAL_B_BASE,IN2,0);
		
	}
	else if (state==CW)
	{
		DIO_voidSetPinValue(PERIPHERAL_B_BASE,IN1,0);
		DIO_voidSetPinValue(PERIPHERAL_B_BASE,IN2,1);
	}
	else if(state==A_CW)
	{
		DIO_voidSetPinValue(PERIPHERAL_B_BASE,IN1,1);
		DIO_voidSetPinValue(PERIPHERAL_B_BASE,IN2,0);
		
	}
	Timer0_PWM_Set_Duty(speed);
	
}