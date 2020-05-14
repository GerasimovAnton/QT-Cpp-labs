#include "mainwindow.h"

#include <QApplication>
#include <QComboBox>
#include <QPushButton>

#include "area.h"
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //int w,h;
    //w = 600;
    //h = 300;

    MainWindow w;
    Canvas canvas;

    w.show();
//    canvas.show();
    canvas.window()->setGeometry(w.x(),w.y()+w.height(),w.width(),500);
    canvas.setWindowFlags(Qt::WindowType::Drawer);
    canvas.show();

    w.setCanvas(canvas);

    QObject::connect(&canvas, &Canvas::setP, &w, &MainWindow::setP);
    QObject::connect(&canvas, &Canvas::setS, &w, &MainWindow::setS);

    canvas.setFlag(mouseFlag::curve);



    return a.exec();
}
