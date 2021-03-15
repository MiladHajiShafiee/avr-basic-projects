/*
 * Grafical LCD 64x128.cpp
 *
 * Created: 2018/07/28 11:01:23 صـبـح
 * Author : Milad
 */ 

#include "GLcd_64x128.h"
#include "Image.h"

ImageGLcd myGLcd;

int main(void)
{
	myGLcd.GLCD_Init();					/* Initialize GLCD */
	myGLcd.GLCD_ClearAll();				/* Clear all GLCD display */
	myGLcd.GLCD_String(img);
	while(1);
}

