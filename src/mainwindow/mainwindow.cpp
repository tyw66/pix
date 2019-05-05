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


    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 8; ++j){
            RenderWidget *renderWindow = new RenderWidget(this);
            ui->mainLayout->addWidget(renderWindow,i,j);
            m_renderWindows.append(renderWindow);
            renderWindow->hide();
        }
    }
    m_renderWindows.at(0)->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOne_triggered()
{
    int index = 0;
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 8; ++j){
            m_renderWindows.at(index++)->hide();
        }
    }
    m_renderWindows.at(0)->show();
}

void MainWindow::on_actionTwo_triggered()
{
    int index = 0;
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 8; ++j){
            m_renderWindows.at(index++)->hide();
        }
    }
    m_renderWindows.at(0)->show();
    m_renderWindows.at(1)->show();
}

void MainWindow::on_actionFour_triggered()
{
    int index = 0;
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 8; ++j){
            m_renderWindows.at(index++)->hide();
        }
    }
    m_renderWindows.at(0)->show();
    m_renderWindows.at(1)->show();
    m_renderWindows.at(2)->show();
    m_renderWindows.at(3)->show();
}

void MainWindow::on_actionAll_triggered()
{
    int index = 0;
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 8; ++j){
            m_renderWindows.at(index++)->show();
        }
    }
}
