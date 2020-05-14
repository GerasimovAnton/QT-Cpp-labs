#ifndef RECT_H
#define RECT_H
#include "figure.h"
#include "polygon.h"
#include "vector2.h"

class Rect :public Polygon
{
public:
    Rect(Vector2& pos,float r);
};

#endif // RECT_H
