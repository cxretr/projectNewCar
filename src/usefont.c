#include "usefont.h"

void font_usefont(int *lcd_mp)
{
	//1.打开开发板路径下TrueType字库
	font *f = fontLoad("./simkai.ttf");

	//2.字体大小的设置
	fontSetSize(f,72);
	
	//3.创建一个画板（点阵图）
	bitmap *bm = createBitmapWithInit(200,200,4,getColor(0,255,255,255)); //也可使用createBitmapWithInit函数，改变画板颜色
	
	char buf[] = "晚安";
	
	//6.将字体写到点阵图上
	fontPrint(f,bm,0,0,buf,getColor(0,0,0,0),0);
	
	//7.把字体框输出到LCD屏幕上
	show_font_to_lcd(lcd_mp,0,0,bm);

	
	return 0;
}