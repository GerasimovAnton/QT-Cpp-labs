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
int *keys;
int capacity =0;

void MainWindow::drawTable(int size)
{
    if(h == nullptr) return;

     ui->textEdit->clear();
    for (int i = 0;i < size;i ++) {
        ui->textEdit->setText(ui->textEdit->toPlainText() +  "\nkey = " + QString::number(keys[i]) + " value = " + QString::number(h->get(keys[i])));
    }

}


void MainWindow::on_pushButton_clicked()
{
    int size = ui->lineEdit_2->text().toInt();

    if(size == 0) return;

    h = new HashTable<int,int>(size);
    keys = new int[size];


    for (int i = 0;i < size;i ++) {
        int r = rand()%100;
        h->add(r,rand()%100);
        keys[i] = r;
    }

    drawTable(size);
}

void MainWindow::on_pushButton_2_clicked()
{
    int key = ui->lineEdit_3->text().toInt();
    int value = ui->lineEdit_4->text().toInt();
    int size  = ui->lineEdit_2->text().toInt();

    if(size == 0) return;

    if(h == nullptr) {
        h = new HashTable<int,int>(size);
        keys = new int[size];

        for(int i= 0;i < size;i++) keys[i] = 0;
        h->add(0,0);
    }

    keys[(capacity++)%size] = key;
    h->add(key,value);

    drawTable(size);
}

void MainWindow::on_pushButton_3_clicked()
{
    if(h == nullptr) return;
    List<int> *l = &h->keys();

    int max = l->back();

    for(int i : *l)
    {
       if(i > max) max = i;
    }

    ui->lineEdit_5->setText("MAX KEY  = "+ QString::number(max));

}
