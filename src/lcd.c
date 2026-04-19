#include "lcd.h"

LcdDev_t *lcd_init(const char *lcd_path)
{
    //1.申请堆内存
    LcdDev_t *lcd = (LcdDev_t *)calloc(1,sizeof(LcdDev_t));

    //*lcd是结构体本身，不能用来判断，lcd即是结构体的地址
    if (lcd == NULL)
    {
        //需要写一个日志记录错误
    }
    

}