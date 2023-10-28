/*
 * EXTI_prog.c
 *
 * Created: 10/27/2023 6:45:45 PM
 *  Author: Sarah saeed
 */ 
#include "MemMap.h"
#include "EXTI_interface.h"
#include "../../BIT_MATH.h"
void (*callback[3])(void) = {NULL, NULL, NULL};

void M_EXTI_voidEnable(u8 id,u8 trigger)
{
	if(id>4 && id<8)
	{
		SETBIT(GICR_REG,id);
	}
	switch(id)
	{
		case 6: //int0
		{
			MCUCR_REG&=(0b11111100);
			MCUCR_REG|=trigger;
			
		}
		case 7://int1
		{
			MCUCR_REG&=0b11110011;
			MCUCR_REG|=trigger<<2;
		}
		case 5://int2
		{
			if (trigger==2)
			{
				CLRBIT(MCUCSR_REG,6);//falling edge
			}
			else
			{
				SETBIT(MCUCSR_REG,6);//rising edge
			}
		}
	}
}
void M_EXTI_voidDisable(void)
{
	CLRBIT(GICR_REG,5);
	CLRBIT(GICR_REG,6);
	CLRBIT(GICR_REG,7);
}
void M_EXTI_voidSetCallback(void (*callback_fn)(void),u8 id)
{
	switch(id)
	{
		case 0://int0
		{
			callback[0]=callback_fn;
		}
		case 1://int1
		{
			callback[1]=callback_fn;
		}
		case 2://int2
		{
			callback[2]=callback_fn;
		}
	}

}
ISR(INT0_vect)
{
	if (callback[0] != NULL)
	{
		callback[0]();
	}
}
ISR(INT1_vect)
{
	if (callback[1] != NULL)
	{
		callback[1]();
	}
}
ISR(INT2_vect)
{
	if (callback[2] != NULL)
	{
		callback[2]();
	}
}
