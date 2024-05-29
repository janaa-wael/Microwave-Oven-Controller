
#ifndef LCD_H
#define LCD_H

#include "../../MCAL/GPIO/GPIO.h"
#include "../../LIB/STD_TYPES.h"

#define LCD_INITIALIZATION_8_BIT_MODE			8


/*************************************** CONTROL PINS MACROS ***************************************/
#define CTRL_PORT					'E'	
#define CTRL_PORT_DIR				0x07
#define LCD_RS_PIN					1
#define LCD_RW_PIN					2
#define LCD_EN_PIN					3
/*************************************** DATA PINS MACROS ******************************************/
#define DATA_PORT					'B'
#define DATA_PORT_DIR				0xFF
#define LCD_D0_PIN					0
#define LCD_D1_PIN					1
#define LCD_D2_PIN					2
#define LCD_D3_PIN					3
#define LCD_D4_PIN					4
#define LCD_D5_PIN					5
#define LCD_D6_PIN					6
#define LCD_D7_PIN					7
/************************************** LCD COMMANDS MACROS *****************************************/
#define LCD_8_BIT_MODE_CMND 			0x38
#define LCD_CLEAR_CMND					0x01
#define LCD_CURSOR_OFF_CMND				0x0C
#define LCD_ENTRY_MODE_SET_CMND		0x06
/*********************************** LCD FUNCTIONS PROTOTYPES **************************************/
void LCD_voidInit(void);
void LCD_voidSendData(char character);
void LCD_voidSendString(char *str);
void LCD_SendCommand(char Data_Value);

void ConvertFloatToStr(f32 distance, char *str);
void Print_Distance_To_LCD(f32 distance);





#endif
