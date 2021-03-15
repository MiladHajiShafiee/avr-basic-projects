/*
 * SPI.cpp
 *
 * Created: 2018/08/02 7:19:57 صـبـح
 * Author : Milad
 */ 

#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "Lcd 2x16.h"
#include "SPI.h"

Lcd_4_BitMode lcd;
Spi spi;

int main(void)
{
	char Rdata ;
	
	lcd.LcdInit();
	spi.SlaveInit();
	lcd.LcdString("Slave Device");
	lcd.LcdCommand(GoSecondLine);
	lcd.LcdString("Received Data: ");
	
    while (1) 
    {
		Rdata = spi.Read();
		lcd.LcdGoXy(1 , lcd.LcdString("Received data") + 2);
		lcd.LcdChar(Rdata);
		_delay_ms(500);
    }
}

