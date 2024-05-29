#include "../LIB/tm4c123gh6pm.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/GPIO/GPIO.h"
#include "../HAL/PUSH_BTN/PUSH_BTN.h"
#include "../HAL/KEYPAD/KEYPAD.h"

int main()
{
	GPIO_INIT('F');
	GPIO_INIT('A');
	GPIO_INIT('D');
	PUSHBTN_INIT();
	KeyPad_voidKeyPadInit();
	GPIO_u8SetPortDirection('F',PORT_OUTPUT);
	GPIO_u8SetPortDirection('A',PORT_INPUT);
	while(1)
	{
		u8 reading = PUSHBTN_u8ButtonPressed();
		if(reading)
		GPIO_u8SetPortValue('F',0x08);
		else
		GPIO_u8SetPortValue('F',0x04);
	}
	
}
