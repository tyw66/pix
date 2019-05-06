#ifndef HEARTPLUGIN_H
#define HEARTPLUGIN_H

#include "interface.h"

#include <QObject>
#include <QColor>

/**
 * @brief 心脏线
 */
class HeartPlugin : public QObject, ImgInterface
{
    Q_OBJECT
#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID "pix.plugin.Heart")
#endif // QT_VERSION >= 0x050000
    Q_INTERFACES(ImgInterface)//告知Qt，这个类实现了哪个接口


public:
    HeartPlugin(QObject *parent = 0);

    void paintImg(QImage& img, const Param& param);

    QColor sampleHeart(double px, double py, double mx, double my, int time);
    QColor sampleCircle(double px, double py, double mx, double my, int time);

    int flag;

};

#endif // HEARTPLUGIN_H
