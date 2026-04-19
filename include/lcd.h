#ifndef _LCD_H
#define _LCD_H

#include <stdlib.h>

typedef struct lcd_deviceinfo
{
    int fd;   //用于记录文件描述符
    int *mp;  //用于记录内存映射
}LcdDev_t;


#endif