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
	GPIO_u8SetPortDirection(KEYPAD_SPARE_ROW_PORT,0x00);
	GPIO_u8SetPortValue(KEYPAD_ROW_PORT,0x11);
	/*Set the COL port as output with Initial value =LOGIC HIGH*/ 
    GPIO_u8SetPortDirection(KEYPAD_COL_PORT,15);
    GPIO_u8SetPortValue(KEYPAD_COL_PORT,0xFF);
}

u8 KEYPAD_READ(void) {
		u8 row = 0;
		u8 col = 0;
    GPIO_u8SetPortValue(KEYPAD_COL_PORT,0xFF);
		GPIO_u8SetPortValue(KEYPAD_SPARE_ROW_PORT,0x11);
    GPIO_u8SetPortValue(KEYPAD_ROW_PORT,0x0F);
    for (col = 0; col < 4; col++) {
        // Drive the current column low
        GPIO_u8SetPinValue(KEYPAD_COL_PORT, col, 0);

        for (row = 0; row < 4; row++) {
            u8 val;
							if(row==2 || row == 3)
                GPIO_u8GetPinValue(KEYPAD_ROW_PORT, row, &val);
							else if(row == 0)
                GPIO_u8GetPinValue(KEYPAD_SPARE_ROW_PORT, 0, &val);
							else
								GPIO_u8GetPinValue(KEYPAD_SPARE_ROW_PORT, 4, &val);
							
            if (val == 0) {
                // Debounce
                delay(10);  // Assuming you have a delay function
							if(row==2 || row == 3)
                GPIO_u8GetPinValue(KEYPAD_ROW_PORT, row, &val);\
							else if(row == 0)
                GPIO_u8GetPinValue(KEYPAD_SPARE_ROW_PORT, 0, &val);
							else
								GPIO_u8GetPinValue(KEYPAD_SPARE_ROW_PORT, 4, &val);
								
                if (val == 0) {
                    // Wait until the key is released
                    while (val == 0) {
                        if(row==2 || row == 3)
													GPIO_u8GetPinValue(KEYPAD_ROW_PORT, row, &val);
												else if(row == 0)
													GPIO_u8GetPinValue(KEYPAD_SPARE_ROW_PORT, 0, &val);
												else
													GPIO_u8GetPinValue(KEYPAD_SPARE_ROW_PORT, 4, &val);
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
	//Define the row and col variables that will check which button pressed
	u8 u8RowLocal=0,u8ColLocal=0;
	//Define the row and col arrays that will include the keypad pins 
	u8 KPD_u8RwoPinArr[KEYPAD_NUM_ROWS] = {KEYPAD_R0_PIN,KEYPAD_R1_PIN,KEYPAD_R2_PIN,KEYPAD_R3_PIN};
	u8 KPD_u8ColPinArr[KEYPAD_NUM_COLS] = {KEYPAD_C0_PIN,KEYPAD_C1_PIN,KEYPAD_C2_PIN,KEYPAD_C3_PIN};
	
	for(u8ColLocal=0;u8ColLocal<KEYPAD_NUM_COLS;u8ColLocal++)
	{
		//To activate one column at a time -> col_pin =0
		GPIO_u8SetPinValue(KEYPAD_COL_PORT,KPD_u8ColPinArr[u8ColLocal],PIN_LOW);
		for(u8RowLocal=0;u8RowLocal<KEYPAD_NUM_ROWS;u8RowLocal++)
		{
			u8 u8Value;
			GPIO_u8GetPinValue(KEYPAD_ROW_PORT,KPD_u8RwoPinArr[u8RowLocal],&u8Value);
			if (u8Value == KEYPAD_BUTTON_PRESSED)
			{
				//delay and second check for switch debouncing
				delay(30);
				if (u8Value == KEYPAD_BUTTON_PRESSED)
				{
					while(u8Value == KEYPAD_BUTTON_PRESSED)
					{
						GPIO_u8GetPinValue(KEYPAD_ROW_PORT,KPD_u8RwoPinArr[u8RowLocal],&u8Value);
					}
					return KEYPAD[u8RowLocal][u8ColLocal];
				}
			}
		}
		//there is no button pressed
		GPIO_u8SetPinValue(KEYPAD_COL_PORT,KPD_u8ColPinArr[u8ColLocal],PIN_HIGH);
	}
	return KEYPAD_BUTTON_RELEASED;
} */