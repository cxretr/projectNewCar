#include "lcd.h"

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
LcdDev_t *lcd_init(const char *lcd_path)
{
    //1.申请堆内存
    LcdDev_t *lcd = (LcdDev_t *)calloc(1,sizeof(LcdDev_t));

    //*lcd是结构体本身，不能用来判断，lcd即是结构体的地址
    if (lcd == NULL)
    {
        errorPrint("calloc lcd NUll");
        return NULL;
    }
    //应该是lcd_path而不是*lcd_path，是因为带*号即意味着是传入第一个的字符
    lcd->fd = open(lcd_path,O_RDWR);
    if (-1 == lcd->fd)
    {
        errorPrint("lcd->fd error");
        return NULL;
    }
    lcd->mp = (int *)mmap(NULL,
                          LCD_MAPSIZE,
                          PROT_READ|PROT_WRITE,
                          MAP_SHARED,
                          lcd->fd,
                          0
                         ); 
    
    return lcd;
}

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
void lcd_uninit(LcdDev_t *Lcd)
{
    if (Lcd == NULL)
    {
        errorPrint("uninit Lcd NULL");
        return;
    }

    //解除内存映射
    munmap(Lcd->mp, LCD_MAPSIZE);

    //关闭LCD屏 
    close(Lcd->fd);

    //指针置空
    Lcd = NULL;
}