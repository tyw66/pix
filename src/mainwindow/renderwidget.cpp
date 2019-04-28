#include "renderwidget.h"
#include <QPluginLoader>
#include <QMessageBox>
#include <QDir>
#include<QMenuBar>

RenderWidget::RenderWidget(QWidget *parent) : QWidget(parent)
{

    setMouseTracking(true);

    if(!loadPlugin()){
        QMessageBox::information(this, "Error","Could not load the plugin.");
        return;
    }

    m_image = QImage(512,512,QImage::Format_RGB32);
    renderImg();
}

bool RenderWidget::loadPlugin()
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

void RenderWidget::mouseMoveEvent(QMouseEvent *ev)
{
    m_param.mouse_posX = ev->x();
    m_param.mouse_posY = ev->y();

    renderImg();
}

void RenderWidget::renderImg()
{
    m_interface->paintImg(m_image, m_param);
    update();
}

void RenderWidget::paintEvent(QPaintEvent *ev)
{
    QPainter p(this);
    p.drawImage(ev->rect(),m_image);
}
