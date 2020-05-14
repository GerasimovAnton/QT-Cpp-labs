#include "vector2.h"
#include <math.h>


Vector2::Vector2(float x,float y)
{
    this->x = x;
    this->y = y;
}

Vector2::~Vector2()
{

}

float Vector2::Distance(Vector2 &other)
{
        return sqrt((this->x - other.x) * (this->x - other.x) +
                    (this->y - other.y) * (this->y - other.y));
}

float Vector2::Distance(int x, int y)
{
    return sqrt((this->x - x) * (this->x - x) +
                (this->y - y) * (this->y - y));
}
