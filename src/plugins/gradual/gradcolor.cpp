#include "gradcolor.h"

#include <QColor>

GradColor::GradColor(QObject *parent)
{
}

void GradColor::paintImg(QImage &img, const Param &param)
{

//#pragma omp parallel for
    //遍历像素点
    for(int i = 0; i < img.width(); ++i){
        for(int j = 0; j < img.width(); ++j){
            //获取颜色
//            int r = 155*i/img.height() +100*param.mouse_posY/h;
//            r = r > 255 ? 255 : r;
//            int g = 155*j/ img.width()+100*param.mouse_posX/w;
//            g = g > 255 ? 255 : g;
            //设置颜色
           // img.setPixel(j,i,QColor::fromRgb(r,g,b).rgb());

            ////////////////////////////////////////////////////////

            double fw = j * 1.0 / img.width();
            double fh = i * 1.0 / img.height();

            int valueX = fw * 255;
            int valueY = fh * 255;

            int valueZ = param.mouse_posY *1.0 / param.drawArea_height * 255;

            //设置颜色
            img.setPixel(j,i,QColor::fromRgb(valueX, valueZ, valueY).rgb());
        }
    }
}

//导出该插件 （插件名，插件类名）
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(GradColor,GradColor)
#endif // QT_VERSION < 0x050000
