#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>

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

    void on_actionAll_triggered();

private:
    Ui::MainWindow *ui;

    QList<RenderWidget*> m_renderWindows;

};

#endif // MAINWINDOW_H
