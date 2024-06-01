#ifndef KEYPAD_H
#define KEYPAD_H


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/GPIO/GPIO.h"

/* NUMBER OF ROWS AND COLUMNS */
#define KEYPAD_ROW_PORT				'D'
#define KEYPAD_COL_PORT				'E'
#define KEYPAD_SPARE_ROW_PORT	'F'

/* PORT CONFIGURATIONS */
#define KEYPAD_R0_PIN			0
#define KEYPAD_R1_PIN			1
#define KEYPAD_R2_PIN			2	
#define KEYPAD_R3_PIN			3

#define KEYPAD_C0_PIN			0
#define KEYPAD_C1_PIN			1
#define KEYPAD_C2_PIN			2
#define KEYPAD_C3_PIN			3

#define	COL_INIT					0
#define COL_FINAL					3
#define ROW_INIT					0
#define ROW_FINAL					3

#define KEYPAD_NUM_ROWS 	4
#define KEYPAD_NUM_COLS		4

#define KEYPAD_BUTTON_PRESSED		PIN_LOW
#define KEYPAD_BUTTON_RELEASED	PIN_HIGH

#define KPD_VALUES     {{'1','2','3','A'},\
	                     {'4','5','6','B'},\
											 {'7','8','9','C'},\
											 {'+','0','=','D'}}	

void KEYPAD_voidInit(void);										 
u8 KEYPAD_READ(void);
											

#endif
