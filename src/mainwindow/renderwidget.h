#ifndef DRAWWINDOW_H
#define DRAWWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>
#include <QLabel>
#include <QTimer>

#include "interface.h"

class RenderWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RenderWidget(QWidget *parent = NULL);

protected:
    void resizeEvent(QResizeEvent* ev);

    void mouseMoveEvent(QMouseEvent* ev);

    void mousePressEvent(QMouseEvent* ev);

    void mouseReleaseEvent(QMouseEvent* ev);

    void paintEvent(QPaintEvent* ev );

    void keyPressEvent(QKeyEvent* ev);

    void dragEnterEvent(QDragEnterEvent* ev);

    void dropEvent(QDropEvent* ev);

private:
    void renderImg();
    /**
     * @brief 加载插件，填充m_interface对象
     */
    void loadPlugin();
    /**
     * @brief 加载插件，填充m_interface对象
     * @param fileName
     */
    void loadPlugin(const QString fileName);

private slots:
    void onTimeOut();

private:
    ImgInterface* m_interface;
    Param m_param;
    QImage* m_image;            //图像数据

    QTimer m_timer;

    QLabel* m_label;

    bool m_hasPlugin;

};

#endif // DRAWWINDOW_H
