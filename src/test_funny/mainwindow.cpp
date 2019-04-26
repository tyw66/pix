#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    setWindowTitle(tr("Image"));
    setGeometry(300,300,512,512);
    setMinimumSize(256,256);
    setMouseTracking(true);

    m_image = QImage(512,512,QImage::Format_RGB32);
    m_fun.paintImg(m_image,m_param);


}

MainWindow::~MainWindow()
{

}

void MainWindow::mouseMoveEvent(QMouseEvent *ev)
{
    m_param.mouse_posX = ev->x();
    m_param.mouse_posY = ev->y();

    renderImg();
}

void MainWindow::paintEvent(QPaintEvent *ev)
{
    QPainter p(this);
    p.drawImage(ev->rect(),m_image);
}

void MainWindow::renderImg()
{
    m_fun.paintImg(m_image,m_param);
    update();
}
