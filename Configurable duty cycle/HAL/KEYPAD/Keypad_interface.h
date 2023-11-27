#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "Keypad_config.h"
#include "Keypad_private.h"
#include "../../Std_types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../BIT_MATH.h"

#define KEYPAD_ROWS   4
#define KEYPAD_COLUMS 4
#define KEYPAD_MS     1


#define ROW1_PD3 3
#define ROW2_PD2 2
#define ROW3_PD1 1
#define ROW4_PD0 0

#define COL1_PD7 7
#define COL2_PD6 6
#define COL3_PD5 5
#define COL4_PD4 4

void KEYPAD_init(void);
u8 KEYPAD_read(void);

#endif /* KEYPAD_H_ */

