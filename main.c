//arm-linux-gcc main.c ./src/*.c -o ./bin/main -I ./include/ -L ./lib/ -ljpeg -lfont -lm -pthread
#include "lcd.h"
#include "ts.h"
#include "jpeg.h"
#include "usefont.h"
#include "log.h"
#include "interfaceui.h"
#include "ts_task.h"  //关于线程API接口的头文件   编译时需要指定  -pthread

int main(int argc, char const *argv[])
{
	//1.LCD屏初始化
	LogPrint("LCDinit");
	LcdDev_t *lcdDev = lcd_init(LCD_PATH);

	// 清屏为黑色（0xFF000000 为不透明黑色）
	lcd_clear(lcdDev->mp, 0xFF000000);

	//2.触摸屏初始化
	LogPrint("TSinit");
	ts_fd = ts_init(TsPath);

	//3.创建子线程
	LogPrint("ts_thread init");
    pthread_t ts_thread;
    pthread_create(&ts_thread,NULL,ts_task,NULL);

	//4.系统开机动画
	if (NULL != lcdDev)
	{
		LogPrint("jpegShow");
		BootAnimation(lcdDev);
	}

	// 清屏为白色（0xFFFFFFFF 为不透明白色）
	lcd_clear(lcdDev->mp, 0xFFFFFFFF);

	//5.共享充电桩选择界面
	LogPrint("SelectionInterface");
	SelectionInterface(lcdDev);

	//6.等待用户点击

    if (-1 != ts_fd)
	{
		LogPrint("ts_uninit");
		ts_uninit(ts_fd);
	}
	
	LogPrint("lcd_uninit");
	lcd_uninit(lcdDev);

	return 0;
}



