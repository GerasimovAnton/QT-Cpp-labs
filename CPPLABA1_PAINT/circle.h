#ifndef CIRCLE_H
#define CIRCLE_H

#include "figure.h"

class Circle : public Figure
{
public:
    Circle(Vector2&,float);
    Vector2& center() override;

    float square() override;
    float length() override;
    void resize(float) override;
    void move(Vector2&) override;
    void drawMethod(QPainter &) override;
    void rotate(float) override;

private:
    float r;
};

#endif // CIRCLE_H
