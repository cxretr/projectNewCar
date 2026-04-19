/**            
 * @file       lcd.h   
 * @brief      LCD screen display  LCD屏显示         
 * @author     2475232977@qq.com
 * @date       2026/04/19
 * @version    1.0
 * @property   
 * @note       
 * @copyright  Copyright (c)   2026    2475232977@qq.com    All Right Reseverd
 */

#ifndef _LCD_H
#define _LCD_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/mman.h>
#include "log.h"

//LCD屏的设备路径，根据实际情况修改
#define  LCD_PATH   "/dev/fb0"

//LCD内存映射的大小
#define  LCD_MAPSIZE (800*480*4)

typedef struct lcd_deviceinfo
{
    int fd;   //用于记录文件描述符
    int *mp;  //用于记录内存映射
}LcdDev_t;

/**
 * @name       lcd_init
 * @brief      LCD initialization LCD初始化
 * @param      
 *             @lcd_path Path of LCD driver lcd驱动的路径
 * @retval     LcdDev_t * The LCD device information includes file descriptors and memory mapping.   LCD设备信息包含文件描述符与内存映射
 * @date       2026/04/19
 * @version    1.0
 * @note       
 */
LcdDev_t *lcd_init(const char *lcd_path);

/**
 * @name       lcd_uninit
 * @brief      LCD uninitialization LCD解除初始化
 * @param      
 *             @lcd LCD device information lcd设备信息
 * @retval     none
 * @date       2026/04/19
 * @version    1.0
 * @note       
 */
void lcd_uninit(LcdDev_t *Lcd);

#endif