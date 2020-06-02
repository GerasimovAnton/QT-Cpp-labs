#ifndef SOLDIER_H
#define SOLDIER_H
#include <QPainter>
#include <rect.h>


class Soldier: public Rect
{
public:
    Soldier(int,int);
    void handDown();
    void salute();
    void draw(QPainter *painter);

private:
    bool isSalute = false;
};

#endif // SOLDIER_H
