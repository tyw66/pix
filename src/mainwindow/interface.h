#ifndef INTERFACE_H
#define INTERFACE_H

#include <QImage>
/**
 * @brief 记录画图所需要的信息，如鼠标位置等
 */
struct Param
{
    Param() {
        mouse_posX = 0;
        mouse_posY = 0;
        mouse_isPress = false;
        key_code = -1;

        drawArea_width = 1;
        drawArea_height = 1;
    }


    int drawArea_width;  //屏幕绘制区大小
    int drawArea_height;
    int mouse_posX; //鼠标位置
    int mouse_posY;
    bool mouse_isPress;

    int key_code; //键盘按下的键

};

/**
 * @brief 接口类
 * @note 需要由插件来实现（提供）以下的这些虚函数
 */
class ImgInterface
{
public:
    virtual ~ImgInterface(){}
    virtual void paintImg(QImage& img, const Param& param) = 0;
};

//在QT元对象系统中注册该接口，第二个参数确保这个接口与其他接口不会相同
Q_DECLARE_INTERFACE(ImgInterface, "tyw66.ImgInterface/1.0")

#endif // INTERFACE_H
