#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(tr("Pix"));
    setGeometry(300,300,600,600);
    setMinimumSize(256,256);


    m_renderWindow01 = new RenderWidget(this);
    ui->mainLayout->addWidget(m_renderWindow01,0,0);
    m_renderWindow02 = new RenderWidget(this);
    ui->mainLayout->addWidget(m_renderWindow02,0,1);
    m_renderWindow03 = new RenderWidget(this);
    ui->mainLayout->addWidget(m_renderWindow03,1,0);
    m_renderWindow04 = new RenderWidget(this);
    ui->mainLayout->addWidget(m_renderWindow04,1,1);

    m_renderWindow02->hide();
    m_renderWindow03->hide();
    m_renderWindow04->hide();


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOne_triggered()
{
    m_renderWindow02->hide();
    m_renderWindow03->hide();
    m_renderWindow04->hide();
}

void MainWindow::on_actionTwo_triggered()
{
    m_renderWindow02->show();
    m_renderWindow03->hide();
    m_renderWindow04->hide();
}

void MainWindow::on_actionFour_triggered()
{
    m_renderWindow02->show();
    m_renderWindow03->show();
    m_renderWindow04->show();
}
