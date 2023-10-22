#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "Std_types.h"
#include "avr/io.h"
#include "DIO_private.h"
#define SETBIT(REG,BIT) (REG |= 1<<BIT)
#define CLRBIT(REG,BIT) (REG &= ~(1<<BIT))
#define TOGBIT(REG,BIT) (REG ^= 1<<BIT)
#define READBIT(REG,BIT)  ((REG >> BIT) & 1)

#define K2 READBIT(PINC,2)
#define K3 READBIT(PINC,3)
#define K4 READBIT(PINC,4)
#define K5 READBIT(PINC,5)
#define K3D(x) if(x == 1) SETBIT(PORTD,3); else CLRBIT(PORTD,3);
#define K5D(x) if(x == 1) SETBIT(PORTD,5); else CLRBIT(PORTD,5);
#define K6D(x) if(x == 1) SETBIT(PORTD,6); else CLRBIT(PORTD,6);
#define K7D(x) if(x == 1) SETBIT(PORTD,7); else CLRBIT(PORTD,7);

void KEYPAD_init(void);
u8 KEYPAD_read(void);

#endif /* KEYPAD_H_ */

