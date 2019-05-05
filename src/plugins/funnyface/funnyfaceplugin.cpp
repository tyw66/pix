#include "funnyfaceplugin.h"
#include "shape.h"
#include "trans.h"
#include "vec.h"

FunnyFacePlugin::FunnyFacePlugin(QObject *parent) :
    QObject(parent)
{
    m_faceColor = Color(250,211,94);
    m_mouth1Color = Color(20,20,20);
    m_mouth2Color = Color(124,64,12);
    m_faceRedColor = Color(255,190,130);

}

void FunnyFacePlugin::paintImg(QImage &img, const Param &param)
{
    //鼠标位置
    double mx = (double)param.mouse_posX / (double)param.drawArea_width;
    double my = (double)param.mouse_posY / (double)param.drawArea_height;

#pragma omp parallel for
    for(int j = 0; j < img.height(); ++j){
        for(int i = 0; i < img.width(); ++i){
            //当前像素位置
            double px = (double)i / (double)img.width();
            double py = (double)j / (double)img.height();
            //着色
            img.setPixel(i, j, sample(px, py, mx, my).rgb());
        }
    }
}

QColor FunnyFacePlugin::sample(double px, double py, double mx, double my)
{
    //抽象空间的大小
    const double SPACEW = 200;
    const double SPACEH = 200;

    //背景色
    QColor color(225,225,225);

    //坐标变换
    double xPos, yPos;
    Util::scalePointXY(px,py,xPos,yPos,SPACEW,SPACEH);
    Util::movePointXY(xPos, yPos, xPos, yPos, SPACEW/2, SPACEH/2);

    double angle = my * 180.0 - 90.0;
    Util::rotatePointXY(xPos, yPos, xPos, yPos, angle, 0, 0);

    //! 加入对象构建场景
    //脸
    Circle face(0,0, m_faceColor, 90);
    if(face.isContain(xPos,yPos)){
        color.setRgb(face.fColor.r,face.fColor.g,face.fColor.b);
    }

    //嘴巴
    Circle mouth_top(0,-10, m_mouth1Color, 82);
    Circle mouth_buttom(0,0, m_mouth2Color, 80);
    Ring r(mouth_buttom,mouth_top);
    if(r.isContain(xPos,yPos)){
        color.setRgb(mouth_buttom.fColor.r,mouth_buttom.fColor.g,mouth_buttom.fColor.b);
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
        color.setRgb(c0.fColor.r,c0.fColor.g,c0.fColor.b);
    }

    //脸颊
    Ellipse e1(-70,-10, m_faceRedColor,20,10);
    Ellipse e2(70,-10, m_faceRedColor,20,10);
    if(e1.isContain(xPos, yPos) || e2.isContain(xPos, yPos)){
        color.setRgb(e1.fColor.r,e1.fColor.g,e1.fColor.b);
    }

    //左眼睛
    Rect rect1(-80,-45,Color(255,255,255),50,16);
    Circle cLeft(-80,-37, Color(20, 20, 20), 8);
    Circle cRight(-30,-37, Color(20,20,20), 8);
    Capsule eye1(rect1, cLeft,cRight);
    if(eye1.isContain(xPos, yPos)){
        color.setRgb(rect1.fColor.r,rect1.fColor.g,rect1.fColor.b);
    }

    //右眼睛
    Rect rect2(30,-45,Color(255, 255, 255),50,16);
    Circle cLeft2(80,-37, Color(20, 20, 20), 8);
    Circle cRight2(30,-37, Color(20,20,20), 8);
    Capsule eye2(rect2, cLeft2, cRight2);
    if(eye2.isContain(xPos, yPos)){
        color.setRgb(rect2.fColor.r,rect1.fColor.g,rect1.fColor.b);
    }

    //左眼珠（变化范围 -80~-30）
    Circle ball1(-80+mx*50,-37, Color(20,20,20), 8);//随鼠标动
    if(ball1.isContain(xPos, yPos)){
        color.setRgb(ball1.fColor.r,ball1.fColor.g,ball1.fColor.b);
    }

    //右眼珠（变化范围 30~80）
    Circle ball2(30+mx*50,-37, Color(20,20,20), 8); //随鼠标动
    if(ball2.isContain(xPos, yPos)){
        color.setRgb(ball2.fColor.r,ball1.fColor.g,ball1.fColor.b);
    }

    return color;
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(FunnyFace, FunnyFacePlugin)
#endif // QT_VERSION < 0x050000
