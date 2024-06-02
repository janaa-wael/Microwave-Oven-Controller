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

u8 kpd_input;
u8 kpd_time[4];
u8 i,j;
int main()
{
	u8 reading;
	u8 counter=0;
	GPIO_INIT('F'); //
	GPIO_INIT('E'); // KEYPAD COLS
	GPIO_INIT('D'); // KEYPAD ROWS
	GPIO_INIT('B'); // LCD DATA PORT
	GPIO_INIT('A'); // LCD CONTROL PORT

	GPIO_u8SetPortDirection('F',PORT_INPUT);
	GPIO_u8SetPortDirection('B',PORT_OUTPUT);
	GPIO_u8SetPortDirection('A',PORT_OUTPUT);

	LCD_voidInit();
	LCD_voidSendString("Initializing");
	delay_sec(5);
	KEYPAD_voidInit();
	
	while(1)
	{
		kpd_input = 0xFF;
		LCD_voidClearScreen();
		LCD_voidSetCursor(0,0);
		LCD_voidSendString("Enter ur choice:");
		while(kpd_input == 0xFF)
			kpd_input = KEYPAD_READ();
		LCD_voidSetCursor(1,0);
		LCD_voidSendData(kpd_input);
		delay_sec(5);
		LCD_voidClearScreen();
	
		switch(kpd_input)
		{
			case 'A' :
				kpd_input = 0xFF;
				LCD_voidSetCursor(0,0);
				LCD_voidSendString("Popcorn");
				delay_sec(5);
				LCD_voidCountDown(60);
				break;
			case 'B' :
				kpd_input = 0xFF;
				LCD_voidSetCursor(0,0);
				LCD_voidSendString("Beef");
				delay_sec(5);
				do
				{
					kpd_input = 0xFF;
					LCD_voidClearScreen();
					LCD_voidSetCursor(0,0);
					LCD_voidSendString("Beef Weight?");
					LCD_voidSetCursor(1,0);
					while(kpd_input==0xFF)
						kpd_input = KEYPAD_READ();
					if(!(kpd_input>='0' && kpd_input<='9'))
					{
						LCD_voidClearScreen();
						LCD_voidSetCursor(0,0);
						LCD_voidSendString("Error!");
						delay_sec(2);
					}
				}while(!(kpd_input>='0' && kpd_input<='9'));
				LCD_voidSetCursor(1,0);
				LCD_voidSendData(kpd_input);
				delay_sec(5);
				LCD_voidCountDown(30*(kpd_input&0x0F));
				delay_sec(5);
				break;
			case 'C' : 
				kpd_input = 0xFF;
				LCD_voidSetCursor(0,0);
				LCD_voidSendString("Chicken");
				delay_sec(5);
				do
				{
					kpd_input = 0xFF;
					LCD_voidClearScreen();
					LCD_voidSetCursor(0,0);
					LCD_voidSendString("Chicken Weight?");
					LCD_voidSetCursor(1,4);
					while(kpd_input == 0xFF)
						kpd_input = KEYPAD_READ();
					if(!(kpd_input>='0' && kpd_input<='9'))
					{
						LCD_voidClearScreen();
						LCD_voidSendString("Error!");
						delay_sec(2);
					}
				}while(!(kpd_input>='0' && kpd_input<='9'));
				LCD_voidSendString("  ");
				LCD_voidSendData(kpd_input);
				delay_sec(5);
				LCD_voidCountDown(12*(kpd_input&0x0F));
				break;
			case 'D' :
				kpd_input = 0xFF;
				LCD_voidSetCursor(0,0);
				LCD_voidSendString("Cooking Time");
				LCD_voidSetCursor(1,5);
				LCD_voidSendString("00:00");
			
				for( i = 0 ; i < 4 ; i++)
				{
					kpd_input = 0xFF;
					while(kpd_input == 0xFF)
						kpd_input = KEYPAD_READ();
					kpd_time[i] = kpd_input;
					if(i>1)
							LCD_voidSetCursor(1,8-i);
					else
						LCD_voidSetCursor(1,9-i);
					for( j = 0 ; j <= i ; j++)
					{
						LCD_voidSendData(kpd_time[j]);
						if((j==1&& i==3)||(j==0 && i==2)) LCD_voidSendData(':');
					}
				}
				delay_sec(10);
				/*kpd_input = 0xFF;				
				while(kpd_input == 0xFF)
					kpd_input = KEYPAD_READ();
				LCD_voidSetCursor(1,5);
				LCD_voidSendData(kpd_input);
				break;*/
		}
	}

	
}

