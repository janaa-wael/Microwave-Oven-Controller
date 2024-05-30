#ifndef PUSH_BTN_H
#define PUSH_BTN_H

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO.h"

#define PUSH_BTN_PORT		'A'
#define PUSH_BTN_PIN		3

void PUSHBTN_INIT();
u8 PUSHBTN_u8ButtonPressed();

#endif
