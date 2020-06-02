#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    s = new Soldier(this->width()/2,this->height()/2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::moveR()
{
    s->moveR(20);
    repaint();
}

void MainWindow::paintEvent(QPaintEvent * e){
    QPainter painter(this);
    s->draw(&painter);
}

void MainWindow::on_pushButton_clicked()
{
    s->moveL(20);
    repaint();
}

void MainWindow::on_pushButton_2_clicked()
{
    s->moveR(20);
    repaint();
}

void MainWindow::on_pushButton_4_clicked()
{
    s->moveD(20);
    repaint();
}

void MainWindow::on_pushButton_3_clicked()
{
    s->moveU(20);
    repaint();
}

bool sal =false;
void MainWindow::on_pushButton_5_clicked()
{
    (sal) ? s->handDown() : s->salute();
    sal = !sal;
    repaint();
}
