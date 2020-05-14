#include "figure.h"
//#include "math.h"


void Figure::drawMethod(QPainter &painter)
{
    std::vector<Vector2*> &p = points;

    for(int i =0;i <p.size()-1;i++)
    {
        painter.drawLine(p[i]->x,p[i]->y,
                          p[(i+1)]->x,p[(i+1)]->y);
    }
}

Figure::Figure()
{
}

Figure::~Figure()
{
    delete pos;
    pos = nullptr;

    delete cen;
    cen = nullptr;

    for(Vector2* v: points)
    {
        delete v;
        v = nullptr;
    }
}

float Figure::length()
{
    float len  = 0;
    int size = points.size();

    for(int i = 0;i < size-1;i++)
    {
        len += points[i]->Distance(*points[(i+1)]);
    }

    return len;
}

void Figure::resize(float k)
{
    for(Vector2 *p: points)
    {
        p->x = cen->x + ((p->x - cen->x)*k);
        p->y = cen->y + ((p->y - cen->y)*k);
    }
}

void Figure::move(Vector2 &delta)
{
    if(this->points.size() != 0)
    {
        for(Vector2 *v: points)
        {
            v->x += delta.x;
            v->y += delta.y;
        }
    }

    this->pos->x += delta.x;
    this->pos->y += delta.y;

    cen->x += delta.x;
    cen->y += delta.y;
}

void Figure::rotate(float f)
{
    Vector2 *t = new Vector2(cen->x,cen->y);

    cen->y = pos->y + (t->x - pos->x)*sin(f) + (t->y - pos->y)*cos(f);
    cen->x = pos->x + (t->x - pos->x)*cos(f) - (t->y - pos->y)*sin(f);

    delete t;

    for(Vector2 *p: points)
    {
        Vector2 *tmp = new Vector2(p->x,p->y);

        p->y = pos->y + (tmp->x - pos->x)*sin(f) + (tmp->y - pos->y)*cos(f);
        p->x = pos->x + (tmp->x - pos->x)*cos(f)- (tmp->y - pos->y)*sin(f);

        delete tmp;
    }
}

Vector2 &Figure::center()
{  


    float maxx = points[0]->x,
          maxy = points[0]->y,
          minx = maxx,
          miny = maxy;


    for(Vector2 *v: points)
    {
        if(v->x > maxx) maxx = v->x;
        if(v->x < minx) minx = v->x;
        if(v->y > maxy) maxy = v->y;
        if(v->y < miny) miny = v->y;
    }

    float x =minx + (maxx - minx)/2, y = miny + (maxy - miny)/2;

//     float x = 0,y = 0;
//     for(Vector2 *v: points)
//     {
//              x +=v->x;
//              y +=v->y;
//     }

    if(cen == nullptr) cen = new Vector2(x,y);
    cen->x = x;
    cen->y = y;

//     cen->x = x/points.size();
//     cen->y = y/points.size();

     return *cen;
}

float Figure::square()
{
    float sq  = 0;
    int size = points.size();

    for(int i = 0;i < size;i++)
    {
        sq += (points[i]->x - points[(i+1)%size]->x)*(points[i]->y + points[(i+1)%size]->y);
    }

    return abs(sq)/2;
}

