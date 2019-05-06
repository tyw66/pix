#ifndef FUNNYFACE_H
#define FUNNYFACE_H

#include "interface.h"
#include "shape.h"

#include <QObject>
#include <QColor>

/**
 * @brief 光
 */
class LightPlugin : public QObject, public ImgInterface
{
    Q_OBJECT
    Q_INTERFACES(ImgInterface)//告知Qt，这个类实现了哪个接口

#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID "pix.plugin.Light")
#endif // QT_VERSION >= 0x050000

public:
    LightPlugin(QObject *parent = 0);

    void paintImg(QImage& img, const Param& param);

private:
    QColor sample(double px, double py, double mx, double my);

    double trace(double x, double y, double dx, double dy, Circle &circle,double power);

};

#endif // FUNNYFACE_H
