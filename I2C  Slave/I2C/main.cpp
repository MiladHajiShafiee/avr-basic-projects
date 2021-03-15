/*
 * I2C.cpp
 *
 * Created: 2018/08/05 8:20:01 صـبـح
 * Author : Milad
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include "I2C.h"
#include "Lcd 2x16.h"

Lcd_4_BitMode lcd;
I2c i2c;

/*
int main()
{
	uint8_t count = 1;
	
	lcd.LcdInit();
	i2c.SlaveInit(0x21);
	lcd.LcdString("Slave Device");
	lcd.LcdCommand(0xc0);
	i2c.Listen();
	while (1)
	{
		if (count > 16)
		{
			lcd.LcdCommand(0x18);
			lcd.LcdChar(i2c.Receive());
		}
		else
		{
			lcd.LcdChar(i2c.Receive());
		}
		count ++;
	}
}
*/

int main(void)
{
	lcd.LcdInit();
	lcd.LcdString("Slave Device");
	lcd.LcdCommand(GoSecondLine);
	lcd.LcdString("Received: ");
	lcd.LcdGoXy(1, 10);
	i2c.SlaveInit(0x11);
	i2c.Listen();
	while(1)
	{
		lcd.LcdChar(i2c.Receive());
	}
	i2c.Stop();
}