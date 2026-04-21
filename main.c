//arm-linux-gcc main.c ./src/*.c -o ./bin/main -I ./include/ -L ./lib/ -ljpeg -lfont -lm -pthread
#include "lcd.h"
#include "ts.h"
#include "jpeg.h"
#include "usefont.h"
#include "log.h"
#include <pthread.h>  //关于线程API接口的头文件   编译时需要指定  -pthread

int ts_fd;
int ts_x;
int ts_y;

//调用线程
void * ts_task(void *arg)
{
	LogPrint("ts_thread start");
    //调用死循环，并且不会退出
    while(1)
    {
        ts_getVal(ts_fd,&ts_x,&ts_y); //获取触摸屏坐标
		printf("ts x: %d\n",ts_x);
		printf("ts y: %d\n",ts_y);
    }
}

int main(int argc, char const *argv[])
{
	//1.LCD屏初始化
	LogPrint("LCDinit");
	LcdDev_t *lcdDev = lcd_init(LCD_PATH);
	//2.触摸屏初始化
	LogPrint("TSinit");
	ts_fd = ts_init(TsPath);

	//3.创建子线程
	LogPrint("ts_thread init");
    pthread_t ts_thread;
    pthread_create(&ts_thread,NULL,ts_task,NULL);

	//3.系统开机动画
	if (NULL != lcdDev)
	{
		LogPrint("jpegShow");
		jpegShow(lcdDev->mp, 0, 0);
	}

	//4.共享充电桩选择界面
	LogPrint("jpeg_to_lcd");
	jpeg_to_lcd(lcdDev->mp, "./gif/icon.jpg", 0, 0);

    //5.显示文字界面
	LogPrint("font_usefont");
    font_usefont(lcdDev->mp,"我是用户",32,200,200,0,255,0,0,0,0,0,0,300,300);

    if (-1 != ts_fd)
	{
		LogPrint("ts_uninit");
		ts_uninit(ts_fd);
	}
	
	LogPrint("lcd_uninit");
	lcd_uninit(lcdDev);

	return 0;
}



