#ifndef FUNNY_H
#define FUNNY_H

#include <QImage>
#include "funny_global.h"

/**
 * @brief 记录画图所需要的信息，如鼠标位置等
 */
struct Param
{
    Param() {}
    int mouse_posX, mouse_posY; //鼠标

};

class FUNNYSHARED_EXPORT Funny
{

public:
    Funny();

    /**
     * @brief 填充渐变图案
     * @param img
     * @param param
     */
    void paintImg(QImage& img, const Param& param);

};

#endif // FUNNY_H
