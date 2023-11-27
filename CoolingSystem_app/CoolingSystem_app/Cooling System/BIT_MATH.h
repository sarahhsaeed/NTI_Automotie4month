/*
 * BIT_MATH.h
 *
 * Created: 10/25/2023 4:05:10 PM
 *  Author: Sarah saeed
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SETBIT(REG,BIT)   (REG |= 1<<BIT)
#define CLRBIT(REG,BIT)   (REG &= ~(1<<BIT))
#define TOGBIT(REG,BIT)	  (REG ^= 1<<BIT)
#define READBIT(REG,BIT)  ((REG >> BIT) & 1)



#endif /* BIT_MATH_H_ */