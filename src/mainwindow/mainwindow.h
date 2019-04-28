#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "renderwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_actionTwo_triggered();

    void on_actionOne_triggered();

    void on_actionFour_triggered();

private:
    Ui::MainWindow *ui;

    RenderWidget* m_renderWindow01;
    RenderWidget* m_renderWindow02;
    RenderWidget* m_renderWindow03;
    RenderWidget* m_renderWindow04;
};

#endif // MAINWINDOW_H
