#include "soldier.h"

Soldier::Soldier(int px, int py)
{
    x = px;
    y = py;
}

void Soldier::handDown(){
    isSalute = false;
}

void Soldier::salute(){
    isSalute = true;
}

void Soldier::draw(QPainter *painter){
    drawR(painter);

    painter->setPen(QPen(Qt::green, 4, Qt::SolidLine, Qt::FlatCap));

    painter->drawLine(x + 98, y + 25, x + 150, y + 100);

    painter->drawLine(x + 25, y + 150, x + 25, y + 250);
    painter->drawLine(x + 75, y + 150, x + 75, y + 250);

    painter->setPen(QPen(Qt::white, 2, Qt::SolidLine, Qt::FlatCap));
    painter->setBrush(Qt::white);
    painter->drawEllipse(QPointF(x+25, y+250), 5, 5);
    painter->drawEllipse(QPointF(x+75, y+250), 5, 5);
    painter->drawEllipse(QPointF(x + 50, y - 50), 50, 50);
    painter->drawLine(x + 30, y - 27, x + 70, y - 27);
    painter->fillRect(x, y - 110, 100, 20, Qt::green);

    painter->setPen(QPen(Qt::white, 4, Qt::SolidLine, Qt::FlatCap));
    painter->setBrush(Qt::white);
    painter->drawEllipse(QPointF(x + 50, y - 50), 50, 50);

    painter->drawEllipse(QPointF(x + 150, y + 100), 5, 5);

    painter->setPen(QPen(Qt::red, 4, Qt::SolidLine, Qt::FlatCap));
    painter->drawLine(x + 30, y - 27, x + 70, y - 27);

    painter->setPen(QPen(Qt::black, 4, Qt::SolidLine, Qt::FlatCap));
    painter->drawLine(x + 50, y - 55, x + 50, y - 42);

    painter->setPen(QPen(Qt::blue, 4, Qt::SolidLine, Qt::FlatCap));
    painter->drawEllipse(QPointF(x + 30, y - 65), 2, 2);
    painter->drawEllipse(QPointF(x + 70, y - 65), 2, 2);

    painter->fillRect(x, y - 115, 100, 25, Qt::green);


    painter->setPen(QPen(Qt::green, 4, Qt::SolidLine, Qt::FlatCap));
    if (isSalute) {
        painter->drawLine(x, y + 25, x - 50, y - 12);
        painter->drawLine(x, y - 50, x - 50, y - 12);
        painter->setPen(QPen(Qt::white, 2, Qt::SolidLine, Qt::FlatCap));
        painter->setBrush(Qt::white);
        painter->drawEllipse(QPointF(x, y - 50), 5, 5);
    }
    else{
        painter->drawLine(x + 2, y + 25, x - 50, y + 100);
        painter->setPen(QPen(Qt::white, 2, Qt::SolidLine, Qt::FlatCap));
        painter->setBrush(Qt::white);
        painter->drawEllipse(QPointF(x - 50, y + 100), 5, 5);
    }
}
