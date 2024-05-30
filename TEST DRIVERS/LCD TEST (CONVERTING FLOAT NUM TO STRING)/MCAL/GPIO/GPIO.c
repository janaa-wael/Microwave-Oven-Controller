#include "../../LIB/STD_TYPES.h"
#include "../../LIB/tm4c123gh6pm.h"
#include "../../LIB/BIT_MATH.h"
#include "GPIO.h"

u8 GPIO_INIT(u8 Copy_u8PortName)
{
	u8 ERROR_STATUS = 0 ;
	if(Copy_u8PortName >= 'A' && Copy_u8PortName<= 'F')
	{
		switch(Copy_u8PortName)
		{
			
			case 'A': 
				SET_BIT(SYSCTL_RCGCGPIO_R,0);
				while(!READ_BIT(SYSCTL_PRGPIO_R,0));
				GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
				GPIO_PORTF_CR_R = GPIO_CR_VALUE;
				GPIO_PORTA_AFSEL_R = 0x00;
				GPIO_PORTA_AMSEL_R = 0x00;
				GPIO_PORTA_PCTL_R = 0x00;
				GPIO_PORTA_DEN_R = 0xFF;
								GPIO_PORTA_DATA_R = 0x00;

				break;
				
			case 'B':
				SET_BIT(SYSCTL_RCGCGPIO_R,1);
				while(!READ_BIT(SYSCTL_PRGPIO_R,1));
				GPIO_PORTB_LOCK_R = GPIO_LOCK_KEY;
				GPIO_PORTB_CR_R = GPIO_CR_VALUE;
				GPIO_PORTB_AFSEL_R = 0x00;
				GPIO_PORTB_AMSEL_R = 0x00;
				GPIO_PORTB_PCTL_R = 0x00;
				GPIO_PORTB_DEN_R = 0xFF;
							GPIO_PORTB_DATA_R = 0x00;

				break;
			
			case 'C':
				SET_BIT(SYSCTL_RCGCGPIO_R,2);
				while(!READ_BIT(SYSCTL_PRGPIO_R,2));
				GPIO_PORTC_LOCK_R = GPIO_LOCK_KEY;
				GPIO_PORTC_CR_R = GPIO_CR_VALUE;
				GPIO_PORTA_AFSEL_R = 0x00;
				GPIO_PORTA_AMSEL_R = 0x00;
				GPIO_PORTA_PCTL_R = 0x00;
				GPIO_PORTA_DEN_R = 0xFF;
							GPIO_PORTA_DATA_R = 0x00;

				break;
				
			
			case 'D':
				SET_BIT(SYSCTL_RCGCGPIO_R,3);
				while(!READ_BIT(SYSCTL_PRGPIO_R,3));
				GPIO_PORTD_LOCK_R = GPIO_LOCK_KEY;
				GPIO_PORTD_CR_R = GPIO_CR_VALUE;
				GPIO_PORTD_AFSEL_R = 0x00;
				GPIO_PORTD_AMSEL_R = 0x00;
				GPIO_PORTD_PCTL_R &= ~0x0000F000;
				GPIO_PORTD_PUR_R = 0x0F;
				GPIO_PORTD_DEN_R = 0xFF;
							GPIO_PORTD_DATA_R = 0x00;

				break;
				
			case 'E':
				SET_BIT(SYSCTL_RCGCGPIO_R,4);
				while(!READ_BIT(SYSCTL_PRGPIO_R,4));
				GPIO_PORTE_LOCK_R = GPIO_LOCK_KEY;
				GPIO_PORTE_CR_R = GPIO_CR_VALUE;
				GPIO_PORTE_AFSEL_R &= ~0xFF;
				GPIO_PORTE_AMSEL_R &= ~0xFF;
				GPIO_PORTE_PCTL_R &= ~0x000F0000;
				GPIO_PORTE_DEN_R = 0xFF;
							GPIO_PORTE_DATA_R = 0x00;

				break;
				
			case 'F':
				SET_BIT(SYSCTL_RCGCGPIO_R,5);
				while(!READ_BIT(SYSCTL_PRGPIO_R,5));
				GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
				GPIO_PORTF_CR_R = GPIO_CR_VALUE;

				GPIO_PORTF_AFSEL_R = 0x00;
				GPIO_PORTF_AMSEL_R = 0x00;
				GPIO_PORTF_PCTL_R = 0x00;
				GPIO_PORTF_DEN_R = 0xFF;
				GPIO_PORTF_DATA_R = 0x00;
				GPIO_PORTF_DIR_R = 0x0E;
				break;
			
			default : 
				ERROR_STATUS = 1;
			
		}
	}
	else
		ERROR_STATUS = 1;
	return ERROR_STATUS;
	
}

