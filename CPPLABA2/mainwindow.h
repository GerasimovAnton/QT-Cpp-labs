#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSizePolicy>
#include "main.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QLineEdit>
#include <QListWidget>
#include <QPlainTextEdit>
#include <qplaintextedit.h>
#include "qlistwidget.h"
#include "qlineedit.h"
#include "component.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //void readInfo(QString fileName,Component **&arr,int &size);
    void drawList();



private slots:
    void on_pushButton_clicked();
    void on_addComponentBttn_clicked();

    void on_pushButton_2_clicked();

    void on_listWidget_itemSelectionChanged();

    void on_pushButton_3_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
