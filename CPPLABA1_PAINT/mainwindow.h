#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "area.h"
#include <QGraphicsScene>
//#include <QObject>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow :public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setCanvas(Canvas&);
    void setPS(float,float);

    void setTimer(bool);

public slots:
    void setP(float);
    void setS(float);
    void resize();
    void rotate();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_lineEdit_2_selectionChanged();

    void on_lineEdit_2_textEdited(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_2_windowIconTextChanged(const QString &iconText);

    void on_lineEdit_2_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_2_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::MainWindow *ui;
    Canvas *canvas;
    QTimer *timer;
    bool allObjectsInfl = 0;
};
#endif // MAINWINDOW_H
