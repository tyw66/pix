#ifndef FUNNYFACE_H
#define FUNNYFACE_H

#include <QObject>
#include <QColor>
#include "interface.h"
/**
 * @brief 圆形插件
 */
class CirclePlugin : public QObject, public ImgInterface
{
    Q_OBJECT
    Q_INTERFACES(ImgInterface)//告知Qt，这个类实现了哪个接口
public:
    CirclePlugin(QObject *parent = NULL);
    /**
     * @brief 填充滑稽表情图案
     * @param img
     * @param param
     */
    void paintImg(QImage& img, const Param& param);

private:
    /**
     * @brief sample
     * @param px
     * @param py
     * @param width
     * @param height
     * @param param
     * @return
     */
    QColor sample(int px, int py, int width, int height, const Param &param);

};

#endif // FUNNYFACE_H
