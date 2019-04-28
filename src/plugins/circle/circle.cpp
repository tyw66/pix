#include "circle.h"
#include <QtPlugin>
#include <math.h>

CirclePlugin::CirclePlugin(QObject *parent)
{    
}

void CirclePlugin::paintImg(QImage &img, const Param &param)
{
    int width = img.width();
    int height = img.height();

//#pragma omp parallel for
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            img.setPixel(j,i,sample(j,i,width,height,param).rgb());
        }
    }
}

QColor CirclePlugin::sample(int px, int py, int width, int height, const Param &param)
{
    int x = px - width/ 2;
    int y = py - height/ 2;
    int rx = param.mouse_posX - width/ 2;
    int ry = param.mouse_posY - height/ 2;
    double r = sqrt(rx * rx + ry * ry);

    if(x * x + y * y <  r * r){
        return QColor(Qt::blue);
    }
    else{
        return QColor(Qt::yellow);
    }
}

//导出该插件 （插件名，插件类名）
Q_EXPORT_PLUGIN2(Circle,CirclePlugin)
