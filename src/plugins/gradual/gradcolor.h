#ifndef FUNNYWIDGET_H
#define FUNNYWIDGET_H

#include <QObject>
#include <QtPlugin>
#include "interface.h"
/**
 * @brief 渐变插件
 */
class GradColor : public QObject, public ImgInterface
{
    Q_OBJECT
    Q_INTERFACES(ImgInterface)//告知Qt，这个类实现了哪个接口

#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID "pix.plugin.GradColor")
#endif // QT_VERSION >= 0x050000



public:
    explicit GradColor(QObject *parent = NULL);
    /**
     * @brief 填充渐变图案
     * @param img
     * @param param
     */
    void paintImg(QImage& img, const Param& param);

};

#endif // FUNNYWIDGET_H
