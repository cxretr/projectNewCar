/**            
 * @file       ts.h   
 * @brief      Touchscreen behavior  触摸屏行为         
 * @author     2475232977@qq.com
 * @date       2026/04/19
 * @version    1.0
 * @property   
 * @note       
 * @copyright  Copyright (c)   2026    2475232977@qq.com    All Right Reseverd
 */

#ifndef _TS_H
#define _TS_H

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/mman.h>
#include<linux/input.h>
#include "log.h"

#define TsPath "/dev/input/event0"
#define lcdwidth 800
#define lcdheight 480
#define tswidth 1024
#define tsheight 600

/**
 * @name       ts_init
 * @brief      ts initialization LCD初始化
 * @param      
 *             @lcd_path Path of ts driver ts驱动的路径
 * @retval     int   ts file descriptors.   ts文件描述符
 * @date       2026/04/19
 * @version    1.0
 * @note       
 */
int ts_init(const char *ts_path);

/**
 * @name       ts_getVal
 * @brief      ts get coord   ts 获取坐标
 * @param      
 *             @fd file descriptors. 文件描述符
 *             @fd_x coord of x x的坐标
 *             @fd_y coord of y y的坐标
 * @retval     none
 * @date       2026/04/19
 * @version    1.0
 * @note       
 */
void ts_getVal(int fd, int *fd_x, int *fd_y);


/**
 * @name       ts_uninit
 * @brief      ts uninitialization LCD解除初始化
 * @param      
 *             @fd file descriptors. 文件描述符
 * @retval     none
 * @date       2026/04/19
 * @version    1.0
 * @note       
 */
void ts_uninit(int fd);

#endif