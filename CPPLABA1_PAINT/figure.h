#ifndef FIGURE_H
#define FIGURE_H

#include <vector>
#include "vector2.h"
#include "math.h"
#include <QPainter>

#include <functional>

class Figure
{
public:
    Figure();
    ~Figure();

    virtual float square();
    virtual float length();
    virtual void resize(float);

    virtual void move(Vector2& delta);
    virtual void rotate(float);

    virtual Vector2& center();

    Vector2 *pos = nullptr;
    Vector2 *cen = nullptr;

    std::vector<Vector2*> points;

    //typedef void (Figure::*drawMethodPtr)(QPainter&);
    //drawMethodPtr pt;


    //std::function<void(QPainter&)> drawMethodF;

//protected:
    virtual void drawMethod(QPainter&);
};

#endif
