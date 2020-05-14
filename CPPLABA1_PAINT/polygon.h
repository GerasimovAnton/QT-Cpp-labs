#ifndef POLYGON_H
#define POLYGON_H
#include "figure.h"

class Polygon :public Figure
{
public:
    Polygon(Vector2&,int,float);
    //Vector2& center() override;
    //void move(Vector2&) override;
    void drawMethod(QPainter &) override;

private:
    int N;
};

#endif // POLYGON_H
