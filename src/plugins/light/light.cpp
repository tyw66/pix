#include "light.h"
#include <QtPlugin>
#include <math.h>
#include "trans.h"
#include "vec.h"

LightPlugin::LightPlugin(QObject *parent)  :
    QObject(parent)
{

}

void LightPlugin::paintImg(QImage &img, const Param &param)
{
    //归一化鼠标位置
    double mx = param.mouse_posX * 1.0 / param.drawArea_width;
    double my = param.mouse_posY * 1.0 / param.drawArea_height;

#pragma omp parallel for
    for(int j = 0; j < img.height(); ++j){
        for(int i = 0; i < img.width(); ++i){
            //当前像素位置
            double px = i *1.0 / img.width();
            double py = j *1.0 / img.height();
            //着色
            img.setPixel(i, j, sample(px, py, mx, my).rgb());
        }
    }
}

QColor LightPlugin::sample(double px, double py, double mx, double my)
{
    //! 背景色
     Color color(255,255,240);
     double factor = 0;

     //! 坐标转换
     double xPos, yPos;
     Util::scalePointXY(px,py,xPos,yPos,200,200);
     Util::movePointXY(xPos, yPos, xPos, yPos, 100, 100);
 //    double xCenter,yCenter;//圆心
 //    Util::scalePointXY(mx,my,xCenter,yCenter,200,200);
 //    Util::movePointXY(xCenter, yCenter, xCenter, yCenter, 100, 100);

     //! 光源
     double r = 10+40*sin(1.57*mx);//鼠标左右控制大小
     Circle lightSource(0,0,Color(255,0,0),r);

     //    //! 物体
     //    double ri = 30;
     //    tyw::Circle item(xCenter,yCenter,Color(255,0,0),ri);

     //    if(item.isContain(xPos,yPos)){
     //        return item.getColor();
     //    }

     //! 不用积分
//         double sdf = lightSource.getSDF(xPos,yPos) ;
//         factor = 1 - sdf/500;

     //!  用MC积分计算当前像素点处的光线强度
     const int N = 20;

     for(int i = 0; i < N; ++i){
         //        double a = 6.28 *i / N; //分层采样
         //        double a =  6.28*  rand()/RAND_MAX;//均匀采样
         double a = 6.28 * (i + (double)rand()/RAND_MAX) / N; //抖动采样
         double dx = cos(a);
         double dy = sin(a);
         factor += trace(xPos,yPos,dx,dy,lightSource,my);
     }
     factor = factor * 1.0 / N;


     color = color*factor;
     return QColor(color.r, color.g, color.b);
}

double LightPlugin::trace(double x, double y, double dx, double dy, Circle &circle, double power)
{
    double t = 0.0;
    for(int j = 0; j < 10 && t < 200; ++j){
        double sdf = circle.getSDF(x + dx * t, y + dy * t) ;
        if(sdf < 1e-6 ) {
            return 4.0-power*4.0;
        }
        t += sdf;
    }
    return 0;
}


//导出该插件 （插件名，插件类名）
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(Light,LightPlugin)
#endif // QT_VERSION < 0x050000
