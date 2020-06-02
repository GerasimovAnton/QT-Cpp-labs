#include "rect.h"

Rect::Rect()
{

}

void Rect::moveL(int step)
{
    x-= step;
}

void Rect::moveR(int step)
{
    x+=step;
}

void Rect::moveU(int step)
{
    y += step;
}

void Rect::moveD(int step)
{
    y -=step;
}

void Rect::drawR(QPainter *painter){
    painter->setPen(QPen(Qt::green, 4, Qt::SolidLine, Qt::FlatCap));
    painter->fillRect(x, y, 100, 150, Qt::green);
}