u8 GPIO_u8SetPortDirection(u8 Copy_u8PortName, u8 Copy_u8PortDir)
{
	u8 ERROR_STATUS = 0;
	if(Copy_u8PortName >= 'A' && Copy_u8PortName <= 'F' && (Copy_u8PortDir == PORT_OUTPUT || Copy_u8PortDir == PORT_INPUT))
	{
		switch(Copy_u8PortName)
		{
			case 'A': 
				if(Copy_u8PortDir == PIN_LOW)
					GPIO_PORTA_DIR_R = PORT_INPUT;
				else
					GPIO_PORTA_DIR_R = PORT_OUTPUT;
					break;
			
			case 'B': 
				if(Copy_u8PortDir == PIN_LOW)
					GPIO_PORTB_DIR_R = PORT_INPUT;
				else
					GPIO_PORTB_DIR_R = PORT_OUTPUT;
	  			break;
				
			case 'C': 
				if(Copy_u8PortDir == PIN_LOW)
					GPIO_PORTC_DIR_R = PORT_INPUT;
				else
					GPIO_PORTC_DIR_R = PORT_OUTPUT;
	  			break;	
			
			case 'D': 
				if(Copy_u8PortDir == PIN_LOW)
					GPIO_PORTD_DIR_R = PORT_INPUT;
				else
					GPIO_PORTD_DIR_R = PORT_OUTPUT;
	  			break;
			
			case 'E': 
				if(Copy_u8PortDir == PIN_LOW)
					GPIO_PORTE_DIR_R = PORT_INPUT;
				else
					GPIO_PORTE_DIR_R = PORT_OUTPUT;
	  			break;
				
			case 'F': 
				if(Copy_u8PortDir == PIN_LOW)
					GPIO_PORTF_DIR_R = PORT_INPUT;
				else
					GPIO_PORTF_DIR_R = PORT_OUTPUT;
	  	  break;
				
			default :
					ERROR_STATUS = 1;
		}
	}
	else
	{
			ERROR_STATUS = 1;
	}
	return ERROR_STATUS;
	
}

u8 GPIO_u8SetPinDirection(u8 Copy_u8PortName, u8 Copy_u8PinId , u8 Copy_u8PinDir)
{
	u8 ERROR_STATUS = 0;
	if(Copy_u8PortName >= 'A' && Copy_u8PortName <= 'F' && (Copy_u8PinId>=0 && Copy_u8PinId <= 7) && (Copy_u8PinDir == PIN_INPUT || Copy_u8PinDir == PIN_OUTPUT))
	{
		switch(Copy_u8PortName)
		{
			case 'A' :
				if(Copy_u8PinDir == PIN_OUTPUT)
					SET_BIT(GPIO_PORTA_DIR_R,Copy_u8PinId);
				else
					CLR_BIT(GPIO_PORTA_DIR_R,Copy_u8PinId);
			break;
			case 'B' :
					if(Copy_u8PinDir == PIN_OUTPUT)
					SET_BIT(GPIO_PORTB_DIR_R,Copy_u8PinId);
				else
					CLR_BIT(GPIO_PORTB_DIR_R,Copy_u8PinId);
			break;
			
			case 'C' :
					if(Copy_u8PinDir == PIN_OUTPUT)
					SET_BIT(GPIO_PORTC_DIR_R,Copy_u8PinId);
				else
					CLR_BIT(GPIO_PORTC_DIR_R,Copy_u8PinId);
			break;
			
			case 'D' :
					if(Copy_u8PinDir == PIN_OUTPUT)
					SET_BIT(GPIO_PORTD_DIR_R,Copy_u8PinId);
				else
					CLR_BIT(GPIO_PORTD_DIR_R,Copy_u8PinId);
			break;
			
			case 'E' :
					if(Copy_u8PinDir == PIN_OUTPUT)
					SET_BIT(GPIO_PORTE_DIR_R,Copy_u8PinId);
				else
					CLR_BIT(GPIO_PORTE_DIR_R,Copy_u8PinId);
			break;
			
			case 'F' :
					if(Copy_u8PinDir == PIN_OUTPUT)
					SET_BIT(GPIO_PORTF_DIR_R,Copy_u8PinId);
				else
					CLR_BIT(GPIO_PORTF_DIR_R,Copy_u8PinId);
			break;
			
			default :
				ERROR_STATUS = 1;
			
		}
	}
	else 
		ERROR_STATUS = 1;
	return ERROR_STATUS;
}


u8 GPIO_u8SetPortValue(u8 Copy_u8PortName, u8 Copy_u8PortValue)
{
	u8 ERROR_STATUS = 0;
	if(Copy_u8PortName >= 'A' && Copy_u8PortName <= 'F' && (Copy_u8PortValue >= 0 || Copy_u8PortValue <= 255))
	{
			switch(Copy_u8PortName)
			{
				case 'A' : 
					GPIO_PORTA_DATA_R = Copy_u8PortValue;
					break;
				
				case 'B' : 
					GPIO_PORTB_DATA_R = Copy_u8PortValue;
					break;
				
				case 'C' : 
					GPIO_PORTC_DATA_R = Copy_u8PortValue;
					break;
				
				case 'D' : 
					GPIO_PORTD_DATA_R = Copy_u8PortValue;
					break;
				
				case 'E' : 
					GPIO_PORTE_DATA_R = Copy_u8PortValue;
					break;
				
				case 'F' : 
					GPIO_PORTF_DATA_R = Copy_u8PortValue;
					break;
				
				default :
					ERROR_STATUS = 1;
			}
	}
	else
		ERROR_STATUS = 1;
	return ERROR_STATUS;
}

