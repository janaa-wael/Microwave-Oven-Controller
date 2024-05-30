#ifndef GPIO_H
#define GPIO_H

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/tm4c123gh6pm.h"
#include "../../LIB/BIT_MATH.h"


#define GPIO_LOCK_KEY           0x4C4F434B  // Unlocks the GPIO_CR register
#define GPIO_CR_VALUE						0xFF

#define PIN_LOW								0
#define PIN_HIGH							1
#define PORT_LOW							0x00
#define PORT_HIGH							0xFF

#define PIN_INPUT							0
#define PIN_OUTPUT							1
#define PORT_INPUT						0x00
#define PORT_OUTPUT						0xFF

u8 GPIO_INIT(u8 u8_CopyPortName);
u8 GPIO_u8SetPortDirection(u8 Copy_u8PortName, u8 Copy_u8PortDir);
u8 GPIO_u8SetPinDirection(u8 Copy_u8PortName, u8 Copy_u8PinId , u8 Copy_u8PinDir);
u8 GPIO_u8SetPortValue(u8 Copy_u8PortName, u8 Copy_u8PortValue);
u8 GPIO_u8SetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinId, u8 Copy_u8PinValue);
u8 GPIO_u8GetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinId , u8* Copy_u32ReturnedPinValue);
u8 GPIO_u8GetPortValue(u8 Copy_u8PortName , u8* Copy_u32ReturnedPortValue);

#endif

