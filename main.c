#include "lcd.h"



int main(int argc, char const *argv[])
{
	//1.LCD屏初始化
	LcdDev_t *lcdDev = lcd_init(LCD_PATH);





	lcd_uninit(lcdDev);
}