u8 GPIO_u8SetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinId, u8 Copy_u8PinValue)
{
	u8 ERROR_STATUS = 0;
	if(Copy_u8PortName >= 'A' && Copy_u8PortName <= 'F' && (Copy_u8PinId>=0 && Copy_u8PinId <=7) && (Copy_u8PinValue == PIN_LOW || Copy_u8PinValue == PIN_HIGH))
	{
			switch(Copy_u8PortName)
			{
				case 'A' : 
					if(Copy_u8PinValue == PIN_HIGH)
						SET_BIT(GPIO_PORTA_DATA_R,Copy_u8PinId);
					else
						CLR_BIT(GPIO_PORTA_DATA_R,Copy_u8PinId);
					break;
				
				case 'B' : 
						if(Copy_u8PinValue == PIN_HIGH)
							SET_BIT(GPIO_PORTB_DATA_R,Copy_u8PinId);
					else
							CLR_BIT(GPIO_PORTB_DATA_R,Copy_u8PinId);
					break;
				
				case 'C' : 
					if(Copy_u8PinValue == PIN_HIGH)
							SET_BIT(GPIO_PORTC_DATA_R,Copy_u8PinId);
					else
							CLR_BIT(GPIO_PORTC_DATA_R,Copy_u8PinId);
					break;
				
				case 'D' : 
					if(Copy_u8PinValue == PIN_HIGH)
						SET_BIT(GPIO_PORTD_DATA_R,Copy_u8PinId);
					else
						CLR_BIT(GPIO_PORTD_DATA_R,Copy_u8PinId);
					break;
				
				case 'E' : 
					if(Copy_u8PinValue == PIN_HIGH)
						SET_BIT(GPIO_PORTE_DATA_R,Copy_u8PinId);
					else
						CLR_BIT(GPIO_PORTE_DATA_R,Copy_u8PinId);
					break;
				
				case 'F' : 
					if(Copy_u8PinValue == PIN_HIGH)
							SET_BIT(GPIO_PORTF_DATA_R,Copy_u8PinId);
					else
						CLR_BIT(GPIO_PORTF_DATA_R,Copy_u8PinId);
					break;
					
				default :
					ERROR_STATUS = 1;
			}
	}
	else
		ERROR_STATUS = 1;
	return ERROR_STATUS;
	
}

u8 GPIO_u8GetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinId , u8* ReturnedPinValue)
{
	u8 ERROR_STATUS = 0;
	if(Copy_u8PortName >= 'A' && Copy_u8PortName <= 'F' && (Copy_u8PinId>=0 && Copy_u8PinId<=7))
	{
		switch(Copy_u8PortName)
		{
			case 'A' : 
				*ReturnedPinValue = READ_BIT(GPIO_PORTA_DATA_R,Copy_u8PinId);
			break;
			
			case 'B' : 
				*ReturnedPinValue = READ_BIT(GPIO_PORTB_DATA_R,Copy_u8PinId);
			break;
			
			case 'C' : 
				*ReturnedPinValue = READ_BIT(GPIO_PORTC_DATA_R,Copy_u8PinId);
			break;
			
			case 'D' : 
				*ReturnedPinValue = READ_BIT(GPIO_PORTD_DATA_R,Copy_u8PinId);
			break;
			
			case 'E' : 
				*ReturnedPinValue = READ_BIT(GPIO_PORTE_DATA_R,Copy_u8PinId);
			break;
			
			case 'F' : 
				*ReturnedPinValue = READ_BIT(GPIO_PORTF_DATA_R,Copy_u8PinId);
			break;
			
			default : 
				ERROR_STATUS = 1;
		}
	}
	else
		ERROR_STATUS = 1;
	
	return ERROR_STATUS;
}

u8 GPIO_u8GetPortValue(u8 Copy_u8PortName , u8* ReturnedPortValue)
{
	u8 ERROR_STATUS = 0;
	if(Copy_u8PortName >= 'A' && Copy_u8PortName <= 'F')
	{
		switch(Copy_u8PortName)
		{
			case 'A' : 
				*ReturnedPortValue = (u8)GPIO_PORTA_DATA_R;
			break;
			
			case 'B' : 
				*ReturnedPortValue = (u8)GPIO_PORTB_DATA_R;
			break;
			
			case 'C' : 
				*ReturnedPortValue = (u8)GPIO_PORTC_DATA_R;
			break;
			
			case 'D' : 
				*ReturnedPortValue = (u8)GPIO_PORTD_DATA_R;
			break;
			
			case 'E' : 
				*ReturnedPortValue = (u8)GPIO_PORTE_DATA_R;
			break;
			
			case 'F' : 
				*ReturnedPortValue = (u8)GPIO_PORTF_DATA_R;
			break;
			
			default : 
				ERROR_STATUS = 1;
		}
	}
	else
		ERROR_STATUS = 1;
	
	return ERROR_STATUS;
	
}

