/*
 * Smart_home.c
 *
 * Created: 8/15/2021 10:07:28 PM
 * Author : ziyad&hossien
 */ 
/*
 * main.c
 *
 * Created: 6/25/2021 10:50:38 PM
 *  Author: ziyad&hossien
 */



#include "InOut.h"
#include "LED.h"
#include "LCD.h"
#include "SPI.h"

int main(void)
	
{	LED0_Initialization();
	LED1_Initialization();
	LED2_Initialization();
	Buzzer_Initialization();
	Relay_Initialization();
	SPI_Init();
	LCD_Initialization();
	UART_Init(); 
	LCD_String("Smart Home");
	
	
	char data;

	while(1)
	
{  
	data = SPI_Receive();
		
		if(data == '1')
		{
			LCD_Clear();
			LCD_String("led 1");
			LED0_TGL();
			buzzer_ring();
		}
		
		else if(data == '2')
		{
			LCD_Clear();
			LCD_String("led 2");
			LED1_TGL();
			buzzer_ring();
			}
		
		else if(data == '3')
		{
			LCD_Clear();
			LCD_String("led 3 ");
			LED2_TGL();
			buzzer_ring();
		}
		
}
}




