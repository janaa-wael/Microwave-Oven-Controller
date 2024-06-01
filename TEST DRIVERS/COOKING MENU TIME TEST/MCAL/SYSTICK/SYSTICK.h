#ifndef SYSTICK_H
#define SYSTICK_H

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/tm4c123gh6pm.h"

void Systick_Init(void);
void Systick_Wait(u32 d);
void delay (u32 del);
void delay_sec(u32 del);

#endif
