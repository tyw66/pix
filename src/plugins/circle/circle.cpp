#include "circle.h"
#include <QtPlugin>
#include <math.h>

CirclePlugin::CirclePlugin(QObject *parent)
{    
}

void CirclePlugin::paintImg(QImage &img, const Param &param)
{
//#pragma omp parallel for
    for(int i = 0; i < img.width(); ++i){
        for(int j = 0; j < img.height(); ++j){
            img.setPixel(j, i, sample(i, j, img, param).rgb());
        }
    }
}

QColor CirclePlugin::sample(int x, int y, const QImage& img, const Param &pm)
{
    //判断当前绘制的像素，
    //距离绘制区中心点的距离  &  鼠标到中心点绘制区中心点的距离

    double xFactorMouse = (double)(pm.mouse_posX)/(double)(pm.drawArea_width) - 0.5;
    double yFactorMouse = (double)(pm.mouse_posY)/(double)(pm.drawArea_height) - 0.5;
    double dMouse = xFactorMouse * xFactorMouse + yFactorMouse * yFactorMouse;

    double xFactorPixel = ((double)x/img.width()) - 0.5;
    double yFactorPixel = ((double)y/img.height()) - 0.5;
    double dCurPixel = xFactorPixel * xFactorPixel + yFactorPixel * yFactorPixel;

    double factor = dCurPixel / dMouse;

    if(factor > 1){
        return QColor(Qt::lightGray);
    }
    else{//factor从1->0,  颜色从（255，0，0）-> (200, 255, 255)
        return QColor(255-55*(1-factor), 255*(1-factor) , 255*(1-factor));
    }

    /*
    double x = x - width/ 2;
    double y = y - height/ 2;
    double rx = pm.mouse_posX - width/ 2;
    double ry = pm.mouse_posY - height/ 2;
    double r = sqrt(rx * rx + ry * ry);

    if(x * x + y * y <  r * r){
        return QColor(Qt::green);
    }
    else{
        return QColor(Qt::lightGray);
    }
    */
}

//导出该插件 （插件名，插件类名）
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(Circle,CirclePlugin)
#endif // QT_VERSION < 0x050000
