#include "renderwidget.h"
#include <QPluginLoader>
#include <QMessageBox>
#include <QDir>
#include <QMimeData>
#include <QUrl>
#include <QDebug>

RenderWidget::RenderWidget(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
    setAcceptDrops(true);

    m_image = QImage(512,512,QImage::Format_RGB32);

    if(!loadPlugin()){
        return;
    }


    renderImg();
}

void RenderWidget::resizeEvent(QResizeEvent *ev)
{
    m_param.drawArea_width = ev->size().width();
    m_param.drawArea_height = ev->size().height();
}

bool RenderWidget::loadPlugin()
{
    QDir pluginDir("./plugin");

    foreach (QString fileName, pluginDir.entryList(QDir::Files)) {
        QString filePathName = pluginDir.absoluteFilePath(fileName);
        if(loadPlugin(filePathName)){
            return true;
        }
    }
    return false;
}

bool RenderWidget::loadPlugin(const QString fileName)
{
    QPluginLoader pluginLoader(fileName);
    QObject *plugin = pluginLoader.instance();
    if(plugin){
        m_interface = qobject_cast<ImgInterface*>(plugin);
        if(m_interface)
            return true;
    }

    QMessageBox::information(this, "Error",tr("Could not load the plugin."));
    return false;
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

void RenderWidget::mouseMoveEvent(QMouseEvent *ev)
{
    m_param.mouse_posX = ev->x();
    m_param.mouse_posY = ev->y();
//    qDebug() << m_param.mouse_posX;

    renderImg();
}

void RenderWidget::mousePressEvent(QMouseEvent *ev)
{
    m_param.mouse_posX = ev->x();
    m_param.mouse_posY = ev->y();
    m_param.mouse_isPress = true;

    renderImg();
}

void RenderWidget::mouseReleaseEvent(QMouseEvent *ev)
{
    m_param.mouse_posX = ev->x();
    m_param.mouse_posY = ev->y();
    m_param.mouse_isPress = false;

    renderImg();
}

void RenderWidget::keyPressEvent(QKeyEvent *ev)
{
    m_param.key_code = ev->key();

    renderImg();
}

void RenderWidget::dragEnterEvent(QDragEnterEvent *ev)
{
    if(ev->mimeData()->hasUrls())
        ev->acceptProposedAction();
    else
        ev->ignore();
}

void RenderWidget::dropEvent(QDropEvent *ev)
{
    if(ev->mimeData()->hasUrls()){
        QString fileName = ev->mimeData()->urls().at(0).toLocalFile();
        loadPlugin(fileName);
        renderImg();
    }
}
