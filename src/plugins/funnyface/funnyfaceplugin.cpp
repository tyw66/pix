#include "funnyfaceplugin.h"

#include <QColor>

#include "color.h"
#include "muti_shape.h"
#include "shape.h"
#include "transform.h"
#include "vec.h"

FunnyFacePlugin::FunnyFacePlugin(QObject *parent) :
    QObject(parent)
{
}

void FunnyFacePlugin::paintImg(QImage &img, const Param &param)
{
    #pragma omp parallel for
        for(int i = 0; i < img.width(); ++i){
            for(int j = 0; j < img.height(); ++j){
                img.setPixel(j, i, sample(i, j, img, param).rgb());
            }
        }
}

QColor FunnyFacePlugin::sample(int x, int y, const QImage &img, const Param &pm)
{
    //! 背景色
    QColor color(225,225,225);

    //! 定义坐标系
    double xPos, yPos;
    Util::scalePointXY(x,y,xPos,yPos,1, 1);
    Util::movePointXY(xPos, yPos, xPos, yPos, img.width()/2, img.height()/2);

    double angle = pm.mouse_posY * 180.0 - 90;
    Util::rotatePointXY(xPos, yPos,xPos, yPos, angle, 0, 0);

    //! 加入对象构建场景
    //脸
    Circle face(0,0, Color(250,211,94), 90);
    if(face.isContain(xPos,yPos)){
        color.setRgb(face.color_fill.r,face.color_fill.g,face.color_fill.b);
    }
    //    else {
    //        return color;
    //    }

    //嘴巴
    Circle mouth_top(0,-10, Color(20,20,20), 82);
    Circle mouth_buttom(0,0, Color(124,64,12), 80);
    Ring r(mouth_buttom,mouth_top);
    if(r.isContain(xPos,yPos)){
        color.setRgb(mouth_buttom.color_fill.r,mouth_buttom.color_fill.g,mouth_buttom.color_fill.b);
    }

    //眉毛
    Circle c0(0,-300, Color(124,64,12), 240);
    Circle c1(-55,-60, Color(20, 20, 20), 15);
    Circle c2(-55,-60, Color(20,20,20), 10);
    Circle c3(55,-60, Color(20, 20, 20), 15);
    Circle c4(55,-60, Color(20,20,20), 10);
    BendShape eyebrow1(c1,c2,c0);
    BendShape eyebrow2(c3,c4,c0);
    if(eyebrow1.isContain(xPos,yPos) || eyebrow2.isContain(xPos,yPos)){
        color.setRgb(c0.color_fill.r,c0.color_fill.g,c0.color_fill.b);
    }

    //脸颊
    Ellipse e1(-70,-10, Color(255,190,130),20,10);
    Ellipse e2(70,-10, Color(255,190,130),20,10);
    if(e1.isContain(xPos, yPos) || e2.isContain(xPos, yPos)){
        color.setRgb(e1.color_fill.r,e1.color_fill.g,e1.color_fill.b);
    }

    //左眼睛
    Rect rect1(-80,-45,Color(255, 255, 255),50,16);
    Circle cLeft(-80,-37, Color(20, 20, 20), 8);
    Circle cRight(-30,-37, Color(20,20,20), 8);
    Capsule eye1(rect1, cLeft,cRight);
    if(eye1.isContain(xPos, yPos)){
        color.setRgb(rect1.color_fill.r,rect1.color_fill.g,rect1.color_fill.b);
    }

    //右眼睛
    Rect rect2(30,-45,Color(255, 255, 255),50,16);
    Circle cLeft2(80,-37, Color(20, 20, 20), 8);
    Circle cRight2(30,-37, Color(20,20,20), 8);
    Capsule eye2(rect2, cLeft2, cRight2);
    if(eye2.isContain(xPos, yPos)){
        color.setRgb(rect2.color_fill.r,rect1.color_fill.g,rect1.color_fill.b);
    }

    //左眼珠（变化范围 -80~-30）
    //        Circle ball1(-79,-37, Color(20,20,20), 8);//无动画
    //    Circle ball1(-80+t*50,-37, Color(20,20,20), 8);//随时间动
    Circle ball1(-80+pm.mouse_posX*50,-37, Color(20,20,20), 8);//随鼠标动
    if(ball1.isContain(xPos, yPos)){
        color.setRgb(ball1.color_fill.r,ball1.color_fill.g,ball1.color_fill.b);
    }

    //右眼珠（变化范围 30~80）
    //        Circle ball2(31,-37, Color(20,20,20), 8);//无动画
    //    Circle ball2(30+t*50,-37, Color(20,20,20), 8); //随时间动
    Circle ball2(30+pm.mouse_posX*50,-37, Color(20,20,20), 8); //随鼠标动
    if(ball2.isContain(xPos, yPos)){
        color.setRgb(ball2.color_fill.r,ball1.color_fill.g,ball1.color_fill.b);
    }

    return color;
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(FunnyFace, FunnyFacePlugin)
#endif // QT_VERSION < 0x050000
