#ifndef GENERICPLUGIN_H
#define GENERICPLUGIN_H

#include <QGenericPlugin>
#include "interface.h"

class FunnyFacePlugin : public QObject, ImgInterface
{
    Q_OBJECT
#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QGenericPluginFactoryInterface")
#endif // QT_VERSION >= 0x050000

    Q_INTERFACES(ImgInterface)//告知Qt，这个类实现了哪个接口

public:
    FunnyFacePlugin(QObject *parent = 0);

    /**
     * @brief 填充滑稽表情图案
     * @param img
     * @param param
     */
    void paintImg(QImage& img, const Param& param);

private:

    QColor sample(int x, int y, const QImage &img, const Param &pm);
};

#endif // GENERICPLUGIN_H
