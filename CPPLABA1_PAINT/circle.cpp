#include "circle.h"
#include <math.h>

Circle::Circle(Vector2 &pos,float r)
{
    this->pos = &pos;
    this->cen = new Vector2(pos.x,pos.y);
    //this->cen = &pos;
    this->r = r;
}

Vector2 &Circle::center()
{
    return *cen;
}

float Circle::square()
{
    return M_PI*r*r;
}

float Circle::length()
{
    return 2*M_PI*r;
}

void Circle::resize(float size)
{
    r *= size;
}

void Circle::move(Vector2& delta)
{
   this->pos->x += delta.x;
   this->pos->y += delta.y;

   this->cen->x += delta.x;
   this->cen->y += delta.y;
}

void Circle::drawMethod(QPainter &painter)
{
    painter.drawEllipse(cen->x - r,cen->y - r,2*r,2*r);
}

void Circle::rotate(float f)
{
    Vector2 *tmp = new Vector2(cen->x,cen->y);

    cen->y = pos->y + (tmp->x - pos->x)*sin(f) + (tmp->y - pos->y)*cos(f);
    cen->x = pos->x + (tmp->x - pos->x)*cos(f)- (tmp->y - pos->y)*sin(f);

    delete tmp;
}
