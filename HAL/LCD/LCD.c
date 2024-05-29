#include <stdio.h>

/************************************************ LIB LAYER INCLUDES ************************************************/
#include "../../LIB/tm4c123gh6pm.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
/************************************************ MCAL LAYER INCLUDES ************************************************/
#include "../../MCAL/GPIO/GPIO.h"
#include "../../MCAL/SYSTICK/Systick.h"
/************************************************ HAL LAYER INCLUDES ************************************************/
#include "../LCD/LCD.h"


#include <string.h>
#include <stdint.h>


/*
 * Array of characters that stores the string to be printed on the LCD
 */
 


/* 
 * Description : 
 * Control Port Direction : OUTPUT
 * Data Port Direction : OUTPUT
 * Delay of 1 second 
 * Initializing 8-bit mode
 * Delay of 1 second
 * Clear Command
 * Delay of 1 second
 * Turning cursor of LCD off
 * Delay of 1 second
 * Sending Enty mode set command
 */
void LCD_voidInit()
{
	delay(300);
	LCD_SendCommand(LCD_8_BIT_MODE_CMND);
	delay(1);
	LCD_SendCommand(0x0F);
	delay(2);
	LCD_SendCommand(0x01);
}


/* 
 * Description : 
 * Clears the RS Pin because a command is being sent
 * Clears the RW Pin to write on the LCD
 * Sends the command to the LCD through Data Pins
 * Sets ENABLE Pin high
 * delay of 2 seconds
 * Clears the ENABLE pin so that data is sent at the falling edge
 */
void LCD_SendCommand(char Data_Value)
{
	GPIO_u8SetPinValue(CTRL_PORT, LCD_RS_PIN, PIN_LOW);
	GPIO_u8SetPinValue(CTRL_PORT, LCD_RW_PIN, PIN_LOW);
	//Set_vPortValue(DATA_PORT, Data_Value);
	GPIO_u8SetPinValue (DATA_PORT,	LCD_D0_PIN ,  READ_BIT(Data_Value,0)   );
	GPIO_u8SetPinValue (DATA_PORT,	LCD_D1_PIN ,  READ_BIT(Data_Value,1)   );
	GPIO_u8SetPinValue (DATA_PORT,	LCD_D2_PIN ,  READ_BIT(Data_Value,2)   );
	GPIO_u8SetPinValue (DATA_PORT,	LCD_D3_PIN ,  READ_BIT(Data_Value,3)   );
	GPIO_u8SetPinValue (DATA_PORT,	LCD_D4_PIN ,  READ_BIT(Data_Value,4)   );
	GPIO_u8SetPinValue (DATA_PORT,	LCD_D5_PIN ,  READ_BIT(Data_Value,5)   );
	GPIO_u8SetPinValue (DATA_PORT,	LCD_D6_PIN ,  READ_BIT(Data_Value,6)   );
	GPIO_u8SetPinValue (DATA_PORT,	LCD_D7_PIN ,  READ_BIT(Data_Value,7)   );
	GPIO_u8SetPinValue(CTRL_PORT, LCD_EN_PIN, PIN_HIGH);
	delay(2);
	GPIO_u8SetPinValue(CTRL_PORT, LCD_EN_PIN, PIN_LOW);
	GPIO_PORTF_DATA_R |= 0x02;
}


/* 
 * Description : 
 * Sets the RS Pin because data is being sent
 * Clears the RW Pin to write on the LCD
 * Sends the character to be displayed on the LCD
 * Sets ENABLE Pin high
 * delay of 2 seconds
 * Clears the ENABLE pin so that data is sent at the falling edge
 */
void LCD_voidSendData(char character)
{
	//char flag = 0;
	GPIO_u8SetPinValue(CTRL_PORT, LCD_RS_PIN, PIN_HIGH);
	GPIO_u8SetPinValue(CTRL_PORT, LCD_RW_PIN, PIN_LOW);
	//Set_vPortValue(DATA_PORT, character);
	GPIO_u8SetPinValue (DATA_PORT,	LCD_D0_PIN ,  READ_BIT(character,0)   );
	GPIO_u8SetPinValue (DATA_PORT,	LCD_D1_PIN ,  READ_BIT(character,1)   );
	GPIO_u8SetPinValue (DATA_PORT,	LCD_D2_PIN ,  READ_BIT(character,2)   );
	GPIO_u8SetPinValue (DATA_PORT,	LCD_D3_PIN ,  READ_BIT(character,3)   );
	GPIO_u8SetPinValue (DATA_PORT,	LCD_D4_PIN ,  READ_BIT(character,4)   );
	GPIO_u8SetPinValue (DATA_PORT,	LCD_D5_PIN ,  READ_BIT(character,5)   );
	GPIO_u8SetPinValue (DATA_PORT,	LCD_D6_PIN ,  READ_BIT(character,6)   );
	GPIO_u8SetPinValue (DATA_PORT,	LCD_D7_PIN ,  READ_BIT(character,7)   );
	GPIO_u8SetPinValue(CTRL_PORT, LCD_EN_PIN, PIN_HIGH);
	delay(2);
	GPIO_u8SetPinValue(CTRL_PORT, LCD_EN_PIN, PIN_LOW);
	//flag = (char)GPIO_PORTB_DATA_R;
}


/* 
 * Description : 
 * Sends each character in the string to be printed on the LCD 
 */
void LCD_voidSendString(char *str)
{
	while(*str)
	{
		LCD_voidSendData(*str);
		str++;
	}
}


/* 
 * Description : 
 * Converts the floating distance into a string and stores it in str_distance
 */
void ConvertFloatToStr(f32 distance,char *str)
{
	distance = sprintf(str, "Distance = %f", distance);
}


/* 
 * Description : 
 * Prints to the LCD the distance travelled from the starting point 
 * of the trajectory in the following format : 
 * "Distance = %f"
 */
void Print_Distance_To_LCD(f32 distance)
{
	char str_distance[20]={0};
	ConvertFloatToStr(distance, str_distance);
	LCD_voidSendString(str_distance);
}







