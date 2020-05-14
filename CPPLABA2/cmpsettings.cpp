#include "cmpsettings.h"
#include "ui_cmpsettings.h"
#include "mainwindow.h"
#include "component.h"

cmpSettings::cmpSettings(QWidget *parent) :QWidget(parent),ui(new Ui::cmpSettings)
{
    ui->setupUi(this);
}

cmpSettings::~cmpSettings()
{
    delete ui;
}

//SAVE Settings
void cmpSettings::on_pushButton_clicked()
{
//    ui->lineEdit->text();

//    Component *cmp = new Component(ui->lineEdit->text(),
//                                   ui->lineEdit_2->text(),
//                                   ui->lineEdit_4->text(),
//                                   ui->lineEdit_5->text());


//    cmp->cost = ui->lineEdit_6->text().toInt();


}
