#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    list = new List<QString>();

    list->pushBack("0");
    list->pushBack("1");
    list->pushBack("2");
    list->pushBack("3");
    list->pushBack("4");
    list->pushBack("5");
    list->pushBack("6");
    list->pushBack("7");

    showList();
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{
    list->pushFront(ui->lineEdit->text());
    showList();
}

void MainWindow::on_pushButton_2_clicked()
{
    list->pushBack(ui->lineEdit->text());
    showList();
}

void MainWindow::on_pushButton_4_clicked()
{
    list->popFront();
    showList();
}

void MainWindow::on_pushButton_3_clicked()
{
    list->popBack();
    showList();
}

void MainWindow::showList()
{
    ui->listWidget->clear();
    //ui->textEdit->clear();

    int i = 0;
    for(QString s: *list){
         ui->listWidget->addItem( QString::number(i++) + ": " +s);
        // i++;
    }
}

void MainWindow::pasteElement(int startInx, QString el)
{

    if(startInx > list->size() - 1) return;
    List<QString> *tmp = new List<QString>();

    int sz = list->size() ;

    for(int i = 0;i < sz - startInx;i++)
    {
        tmp->pushFront(list->back());
        list->popBack();
    }

    list->pushBack(el);

    for(QString s : *tmp)
    {
        list->pushBack(s);
        tmp->popFront();
    }

    delete tmp;
}

List<QString> &MainWindow::removeElements(int f, int t)
{
    List<QString> *tmp = new List<QString>();
    List<QString> *rem = new List<QString>();

    int sz = list->size();

    for(int i = 0;i < sz - t;i++)
    {
        tmp->pushFront(list->back());
        list->popBack();
    }

    sz = list->size();
    for(int i = 0;i < sz - f;i++)
    {
        rem->pushFront(list->back());
        list->popBack();
    }

    for(QString s  : *tmp)
    {
        list->pushBack(s);
        tmp->popFront();
    }

    delete tmp;
    return *rem;

}


//Paste
void MainWindow::on_pushButton_5_clicked()
{
    int from,to;

    from = ui->lineEdit_4->text().toInt();
    to = ui->lineEdit_3->text().toInt();

    if(from < 0 || to > list->size() || (from > to) ) return;

    int indx = ui->lineEdit_2->text().toInt();
    if(indx > to) indx -= (to - from + 1);

    List<QString> *rem =  &removeElements(from,to + 1);

    for(QString s : *rem)
    {
       pasteElement(indx,rem->front());
       rem->popFront();
       indx ++;
    }

    showList();
}

//load code
void MainWindow::on_pushButton_6_clicked()
{
    QFile file(":/code/res/code.txt");
    file.open(QFile::ReadOnly);

    QTextStream in(&file);

    while(!in.atEnd())
    {
        list->pushBack( in.readLine());
    }

    file.close();
    showList();
}
