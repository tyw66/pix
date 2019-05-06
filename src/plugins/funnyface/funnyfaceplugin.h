#ifndef GENERICPLUGIN_H
#define GENERICPLUGIN_H

#include <QColor>
#include "color.h"
#include "interface.h"

/**
 * @brief 滑稽表情
 */
class FunnyFacePlugin : public QObject, ImgInterface
{
    Q_OBJECT
#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID "pix.plugin.FunnyFace")
#endif // QT_VERSION >= 0x050000

    Q_INTERFACES(ImgInterface)//告知Qt，这个类实现了哪个接口

public:
    FunnyFacePlugin(QObject *parent = 0);

    void paintImg(QImage& img, const Param& param);

private:
    QColor sample(double px, double py, double mx, double my);


    Color m_faceColor;
    Color m_darkGrayColor;
    Color m_mouth2Color;

    Color m_faceRedColor;
    Color m_blackColor;
    Color m_whiteColor;

};

#endif // GENERICPLUGIN_H
