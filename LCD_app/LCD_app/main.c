/*
 * main.c
 *
 * Created: 10/23/2023 11:09:58 AM
 *  Author: Sarah saeed
 */ 

#include <xc.h>
#include "HAL/LCD_interface.h"
#include "hal/Keypad/Keypad_interface.h"
#include "util/delay.h"
typedef struct 
{
	u8 name[20];
	u16 id;
	u16 password;

}User;
int main(void)
{
	H_LCD_void_Init(); 
	KEYPAD_init();
	u8 id_arr[4]={0};
	u8 pass_arr[4]={0};
	u16 id_value=0,pass_value=0;
	u8 counter=0;
	User user1,user2;
	//user1 data
	user1.id=2322;
	user1.password=1234;
	strcpy(user1.name, "Sarah");
	//user2 data
	user2.id=1792;
	user2.password=5678;
	strcpy(user2.name, "Taho");
    while(1)
	{
		H_LCD_void_sendCommand(0x80);
		H_LCD_void_sendString("enter your id");
		_delay_ms(10000);
		H_LCD_void_sendCommand(0x01);
		//loop for the id
		while(1)
		{

			if( KEYPAD_read() !=0){
				id_arr[counter] = KEYPAD_read()-48;
				H_LCD_void_sendIntNum(id_arr[counter]);
				_delay_ms(10);
				while(id_arr[counter] == KEYPAD_read()-48);
				//_delay_ms(1);
				counter++;
				if (counter==4)
				{
					id_value=id_arr[0]*1000+id_arr[1]*100+id_arr[2]*10+id_arr[3]; 
					counter=0;
					break;
				}
			}
			
		}
		H_LCD_void_sendCommand(0x80);
		H_LCD_void_sendString("enter password");
		_delay_ms(4000);
		H_LCD_void_sendCommand(0x01);
		//loop for password
		while(1)
		{
			if( KEYPAD_read() !=0){
				pass_arr[counter] = KEYPAD_read()-48;
				H_LCD_void_sendIntNum(pass_arr[counter]);
				_delay_ms(10);
				while(pass_arr[counter] == KEYPAD_read()-48);
				//_delay_ms(1);
				counter++;
				if (counter==4)
				{
					pass_value=pass_arr[0]*1000+pass_arr[1]*100+pass_arr[2]*10+pass_arr[3];
					counter=0;
					break;
				}
			}
			
		}
		if (id_value==user1.id)
		{
			if (pass_value==user1.password)
			{
				H_LCD_void_sendCommand(0x80);
				H_LCD_void_sendString("welcome, ");
				H_LCD_void_sendString(user1.name);
				_delay_ms(10000);
			}	
		}
		else if (id_value==user2.id)
		{
			if (pass_value==user2.password)	
			{
				H_LCD_void_sendCommand(0x80);
				H_LCD_void_sendString("welcome, ");
				H_LCD_void_sendString(user2.name);
				_delay_ms(10000);
				
			}
		}
		else
		{
			H_LCD_void_sendCommand(0x80);
			H_LCD_void_sendString("try again");
			_delay_ms(10000);
			
		}
	}
	
		
		  

}
//H_LCD_void_sendCommand(0x80);
//H_LCD_void_sendString("id is ");
//H_LCD_void_sendIntNum(id_value);
//H_LCD_void_sendString(" pass is ");
//H_LCD_void_sendIntNum(pass_value);