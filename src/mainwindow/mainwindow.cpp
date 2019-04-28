#include "mainwindow.h"
#include <QPluginLoader>
#include <QMessageBox>
#include <QDir>
#include<QMenuBar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle(tr("Pix"));
    setGeometry(300,300,512,512);
    setMinimumSize(256,256);
    setMouseTracking(true);

    if(!loadPlugin()){
        QMessageBox::information(this, "Error","Could not load the plugin.");
        return;
    }

    m_image = QImage(512,512,QImage::Format_RGB32);
    renderImg();
}

bool MainWindow::loadPlugin()
{
    QDir pluginDir("./plugin");

    foreach (QString fileName, pluginDir.entryList(QDir::Files)) {
        QPluginLoader pluginLoader(pluginDir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();
        if(plugin){
            m_interface = qobject_cast<ImgInterface*>(plugin);
            if(m_interface)
                return true;
        }
    }
    return false;
}

void MainWindow::mouseMoveEvent(QMouseEvent *ev)
{
    m_param.mouse_posX = ev->x();
    m_param.mouse_posY = ev->y();

    renderImg();
}

void MainWindow::renderImg()
{
    m_interface->paintImg(m_image, m_param);
    update();
}

void MainWindow::paintEvent(QPaintEvent *ev)
{
    QPainter p(this);
    p.drawImage(ev->rect(),m_image);
}
