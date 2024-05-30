#include "../../LIB/STD_TYPES.h"
#include "../../LIB/tm4c123gh6pm.h"

void Systick_Init(void){
    NVIC_ST_CTRL_R=0;
    NVIC_ST_RELOAD_R=0x00FFFFFF;
    NVIC_ST_CURRENT_R=0;
    NVIC_ST_CTRL_R=0x00000005;  
}
void Systick_Wait(u32 d){
		NVIC_ST_CTRL_R=0;
    NVIC_ST_RELOAD_R=d-1;
    NVIC_ST_CURRENT_R=0;
		NVIC_ST_CTRL_R=0x00000005;
    while((NVIC_ST_CTRL_R&0x00010000)==0);  
}

void delay (u32 del){
		u32 i ;
		for(i=0;i<del;i++){
			Systick_Wait(16000);
		}
}
