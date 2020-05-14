#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "list.h"
#include "info.h"
#include <QString>

List<Info*> list;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setInfo(Info *&i,int r)
{
    QTableWidgetItem *w = new QTableWidgetItem();
    QTableWidgetItem *w1 = new QTableWidgetItem();
    QTableWidgetItem *w2 = new QTableWidgetItem();
    QTableWidgetItem *w3 = new QTableWidgetItem();

    w->setText(QString::number(i->getNum()));
    w1->setText(i->getType());
    w2->setText(i->getPlace());
    w3->setText(i->getTime());

    ui->tableWidget->setRowCount(r + 1);

    ui->tableWidget->setItem(r,0,w);
    ui->tableWidget->setItem(r,1,w1);
    ui->tableWidget->setItem(r,2,w2);
    ui->tableWidget->setItem(r,3,w3);
}


void MainWindow::on_addComponentBttn_clicked()
{
    if(ui->lineEdit_model->text().toInt() <= 0 ||
       ui->lineEdit_model_2->text() ==  "" ||
       ui->lineEdit_model_3->text() == ""  ||
       ui->lineEdit_model_4->text() == "" ) return;

    list.pushBack(new Info(ui->lineEdit_model->text().toInt(),
                           ui->lineEdit_model_2->text(),
                           ui->lineEdit_model_3->text(),
                           ui->lineEdit_model_4->text()));

   setInfo(list.back(),ui->tableWidget->rowCount());

}

//FIND
void MainWindow::on_pushButton_clicked()
{
    Info *i = new Info(ui->lineEdit_model->text().toInt(),
                       ui->lineEdit_model_2->text(),
                       ui->lineEdit_model_3->text(),
                       ui->lineEdit_model_4->text());

    int newR = 0;

    ui->tableWidget->clearContents();

    for (auto value : list)
    {
        if(*value == *i)
        {
            setInfo(value,newR);
            newR ++;
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    list.popBack();

    int newR = 0;

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    for (auto value : list)
    {
            setInfo(value,newR);
            newR ++;
    }

}
