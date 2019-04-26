#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>

#include "/home/tyw/tyw66/off/pix/src/funny/funny.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void mouseMoveEvent(QMouseEvent* ev);

    void paintEvent(QPaintEvent* ev );

private:
    void renderImg();

private:
    Funny m_fun;
    QImage m_image;
    Param m_param;
};

#endif // MAINWINDOW_H
