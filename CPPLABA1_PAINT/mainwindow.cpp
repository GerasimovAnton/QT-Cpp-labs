#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "area.h"
#include <QLabel>
#include <QImage>
#include <QTimer>

#define REAL_SIZE_CONST 50

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->radioButton_2->setDown(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setCanvas(Canvas &cnv)
{
    this->canvas = &cnv;
}

void MainWindow::setPS(float p, float s)
{
    ui->label_2->setText("P = " +QString::number(p/REAL_SIZE_CONST) + " cm");
    ui->label_3->setText("S = " +QString::number( s/(REAL_SIZE_CONST*REAL_SIZE_CONST)) + " cm^2");
}

bool tm = 0;
void MainWindow::setTimer(bool b)
{
    tm = b;
    float t = ui->lineEdit_5->text().toFloat();


    canvas->setFlag(mouseFlag::center_point);
    if(t <=0 ) return;

    if(tm == 1){

        if(t <= 0) return;

        timer = new QTimer(this);

        connect(timer, SIGNAL(timeout()), this,SLOT(rotate()));
        connect(timer, SIGNAL(timeout()), this,SLOT(resize()));

        timer->start(t*1000);

        ui->pushButton_10->setText("del Timer");
    } else {

        timer->stop();
        delete timer;

        ui->pushButton_10->setText("add Timer");
    }
}

void MainWindow::resize()
{
    float k = ui->lineEdit_3->text().toFloat();

    if(k <= 0) return;
    canvas->cleanCanvas();

    if(!allObjectsInfl){
        if(&canvas->currentFigure() != nullptr)
        {
            canvas->currentFigure().resize(k);
        }
    } else {
        for (Figure *fg : canvas->getAllFigures()) {
            fg->resize(k);
        }
    }

    canvas->drawAllFigures();
}

void MainWindow::rotate()
{
    float f = ui->lineEdit_4->text().toFloat()*M_PI/180;

   // if(f == 0) return;
    canvas->cleanCanvas();

    if(!allObjectsInfl){
        if(&canvas->currentFigure() != nullptr)
        {
            canvas->currentFigure().rotate(f);
        }
    } else {
        for (Figure *fg : canvas->getAllFigures()) {
            fg->rotate(f);
        }
    }

    canvas->drawAllFigures();
}

void MainWindow::setP(float p)
{
    ui->label_2->setText("P = "+ QString::number(p/REAL_SIZE_CONST)+ " cm");
}

void MainWindow::setS(float s)
{
    ui->label_3->setText("S = " + QString::number(s/(REAL_SIZE_CONST*REAL_SIZE_CONST))+ " cm^2");
}


void MainWindow::on_pushButton_clicked()
{
    if(tm) setTimer(0);
    canvas->cleanCanvas();
    canvas->removeAllFigures();

    canvas->setFlag(mouseFlag::curve);
    setPS(0,0);
}

//Polygon
void MainWindow::on_pushButton_6_clicked()
{
    float r = ui->lineEdit_2->text().toFloat();
    int n = ui->lineEdit->text().toInt();


    if(r <= 0 || n <= 0) return;
    Polygon *p = new Polygon(*(new Vector2(canvas->width()/2,canvas->height()/2)),n,r*REAL_SIZE_CONST);
    canvas->addFigure(*p);
    canvas->drawAllFigures();

    setPS(p->length(),p->square());
}


//Circle
void MainWindow::on_pushButton_5_clicked()
{
    float r = ui->lineEdit_2->text().toFloat() * REAL_SIZE_CONST;

    if(r <= 0) return;
    Circle *c = new Circle(*(new Vector2(canvas->width()/2,canvas->height()/2)),r);


    canvas->addFigure(*c);
    //canvas->Draw(*c);
    canvas->drawAllFigures();

    setPS(c->length(),c->square());
}

//Curve
void MainWindow::on_pushButton_4_clicked()
{
    if(tm) setTimer(0);
    canvas->setFlag(mouseFlag::curve);
}

//Closed Curve
void MainWindow::on_pushButton_3_clicked()
{
    if(tm) setTimer(0);
    canvas->setFlag(mouseFlag::closed_curve);
}


//Rectange
void MainWindow::on_pushButton_7_clicked()
{
    float a = ui->lineEdit_2->text().toFloat();

    if(a <= 0) return;

    Rect *r = new Rect(*(new Vector2(canvas->width()/2,canvas->height()/2)),a*REAL_SIZE_CONST);
    //canvas->draw(*r);
    canvas->addFigure(*r);
    canvas->drawAllFigures();
    setPS(r->length(),r->square());
}

void MainWindow::on_lineEdit_2_selectionChanged()
{

}

void MainWindow::on_lineEdit_2_textEdited(const QString &arg1)
{

}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    //ui->lineEdit_2->setText("");
}

void MainWindow::on_lineEdit_2_windowIconTextChanged(const QString &iconText)
{

}

void MainWindow::on_lineEdit_2_cursorPositionChanged(int arg1, int arg2)
{

}



//resize
void MainWindow::on_pushButton_8_clicked()
{
   resize();
}
//rotate
void MainWindow::on_pushButton_9_clicked()
{
   rotate();
}

void MainWindow::on_pushButton_2_clicked()
{
    canvas->setFlag(mouseFlag::center_point);
}

void MainWindow::on_radioButton_clicked()
{
    ui->radioButton_2->setDown(false);
    allObjectsInfl = 1;
    canvas->moveAll(true);
}

void MainWindow::on_radioButton_2_clicked()
{
    ui->radioButton->setDown(false);
    allObjectsInfl = 0;
    canvas->moveAll(false);
}



//Timer
void MainWindow::on_pushButton_10_clicked()
{
    tm ? setTimer(0) : setTimer(1);
}
