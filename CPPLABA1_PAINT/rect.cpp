#include "rect.h"
#include <math.h>


Rect::Rect(Vector2& pos,float r) : Polygon(pos,4,r*sqrt(2)/2)
{
    this->pos = &pos;
    this->cen = new Vector2(pos.x,pos.y);
}

