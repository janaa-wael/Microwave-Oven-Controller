#include "../LIB/tm4c123gh6pm.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/GPIO/GPIO.h"
#include "../MCAL/SYSTICK/SYSTICK.h"
#include "../HAL/PUSH_BTN/PUSH_BTN.h"
#include "../HAL/KEYPAD/KEYPAD.h"
#include "../HAL/LCD/LCD.h"

extern u8 GLOBAL_NUM_CHAR;
u8 LCD_LINE;
int main()
{
	u8 reading;
	u8 x='A';
	GPIO_INIT('F'); //
	//GPIO_INIT('E'); // KEYPAD COLS
	//GPIO_INIT('D'); // KEYPAD ROWS
	GPIO_INIT('B'); // LCD DATA PORT
	GPIO_INIT('A'); // LCD CONTROL PORT
	//KEYPAD_voidInit();
	GPIO_u8SetPortDirection('F',PORT_OUTPUT);
	GPIO_u8SetPortDirection('B',PORT_OUTPUT);
	GPIO_u8SetPortDirection('A',PORT_OUTPUT);
	LCD_voidInit();
	LCD_voidSendString("Initializing");
	delay(200);
	LCD_SendCommand(LCD_CLEAR_CMND);
	LCD_voidSetCursor(1,0);

		while(x<='Z')
		{
			LCD_voidSendData(x);
			x++;
			GLOBAL_NUM_CHAR++;
			while(GLOBAL_NUM_CHAR>15 && GLOBAL_NUM_CHAR<40 && LCD_LINE!=1)
			{
				LCD_voidSendData(' ');
				if(GLOBAL_NUM_CHAR==39)
				{
					LCD_LINE = 1;
				}
				GLOBAL_NUM_CHAR++;
			}
			delay(1000);
}

	
	
}
