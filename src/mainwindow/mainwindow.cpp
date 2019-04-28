#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(tr("Pix"));
    setGeometry(300,300,512,512);
    setMinimumSize(256,256);

    m_renderWindow = new RenderWidget(this);
    ui->mainLayout->addWidget(m_renderWindow);
    setCentralWidget(m_renderWindow);

}

MainWindow::~MainWindow()
{
    delete ui;
}
