#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "info.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setInfo(Info *&i,int r);

private slots:
    void on_addComponentBttn_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
