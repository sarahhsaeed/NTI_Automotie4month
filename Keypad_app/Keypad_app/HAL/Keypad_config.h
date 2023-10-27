/*
 * Keypad_config.h
 *
 * Created: 10/25/2023 10:59:28 PM
 *  Author: Sarah saeed
 */ 
#include "avr/io.h"
#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define KEYPAD_ROWS   4
#define KEYPAD_COLUMS 4
#define KEYPAD_MS     1


#define ROW1_PC5 5
#define ROW2_PC4 4
#define ROW3_PC3 3
#define ROW4_PC2 2

#define COL1_PD7 7
#define COL2_PD6 6
#define COL3_PD5 5
#define COL4_PD3 3

#endif /* KEYPAD_CONFIG_H_ */