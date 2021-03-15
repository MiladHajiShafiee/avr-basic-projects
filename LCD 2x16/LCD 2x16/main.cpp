/*
 * LCD 2x16.cpp
 *
 * Created: 2018/08/07 5:20:18 عـصـر
 * Author : Milad
 */ 
#include "Lcd 2x16.h"

Lcd_4_BitMode lcd;

int main(void)
{
	lcd.LcdInit();
	lcd.LcdString("Master is God");
	
}

