#include "interfaceui.h"

/**
 * @name       BootAnimation
 * @brief      Boot Animation Boot Animation 开机动画
 * @param      
 *             @lcdDev LCD device information lcd设备信息
 * @retval     none
 * @date       2026/04/21
 * @version    1.0
 * @note       
 */
void BootAnimation(LcdDev_t *lcdDev)
{
   jpegShow(lcdDev->mp, 0, 40); 
}

/**
 * @name       SelectionInterface
 * @brief      Selection Interface Selection Interface 选择界面
 * @param      
 *             @lcdDev LCD device information lcd设备信息
 * @retval     none
 * @date       2026/04/21
 * @version    1.0
 * @note       
 */
void SelectionInterface(LcdDev_t *lcdDev)
{
    LogPrint("jpeg_to_lcd");
	jpeg_to_lcd(lcdDev->mp, "./gif/icon.jpg", 200, 150);

    //5.显示文字界面
	LogPrint("font_usefont");
    font_usefont(lcdDev->mp,"共享充电桩系统",
	            32,         //字体大小
				250,50,
	            0,255,255,255,
				255,0,0,0,
				300,50);
    font_usefont(lcdDev->mp,"我是商家",
				22,      //字体大小
				85,20,   //宽度高度
				0,236,237,239,
				255,0,0,0,
				270,350);  //起始位置
    font_usefont(lcdDev->mp,"我是用户",
				22,       //字体大小
				85,20,   //宽度高度
				0,236,237,239,
				255,0,0,0,
				445,350);  //起始位置
}

/**
 * @name       Login Interface
 * @brief      Login Interface 登录界面
 * @param      
 *             @lcdDev LCD device information lcd设备信息
 * @retval     none
 * @date       2026/04/23
 * @version    1.0
 * @note       
 */
void LoginInterface(LcdDev_t *lcdDev)
{
    LogPrint("jpeg_to_lcd");
	// 清屏为白色（0xFFFFFFFF 为不透明白色）
	lcd_clear(lcdDev->mp, 0xFFFFFFFF);
	jpeg_to_lcd(lcdDev->mp, "./gif/icon.jpg", 200, 150);

    //5.显示文字界面
	LogPrint("font_usefont");
    font_usefont(lcdDev->mp,"共享充电桩系统",
	            32,         //字体大小
				250,50,
	            0,255,255,255,
				255,0,0,0,
				300,50);
    font_usefont(lcdDev->mp,"注册账号",
				22,      //字体大小
				85,20,   //宽度高度
				0,236,237,239,
				255,0,0,0,
				270,350);  //起始位置
    font_usefont(lcdDev->mp,"登录账号",
				22,       //字体大小
				85,20,   //宽度高度
				0,236,237,239,
				255,0,0,0,
				445,350);  //起始位置
}