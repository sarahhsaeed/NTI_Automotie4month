/*
 * main.c
 *
 * Created: 11/9/2023 9:48:41 AM
 *  Author: Sarah saeed
 */ 
#include "HAL/Longin_sys/LoginSys.h"
#include "util/delay.h"
int main(void)
{
	SysInit();
	while(1)
	{
		login();
		
	}

}
