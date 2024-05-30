#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/GPIO/GPIO.h"
#include "../../MCAL/SYSTICK/SYSTICK.h"
#include "KEYPAD.h"

const u8 KEYPAD [4][4]=
{
	{'1','2','3','A'},
	{'4','5','6','B'},
	{'7','8','9','C'},
	{'*','0','#','D'}
};

void KEYPAD_voidInit(void)
{
	/*Set the Raw port as input with PORT=1 to activate the internal pull up */
	GPIO_u8SetPortDirection(KEYPAD_ROW_PORT,PORT_INPUT);
	GPIO_u8SetPortValue(KEYPAD_ROW_PORT,0x0F);
	/*Set the COL port as output with Initial value =LOGIC HIGH*/ 
    GPIO_u8SetPortDirection(KEYPAD_COL_PORT,PORT_OUTPUT);
    GPIO_u8SetPortValue(KEYPAD_COL_PORT,0xFF);
}

u8 KEYPAD_READ(void) {
		u8 row = 0;
		u8 col = 0;
    for (col = 0; col < 4; col++) {
        // Drive the current column low
        GPIO_u8SetPinValue(KEYPAD_COL_PORT, col, 0);

        for (row = 0; row < 4; row++) {
            u8 val;
            GPIO_u8GetPinValue(KEYPAD_ROW_PORT, row, &val);
            if (val == 0) {
                // Debounce
                delay(10);  // Assuming you have a delay function
                GPIO_u8GetPinValue(KEYPAD_ROW_PORT, row, &val);
                if (val == 0) {
                    // Wait until the key is released
                    while (val == 0) {
                        GPIO_u8GetPinValue(KEYPAD_ROW_PORT, row, &val);
                    }
                    GPIO_u8SetPinValue(KEYPAD_COL_PORT, col, 1); // Reset the column
                    return KEYPAD[row][col];  // Return the corresponding character from the keymap
                }
            }
        }

        // Reset the column back high
        GPIO_u8SetPinValue(KEYPAD_COL_PORT, col, 1);
    }
    return 0xFF;  // Indicate no key press
}
/*
u8 KEYPAD_READ(void)
{
	u8 LOC_ROW = 0;
	u8 LOC_COL = 0;
	u8 temp = 0, Val = 0xFF;
	for(LOC_COL = 0; LOC_COL <= 3; LOC_COL++)
	{
		GPIO_u8SetPinValue(KEYPAD_COL_PORT, LOC_COL, PIN_LOW);
		for(LOC_ROW = 0; LOC_ROW <= 3; LOC_ROW++)
		{
			GPIO_u8GetPinValue(KEYPAD_ROW_PORT, LOC_ROW, &temp);
			if(!temp)
			{
				Val = KEYPAD[LOC_ROW][LOC_COL];
				while (!temp)
				{
					GPIO_u8GetPinValue(KEYPAD_ROW_PORT, LOC_ROW, &temp);
				}
				delay(10);
				GPIO_u8SetPinValue(KEYPAD_COL_PORT, LOC_COL, PIN_HIGH);
				return Val;
			}
		GPIO_u8SetPinValue(KEYPAD_COL_PORT, LOC_COL, PIN_HIGH);

		}
	}

}*/