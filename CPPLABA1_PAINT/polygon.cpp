#include "polygon.h"

Polygon::Polygon(Vector2& pos,int N,float R)
{
    this->pos = &pos;
    this->cen = new Vector2(pos.x,pos.y);
    this->N = N;

    float a = (360/N)*M_PI/180;
    points.push_back(new Vector2(pos.x + R,pos.y + R));

    for(int i = 0;i < N-1; i++)
    {
        float x,y;
        float px = points.back()->x,py = points.back()->y;

        x = pos.x + (px - pos.x)*cos(a) - (py - pos.y)*sin(a);
        y = pos.y + (py - pos.y)*cos(a) + (px - pos.x)*sin(a);

        points.push_back(new Vector2(x,y));
    }
}

//void Polygon::move(Vector2 &delta)
//{
//    pos->x += delta.x;
//    pos->y += delta.y;

//    cen->x += delta.x;
//    cen->y += delta.y;

//    for(Vector2 *v: points)
//    {
//        v->x += delta.x;
//        v->y += delta.y;
//    }
//}

void Polygon::drawMethod(QPainter &painter)
{
    std::vector<Vector2*> &p = points;

    for(int i =0;i <p.size();i++)
    {
        painter.drawLine(p[i]->x,p[i]->y,
                         p[(i+1)%(p.size())]->x,p[(i+1)%(p.size())]->y);
    }
}

