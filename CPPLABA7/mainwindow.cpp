#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "HashTable.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

HashTable<int,int> *h;

void MainWindow::drawTable(int size)
{
    if(h == nullptr) return;

    for (int i = 0;i < size;i ++) {
        ui->textEdit->setText(ui->textEdit->toPlainText() +  "\nkey = " + QString::number(i) + " value = " + QString::number(h->get(i)));
    }

}


void MainWindow::on_pushButton_clicked()
{
    int size = ui->lineEdit_2->text().toInt();
    h = new HashTable<int,int>(size);



    for (int i = 0;i < size;i ++) {
        h->add(rand()%100,rand()%100);
    }

    drawTable(size);
}
