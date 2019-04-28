#ifndef DRAWWINDOW_H
#define DRAWWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>

#include "interface.h"

class RenderWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RenderWidget(QWidget *parent = NULL);

protected:
    void mouseMoveEvent(QMouseEvent* ev);

    void paintEvent(QPaintEvent* ev );

private:
    void renderImg();
    /**
     * @brief 加载插件，填充m_interface对象
     * @return
     */
    bool loadPlugin();
private:
    ImgInterface* m_interface;
    Param m_param;
    QImage m_image;            //帧图像数据



};

#endif // DRAWWINDOW_H
