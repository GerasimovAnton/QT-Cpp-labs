#ifndef RECT_H
#define RECT_H
#include <QPainter>

class Rect
{
public:
    Rect();

    void moveL(int);
    void moveR(int);
    void moveU(int);
    void moveD(int);

protected:
    int x, y;
    void drawR(QPainter *painter);
};

#endif // RECT_H
