#include "renderwidget.h"
#include <QPluginLoader>
#include <QMessageBox>
#include <QDir>
#include <QMimeData>
#include <QUrl>
#include <QDebug>

RenderWidget::RenderWidget(QWidget *parent) : QWidget(parent)
{
    m_hasPlugin = false;
    setMouseTracking(true);
    setAcceptDrops(true);

    m_image = new QImage(256,256,QImage::Format_RGB32);
    m_label = new QLabel(tr("Please drag file to draw."),this);

    m_timer.start(50);
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(onTimeOut()));

    loadPlugin();
    if(m_hasPlugin){
        renderImg();
    }
}

void RenderWidget::resizeEvent(QResizeEvent *ev)
{
    m_param.drawArea_width = ev->size().width();
    m_param.drawArea_height = ev->size().height();

    if(m_hasPlugin){
        renderImg();
    }
}

void RenderWidget::loadPlugin()
{
    QDir pluginDir("./plugin");

    foreach (QString fileName, pluginDir.entryList(QDir::Files)) {
        if(fileName == "default.dll"){//默认加载default.dll
            QString filePathName = pluginDir.absoluteFilePath(fileName);
            loadPlugin(filePathName);
        }
    }

}

void RenderWidget::loadPlugin(const QString fileName)
{
    QPluginLoader pluginLoader(fileName);
    QObject *plugin = pluginLoader.instance();
    if(plugin){
        m_interface = qobject_cast<ImgInterface*>(plugin);
        if(m_interface){
            m_hasPlugin = true;
            m_label->hide();
            return;
        }
    }

    m_label->setText(tr("Could not load the plugin."));
    m_label->show();
    m_hasPlugin = false;
}

void RenderWidget::onTimeOut()
{
    m_param.timetick++;
    if(m_hasPlugin){
        renderImg();
    }
}

void RenderWidget::renderImg()
{
    m_interface->paintImg(*m_image, m_param);
    update();
}


void RenderWidget::paintEvent(QPaintEvent *ev)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing, true);
    p.drawImage(ev->rect(),*m_image);
}

void RenderWidget::mouseMoveEvent(QMouseEvent *ev)
{
    m_param.mouse_posX = ev->x();
    m_param.mouse_posY = ev->y();
    //    qDebug() << m_param.mouse_posX;

    if(m_hasPlugin){
        renderImg();
    }
}

void RenderWidget::mousePressEvent(QMouseEvent *ev)
{
    m_param.mouse_posX = ev->x();
    m_param.mouse_posY = ev->y();
    m_param.mouse_isPress = true;


    if(m_hasPlugin){
        renderImg();
    }
}

void RenderWidget::mouseReleaseEvent(QMouseEvent *ev)
{
    m_param.mouse_posX = ev->x();
    m_param.mouse_posY = ev->y();
    m_param.mouse_isPress = false;

    if(m_hasPlugin){
        renderImg();
    }
}

void RenderWidget::keyPressEvent(QKeyEvent *ev)
{
    m_param.key_code = ev->key();
    if(m_hasPlugin){
        renderImg();
    }
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
        if(m_hasPlugin){
            renderImg();
        }
    }
}
