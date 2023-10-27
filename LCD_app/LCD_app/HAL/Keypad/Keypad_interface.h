#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "Keypad_config.h"
#include "Keypad_private.h"
#include "../../Std_types.h"
#include "../../MCAL/DIO_interface.h"
#include "../../BIT_MATH.h"

void KEYPAD_init(void);
u8 KEYPAD_read(void);

#endif /* KEYPAD_H_ */

