#include "../LIB/tm4c123gh6pm.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/GPIO/GPIO.h"
#include "../MCAL/SYSTICK/SYSTICK.h"
#include "../HAL/PUSH_BTN/PUSH_BTN.h"
#include "../HAL/KEYPAD/KEYPAD.h"
#include "../HAL/LCD/LCD.h"
#include <stdio.h>
#include <stdlib.h>


extern u8 GLOBAL_NUM_CHAR;
u8 LCD_LINE;
u8 str1[5];
u8 str2[5];

u8 arr[16] = {'1','2','3','4','5','6','7','8','9','A','B','C','D','*','#','\0'};
u32 x = (u32)993;
f64 y = 10.01;
f64 z = 9.1;

int main()
{
	u8 reading;
	u8 counter=0;
	GPIO_INIT('F'); //
	//GPIO_INIT('E'); // KEYPAD COLS
	GPIO_INIT('D'); // KEYPAD ROWS
	GPIO_INIT('B'); // LCD DATA PORT
	GPIO_INIT('A'); // LCD CONTROL PORT
	//KEYPAD_voidInit();
	//GPIO_u8SetPortDirection('F',PORT_OUTPUT);
	GPIO_u8SetPortDirection('B',PORT_OUTPUT);
	GPIO_u8SetPortDirection('A',PORT_OUTPUT);
	LCD_voidInit();
	LCD_voidSendString("Initializing");
	delay(2000);

		while(1)
		{
			if(x>2000)
				break;
			LCD_voidClearScreen();
			LCD_voidSendString("  Reading = ");
			sprintf(str1,"%f",y);
			LCD_voidSendString(str1);
			GLOBAL_NUM_CHAR++;
			LCD_voidJumpTo2ndLine();
			LCD_voidSendString("Reading = ");
			sprintf(str2,"%f",z);
			LCD_voidSendString(str2);
			if(READ_BIT(GPIO_PORTF_DATA_R,1)==1) 
			{
				y += 0.01;
				z += 0.1;
			}
			delay(2000);
		}

	
	
}
