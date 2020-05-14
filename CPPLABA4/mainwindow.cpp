#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "operation.h"
#include <QMap>
#include <stack>
#include <QMessageBox>



QMap<QChar,Operation *> operations;
QMap<QChar,double> variables;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    Operation *add = new Operation([](double l,double r){return l+r;},1);
    Operation *sub = new Operation([](double l,double r){return r-l;},1);
    Operation *mul = new Operation([](double l,double r){return l*r;},2);
    Operation *div = new Operation([](double l,double r){return r/l;},2);

    operations.insert('+',add);
    operations.insert('-',sub);
    operations.insert('*',mul);
    operations.insert('/',div);

    operations.insert('(',new Operation(nullptr,3));
    operations.insert(')',new Operation(nullptr,0));

    ui->setupUi(this);

    //ui->tableWidget->setRowCount(2);
    ui->tableWidget->setColumnCount(2);


    //EXAMPLE
    ui->tableWidget->setRowCount(2);
    ui->tableWidget->setItem(0,0,new QTableWidgetItem("a"));
    ui->tableWidget->setItem(0,1,new QTableWidgetItem("1"));
    ui->tableWidget->setItem(1,0,new QTableWidgetItem("b"));
    ui->tableWidget->setItem(1,1,new QTableWidgetItem("2"));

    ui->lineEdit->setText("a+b");
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::infixToPostfix(QString expression)
{
    std::stack<QChar> _stack;
    QString s;
    for(auto c : expression)
    {
        if(!operations.contains(c) && !variables.contains(c)){
            QMessageBox::information(this,"ERROR","Variable or operand not defined");
            return "";
        }
        if(!operations.contains(c) && variables.contains(c)) s+=c;
        else
        {
            while(!_stack.empty() && operations[_stack.top()]->priority >= operations[c]->priority && _stack.top() != '(')
            {
                s += _stack.top();
                _stack.pop();
            }
            _stack.push(c);

            //delete ()
            if (!_stack.empty() && _stack.top() == ')'){ _stack.pop();_stack.pop();}
        }
    }

    while (!_stack.empty()){
        s += _stack.top();
        _stack.pop();
    }

    return s;
}

void trim(QString &expression)
{
    expression.remove(' ');
}

double MainWindow::calcExpression(QString expression)
{
    if(expression == "") return 0;
    std::stack<double> _stack;

    for(auto c:expression)
    {
        if(variables.contains(c)) _stack.push(variables[c]);
        else if(operations.contains(c))
        {
            double l =_stack.top();
            double r =*(&_stack.top()-1);

            _stack.pop();
            _stack.pop();

            _stack.push( operations[c]->apply(l,r));
        }

    }

    return _stack.top();
}

void MainWindow::loadVariables()
{
    int r = ui->tableWidget->rowCount();

    ui->tableWidget->update();
    variables.clear();

    for(int i = 0;i < r ; i++)
    {
        if((ui->tableWidget->item(i,0)) == nullptr) return;

        if((ui->tableWidget->item(i,1)) == nullptr){
            QTableWidgetItem *t = new QTableWidgetItem();
            t->setText("0");
            ui->tableWidget->setItem(i,1,t);
            ui->tableWidget->update();
        }

        QChar c = ui->tableWidget->item(i,0)->text().data()[0];
        int n = ui->tableWidget->item(i,1)->text().toInt();



        if(!variables.contains(c))
         variables.insert(c,n);
    }
}

//SOLVE
void MainWindow::on_pushButton_clicked()
{
     QString str = ui->lineEdit->text();

     trim(str);
     loadVariables();

     QString s = infixToPostfix(str);

     ui->lineEdit_2->setText(s);

     if(s != "")
     ui->lineEdit->setText(ui->lineEdit->text() +" = " + QString::number( calcExpression(s)));

    //trim(str);

    //ui->lineEdit->setText(QString::number( operations['*']->apply(1,2)));

}


//ADD Variable
void MainWindow::on_pushButton_3_clicked()
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
}

//Delete Variable
void MainWindow::on_pushButton_4_clicked()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}

void MainWindow::on_lineEdit_selectionChanged()
{
   ui->lineEdit->clear();
}
