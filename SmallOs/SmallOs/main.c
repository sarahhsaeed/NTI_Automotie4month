/*
 * main.c
 *
 * Created: 11/11/2023 2:59:30 PM
 *  Author: Sarah saeed
 */ 
#include "HAL/SmallOs/SmallOs.h"
#define F_CPU 16000000
#include "util/delay.h"

int main(void)
{
	System_init();
    while(1)
    {
		work_on_tasks();
    }
}