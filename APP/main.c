#include "../LIB/tm4c123gh6pm.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/GPIO/GPIO.h"
#include "../MCAL/SYSTICK/SYSTICK.h"
#include "../HAL/PUSH_BTN/PUSH_BTN.h"
#include "../HAL/KEYPAD/KEYPAD.h"

int main()
{

	GPIO_INIT('F'); //
	GPIO_INIT('E'); // KEYPAD COLS
	GPIO_INIT('D'); // KEYPAD ROWS
	KEYPAD_voidInit();
	GPIO_u8SetPortDirection('F',PORT_OUTPUT);
	while(1)
	{
		u8 reading = KEYPAD_READ();
		//u8 reading2 = PUSHBTN_u8ButtonPressed();
		
		if(reading == 0)
			GPIO_u8SetPortValue('F',0x00);		
		else if(reading == '1' || reading == '2' || reading == '3' || reading == 'A')
			GPIO_u8SetPortValue('F',0x02); //RED
		else if(reading == '4' || reading == '5' || reading == '6' || reading == 'B')
			GPIO_u8SetPortValue('F',0x04); //BLUE
		else if(reading == '7' || reading == '8' || reading == '9' || reading == 'C')
			GPIO_u8SetPortValue('F',0x08); //GREEN
		else if(reading == '*' || reading == '0' || reading == '#' || reading == 'D')
			GPIO_u8SetPortValue('F',0x0C); //CYAN

	delay(700);
			GPIO_u8SetPortValue('F',0x00);		
/*	if(reading2==0)
	{
			GPIO_u8SetPortValue('F',0x06);			
	}
	else
	{
			GPIO_u8SetPortValue('F',0x08);			
	}*/
}

	
	
}
