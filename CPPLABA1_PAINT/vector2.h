#ifndef VECTOR2_H
#define VECTOR2_H


class Vector2
{
public:
    Vector2(float,float);
    ~Vector2();

    float x;
    float y;

    float Distance(Vector2 &other);
    float Distance(int,int);
};

#endif // VECTOR2_H
