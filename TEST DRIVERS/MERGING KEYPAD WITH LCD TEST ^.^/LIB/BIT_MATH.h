#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(reg, bit)	reg |= (1<<bit)
#define CLR_BIT(reg, bit) reg &= (~(1<<bit))
#define TOG_BIT(reg, bit) reg ^= (1<<bit)
#define READ_BIT(reg, bit) (reg & (1<<bit))>>bit

#endif
