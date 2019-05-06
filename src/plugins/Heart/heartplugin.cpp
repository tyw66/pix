#include "heartplugin.h"
#include <math.h>
#include <QKeyEvent>

#include <QDebug>
HeartPlugin::HeartPlugin(QObject *parent) :
    QObject(parent)
{
    flag = 0;
}

void HeartPlugin::paintImg(QImage &img, const Param &param)
{
    //计时
    int t = param.timetick;
    //
    if(param.mouse_isPress){
        flag = flag+1;
    }

    //归一化鼠标位置
    double mx = param.mouse_posX * 1.0 / param.drawArea_width ;
    double my = param.mouse_posY * 1.0 / param.drawArea_height;

    for(int j = 0; j < img.height(); ++j){
        for(int i = 0; i < img.width(); ++i){
            //当前归一化像素位置
            double px = i *1.0 / img.width() ;
            double py = j *1.0 / img.height() ;
            //着色
            if(flag %2 == 0){
                img.setPixel(i, j, sampleHeart(px, py, mx, my, t).rgb());
            }
            else if(flag%2 == 1){
                img.setPixel(i, j, sampleCircle(px, py, mx, my, t).rgb());
            }
        }
    }
}

QColor HeartPlugin::sampleHeart(double px, double py, double mx, double my, int time)
{
    //! 心型线方程：x^2+(y-x^(2/3))^2=1
    //! 数值范围 X：-1.0～1.0 ； Y：-1.0～1.5
    double radius = 0.02 * (2 + sin(0.2 * time));

    double pxt = px - mx ;
    double pyt = py - my;

    double n = -pyt - pow(pxt,2.0/3.0);
    double f = pxt * pxt + n * n;

    if(f < radius){
        return QColor(0,255,255);
    }
    else{
        return QColor(0,0,255);
    }

}

QColor HeartPlugin::sampleCircle(double px, double py, double mx, double my, int time)
{
    double radius = 0.02 * (2 + sin(0.2 * time));
    double pxt = px - mx;
    double pyt = py - my;

    double  f = pxt * pxt + pyt * pyt;

    if(f < radius){
        return QColor(0,255,255);
    }
    else{
        return QColor(0,0,255);
    }
}


#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(Heart, HeartPlugin)
#endif // QT_VERSION < 0x050000
