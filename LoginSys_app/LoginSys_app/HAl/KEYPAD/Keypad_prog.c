#include "util/delay.h"
#include "Keypad_interface.h"
const u8 keypad_matrix[] = {
	'7', '8', '9', '//',
	'4', '5', '6', '*',
	'1', '2', '3', '-',
	'c', '0', '=', '+',
};

const u8 keypad_rows_arr[]={ROW4_PD0,ROW3_PD1,ROW2_PD2,ROW1_PD3};
const u8 keypad_colums_arr[]={COL4_PD4,COL3_PD5,COL2_PD6,COL1_PD7};

void KEYPAD_init(void){
	for (int i=0;i<KEYPAD_ROWS;i++) //keypad rows and columns are equal
	{
		DIO_voidSetPinDirection(PERIPHERAL_D_BASE,keypad_rows_arr[i],1);//rows are output
		DIO_voidSetPinValue(PERIPHERAL_B_BASE,keypad_colums_arr[i],1); //col are pulledup
		DIO_voidSetPinDirection(PERIPHERAL_B_BASE,keypad_colums_arr[i],0);//columns are input
	}
}

u8 KEYPAD_read(void)
{
	u8 port_value;
	for (u8 row = 0; row < KEYPAD_ROWS; row++)
	{
		//set all pin c values to high
		for(int i=0;i<KEYPAD_ROWS;i++)
		{
			DIO_voidSetPinValue(PERIPHERAL_D_BASE,keypad_rows_arr[i],1);
		}
		//set row of the current index to low
		DIO_voidSetPinValue(PERIPHERAL_D_BASE,keypad_rows_arr[row],0);
		for (u8 col=0;col<KEYPAD_COLUMS;col++)
		{
			// If a key is pressed, return the corresponding value from the matrix
			if (DIO_voidGetPinValue(PERIPHERAL_B_BASE,keypad_colums_arr[col])==0)
			{
				return  keypad_matrix[row * KEYPAD_COLUMS + col];
			}
			
		}
		_delay_ms(KEYPAD_MS);
	}
}

