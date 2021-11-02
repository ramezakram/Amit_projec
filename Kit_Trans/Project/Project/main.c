
/*
 * main.c
 *
 * Created: 6/25/2021 10:50:38 PM
 *  Author: ziyed & hessan
 */

#include "SPI.h"
#include "UART.h"
#include "InOut.h"
#include "LCD.h"
#include "LED.h"




int main(void)
	
{	LED0_Initialization();
	LED1_Initialization();
	LED2_Initialization();
	Relay_Initialization();
	Buzzer_Initialization();
	LCD_Initialization();
	UART_Init(); 
	LCD_String("Smart Home");
	SPI_Init();
	
	char data;
	

	while(1)
{ 
	data = UART_Receive();//UART_Receive();
	
	
	if(data == '1')
	{
	       SPI_Transmit(data);
			LCD_Clear();
			LCD_String("led 1 ");
			LED0_TGL();
			buzzer_ring();
	} 
	 
	else if(data == '2')
	{
		
			SPI_Transmit(data);
			LCD_Clear();
			LCD_String("led 2");
			LED1_TGL();
			buzzer_ring();
	}
	 
	else if(data == '3')
	{	
			SPI_Transmit(data);
			LCD_Clear();
			LCD_String("led 3");
			LED2_TGL();
			buzzer_ring();
	}
 
}
}