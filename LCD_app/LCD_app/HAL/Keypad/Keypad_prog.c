#include "util/delay.h"
#include "Keypad_interface.h"
const u8 keypad_matrix[] = {
	'0', '0', '0', '0',
	'8', '9', '0', '0',
	'4', '5', '6', '7',
	'0', '1', '2', '3',
};

const u8 keypad_rows_arr[]={ROW1_PC5,ROW2_PC4,ROW3_PC3,ROW4_PC2};
const u8 keypad_colums_arr[]={COL1_PD7,COL2_PD6,COL3_PD5,COL4_PD3};

void KEYPAD_init(void){
	for (int i=0;i<KEYPAD_ROWS;i++) //keypad rows and columns are equal
	{
		DIO_voidSetPinDirection(PERIPHERAL_C_BASE,keypad_rows_arr[i],1);//rows are output
		DIO_voidSetPinDirection(PERIPHERAL_D_BASE,keypad_colums_arr[i],0);//columns are input
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
			DIO_voidSetPinValue(PERIPHERAL_C_BASE,keypad_rows_arr[i],1);
		}
		//set row of the current index to low
		DIO_voidSetPinValue(PERIPHERAL_C_BASE,keypad_rows_arr[row],0);
		for (u8 col=0;col<KEYPAD_COLUMS;col++)
		{
			// If a key is pressed, return the corresponding value from the matrix
			if (DIO_voidGetPinValue(PERIPHERAL_D_BASE,keypad_colums_arr[col])==0)
			{
				return  keypad_matrix[row * KEYPAD_COLUMS + col];
			}
			
		}
		_delay_ms(KEYPAD_MS);
	}
}

