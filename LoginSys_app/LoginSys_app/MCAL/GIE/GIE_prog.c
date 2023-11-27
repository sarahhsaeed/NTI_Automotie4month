/*
 * GIE_prog.c
 *
 * Created: 10/27/2023 10:18:08 AM
 *  Author: Sarah saeed
 */ 
#include "GIE_interface.h"
#include "../../HAl/LCD/LCD_interface.h"
void enable_GIE()
{
	SETBIT(SREG_BASE,7);	
}
void DISABLE_GIE()
{
	CLRBIT(SREG_BASE,7);
}