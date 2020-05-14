#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "component.h"

Component **ComponentList;
int listSize;

void addElement(Component **&,int &,Component *);
void deleteElement(Component **&,int &,int);

void readInfo(QString,Component **&,int &);
void writeInfo(QString,Component **&,int &);

void reverse(Component **&,int);
void ascendingPrice(Component **&,int);


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    listSize = 0;

    readInfo(":/info/res/database.txt",ComponentList,listSize);
    drawList();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void writeInfo(QString fileName,Component **&info,int &size)
{
    QFile file(fileName);
    file.open(QFile::WriteOnly);

    QTextStream out(&file);

    out << size;


    for(int i = 0;i < size;i++){
        out << "\n" << info[i]->type;
        out << "\n" << info[i]->brand;
        out << "\n" << info[i]->model;
        out << "\n" << info[i]->cost;
        out << "\n" << info[i]->count;
        out << "\n" << info[i]->description.size();
        out << "\n" << info[i]->description;
    }

    file.close();
}

void readInfo(QString fileName,Component **&info,int &size)
{
    QFile file(fileName);
    file.open(QFile::ReadOnly);
    QTextStream in(&file);
    QString s = in.readLine();

    size = s.toInt();

    Component** cmp = new Component*[size];
    QString type,brand,model,description;

    for (int i = 0;i < size;i++) {

        type = in.readLine();
        brand = in.readLine();
        model = in.readLine();
        int cost = in.readLine().toInt();
        int count = in.readLine().toInt();


        int r = in.readLine().toInt();

        description = in.read(r);
        in.readLine();

        cmp[i] = new Component(type,brand,model,description);
        cmp[i] ->cost = cost;
        cmp[i] ->count = count;
    }

    delete [] info;
    info = cmp;
    file.close();
}

void reverse(Component **&cmp,int listSize)
{
     for (int i = 0,j = listSize-1; i < listSize/2; i++,j--)
     {
       Component *tmp = cmp[i];
       cmp[i] = cmp[j];
       cmp[j] = tmp;
     }
}

void ascendingPrice(Component **&cmp,int listSize)
{
    Component *tmp;
    for (int i = 1, j; i < listSize; ++i)
    {
        tmp = cmp[i];

        for (j = i - 1; j >= 0 && cmp[j]->cost > tmp->cost; --j)
         cmp[j+1] = cmp[j];
         cmp[j+1] = tmp;
    }
}

void addElement(Component **&arr,int &size,Component *element)
{
    Component** cmp = new Component *[size + 1];

    for(int i = 0,r = 0;i < size;i++ )
    {
        cmp[i] = arr[i];
    }

    cmp[size] = element;
    size++;

    delete [] arr;
    arr = cmp;
}

void deleteElement(Component **&arr,int &size,int num)
{
    if(size == 0) return;

    Component** cmp = new Component *[size - 1];
    for(int i = 0,r = 0;i < size;i++ )
    {
        if(i != num)
        {
            cmp[r] = arr[i];
            r++;
        }
    }

    delete [] arr;
    arr = cmp;
    size--;
}



void MainWindow::on_pushButton_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "");
    readInfo(file_name,ComponentList,listSize);

    ui->listWidget->clear();
    drawList();
}
//DELETE_ELEMENT
void MainWindow::on_pushButton_2_clicked()
{
    int r = ui->listWidget->currentRow();
    ui->listWidget->clear();

    deleteElement(ComponentList,listSize,r);
    drawList();
}

void MainWindow::drawList()
{
    if(ComponentList != nullptr && listSize != 0)
    for (int i =0;i<listSize;i++) {
        ui->listWidget->addItem("Brand: "+ ComponentList[i]->brand+"\n"
                                +"Type: "+ ComponentList[i]->type+"\n"
                                +"Model: "+ComponentList[i]->model+"\n"
                                +"Price: " + QString::number( ComponentList[i]->cost) + "$"+
                                "   In Stock: "+ QString::number(ComponentList[i]->count)+
                                "\n______________________________________");
    }
}

void MainWindow::on_listWidget_itemSelectionChanged()
{
    //ui->textEdit->setText(QString::number(ui->listWidget->currentRow()));
    ui->textEdit->setText(ComponentList[ui->listWidget->currentRow()]->description);
}
//SAVE
void MainWindow::on_pushButton_3_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "");
    writeInfo(file_name,ComponentList,listSize);
}

void MainWindow::on_addComponentBttn_clicked()
{
    Component *cmp = new Component(ui->lineEdit_type->text(),
                                   ui->lineEdit_brand->text(),
                                   ui->lineEdit_model->text(),
                                   ui->plainTextEdit->toPlainText());

    cmp->cost = ui->lineEdit_cost->text().toInt();
    cmp->count = ui->lineEdit_count->text().toInt();

    addElement(ComponentList,listSize,cmp);

    ui->listWidget->clear();
    drawList();
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if(index == 1) ascendingPrice(ComponentList,listSize);
    if(index == 2) {
        ascendingPrice(ComponentList,listSize);
        reverse(ComponentList,listSize);
    }

    ui->listWidget->clear();
    drawList();
}



