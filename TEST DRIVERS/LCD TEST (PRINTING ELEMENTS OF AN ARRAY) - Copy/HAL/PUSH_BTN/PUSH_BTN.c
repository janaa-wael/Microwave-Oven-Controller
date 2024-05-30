#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO.h"
#include "PUSH_BTN.h"

void PUSHBTN_INIT()
{
	GPIO_u8SetPinDirection(PUSH_BTN_PORT,PUSH_BTN_PIN,PIN_INPUT);
}

u8 PUSHBTN_u8ButtonPressed()
{
	return READ_BIT(GPIO_PORTA_DATA_R,PUSH_BTN_PIN);
}
