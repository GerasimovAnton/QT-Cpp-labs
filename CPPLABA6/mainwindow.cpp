#include "mainwindow.h"
#include "ui_mainwindow.h"


#include "tree.h"
#include "list.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

List<QString> *arr = nullptr;
Tree<QString,QString> *tree = nullptr;

void MainWindow::printList(List<QString>& l)
{
    ui->lineEdit_2->clear();
    for(QString s: l)
    {
        ui->lineEdit_2->setText(ui->lineEdit_2->text() +" "+ s);
    }
}

void MainWindow::printTree(int i)
{
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    if(tree == nullptr || tree->Size() == 0) return;

    List<QString> *l = new List<QString>();

    if(i == 0) tree->sorted(*l);
    else if(i == 1) tree->leftToRight(*l);
    else if(i == 2) tree->rightToLeft(*l);


    for(QString s: *l)
    {
        ui->textEdit->setText(ui->textEdit->toPlainText() +" "+ s);
    }

    ui->textEdit_2->setText("H = " + QString::number(tree->Height())+" Size ="+ QString::number(tree->Size()) + "\nTREE STRUCT: ");

    int h = tree->Height();
    int last = tree->Size();
    for (int i = 0;i < h-1; i++) {
        last -= pow(2,i);
    }


    QString levels;
    for (int i = 0;i < h-1; i++) {
        levels = levels + "\n" + QString::number(i) + " level = " + QString::number(pow(2,i));
    }

    levels  += "\n" + QString::number(h-1) + " level = " + QString::number(last);
    ui->textEdit_2->setText(ui->textEdit_2->toPlainText() +"\n"+ levels);

}

void MainWindow::on_pushButton_clicked()
{
    if(arr == nullptr)  arr = new List<QString>();
    arr->pushBack(ui->lineEdit->text());

    printList(*arr);

}

void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit_2->clear();
    delete arr;
    arr = nullptr;
}

void MainWindow::on_pushButton_3_clicked()
{
    if(arr != nullptr){
    tree = new Tree<QString,QString>();

        for(QString s: *arr)
        {
            tree->addElement(s,s);
        }

        printTree(ui->comboBox->currentIndex());
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    printTree(index);
}

void MainWindow::on_pushButton_5_clicked()
{
    QString s = ui->lineEdit_4->text();
    if(tree == nullptr) tree = new Tree<QString,QString>();

    tree->addElement(s,s);
    printTree(ui->comboBox->currentIndex());
}

void MainWindow::on_pushButton_4_clicked()
{
    QString s = ui->lineEdit_4->text();
    if(tree == nullptr) return;
    tree->deleteElement(s);
    printTree(ui->comboBox->currentIndex());
}

void MainWindow::on_pushButton_6_clicked()
{

}
