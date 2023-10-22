#include "KEYPAD.h"
#include "util/delay.h"
const u8 keypad_matrix[] = {
	'7', '8', '9', '\\',
	'4', '5', '6', '*',
	'1', '2', '3', '-',
	'c', '0', '=', '+'
};

void KEYPAD_init(void){
	//output direction(columns)
	SETBIT(DDRD,3);
	SETBIT(DDRD,5);
	SETBIT(DDRD,6);
	SETBIT(DDRD,7);
	//input direction(rows)
	CLRBIT(DDRC,2);
	CLRBIT(DDRC,3);
	CLRBIT(DDRC,4);
	CLRBIT(DDRC,5);
	//ones on input
	SETBIT(PORTC,2);
	SETBIT(PORTC,3);
	SETBIT(PORTC,4);
	SETBIT(PORTC,5);
	
	
}
u8 KEYPAD_read(void){
	K7D(0); K6D(1); K5D(1); K3D(1);
	if(K5 == 0) return keypad_matrix[0];
	if(K4 == 0) return keypad_matrix[4];
	if(K3 == 0) return keypad_matrix[8];
	if(K2 == 0) return keypad_matrix[12];
	_delay_ms(1);
	
	K7D(1); K6D(0); K5D(1); K3D(1);
	if(K5 == 0) return keypad_matrix[1];
	if(K4 == 0) return keypad_matrix[5];
	if(K3 == 0) return keypad_matrix[9];
	if(K2 == 0) return keypad_matrix[13];
	_delay_ms(1);
	
	K7D(1); K6D(1); K5D(0); K3D(1);
	if(K5 == 0) return keypad_matrix[2];
	if(K4 == 0) return keypad_matrix[6];
	if(K3 == 0) return keypad_matrix[10];
	if(K2 == 0) return keypad_matrix[14];
	_delay_ms(1);
	
	K7D(1); K6D(1); K5D(1); K3D(0);
	if(K5 == 0) return keypad_matrix[3];
	if(K4 == 0) return keypad_matrix[7];
	if(K3 == 0) return keypad_matrix[11];
	if(K2 == 0) return keypad_matrix[15];
	_delay_ms(1);
	return 0;
}

/*

void KEYPAD_init(void) {
	// Set row pins as outputs and column pins as inputs with pull-up resistors
	DDRC |= (1 << PC2) | (1 << PC3) | (1 << PC4) | (1 << PC5);
	PORTC |= (1 << PC2) | (1 << PC3) | (1 << PC4) | (1 << PC5);

	// Set column pins as inputs with pull-up resistors
	DDRD &= ~((1 << PD3) | (1 << PD5) | (1 << PD6) | (1 << PD7));
	PORTD |= (1 << PD3) | (1 << PD5) | (1 << PD6) | (1 << PD7);
}

u8 KEYPAD_read(void) {
	// Scan first row
	PORTC &= ~(1 << PC2);
	PORTC |= (1 << PC3) | (1 << PC4) | (1 << PC5);
	_delay_ms(5);

	if (!(PIND & (1 << PD3))) return keypad_matrix[0];
	if (!(PIND & (1 << PD5))) return keypad_matrix[1];
	if (!(PIND & (1 << PD6))) return keypad_matrix[2];
	if (!(PIND & (1 << PD7))) return keypad_matrix[3];

	// Scan second row
	PORTC &= ~(1 << PC3);
	PORTC |= (1 << PC2) | (1 << PC4) | (1 << PC5);
	_delay_ms(5);

	if (!(PIND & (1 << PD3))) return keypad_matrix[4];
	if (!(PIND & (1 << PD5))) return keypad_matrix[5];
	if (!(PIND & (1 << PD6))) return keypad_matrix[6];
	if (!(PIND & (1 << PD7))) return keypad_matrix[7];

	// Scan third row
	PORTC &= ~(1 << PC4);
	PORTC |= (1 << PC2) | (1 << PC3) | (1 << PC5);
	_delay_ms(5);

	if (!(PIND & (1 << PD3))) return keypad_matrix[8];
	if (!(PIND & (1 << PD5))) return keypad_matrix[9];
	if (!(PIND & (1 << PD6))) return keypad_matrix[10];
	if (!(PIND & (1 << PD7))) return keypad_matrix[11];

	// Scan fourth row
	PORTC &= ~(1 << PC5);
	PORTC |= (1 << PC2) | (1 << PC3) | (1 << PC4);
	_delay_ms(5);

	if (!(PIND & (1 << PD3))) return keypad_matrix[12];
	if (!(PIND & (1 << PD5))) return keypad_matrix[13];
	if (!(PIND & (1 << PD6))) return keypad_matrix[14];
	if (!(PIND & (1 << PD7))) return keypad_matrix[15];

	return 0;
}

*/