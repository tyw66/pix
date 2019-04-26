#include "funny.h"
#include <QColor>

Funny::Funny()
{
}

void Funny::paintImg(QImage &img, const Param &param)
{
    int w = img.width();
    int h = img.height();

//#pragma omp parallel for
    //遍历像素点
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            //获取颜色
            int r = 155*i/h+100*param.mouse_posY/h;
            r = r > 255 ? 255 : r;
            int g = 155*j/w+100*param.mouse_posX/w;
            g = g > 255 ? 255 : g;
            //设置颜色
            img.setPixel(j,i,QColor::fromRgb(r, g,140).rgb());
        }
    }
}
