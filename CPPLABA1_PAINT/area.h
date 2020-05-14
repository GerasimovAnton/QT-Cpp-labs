#ifndef AREA_H
#define AREA_H

#include <QColor>
#include <QPoint>
#include <QMouseEvent>
#include <QWidget>
#include <QPaintEvent>
#include "figure.h"
#include <QPainter>
#include <QPen>
#include <QPainter>
#include <vector>
#include "vector2.h"
#include "circle.h"
#include "polygon.h"
#include "mouseFlag.h"
#include "rect.h"
//#include <QObject>

class Canvas : public QWidget
{

   Q_OBJECT
public:
    QImage *image;
    QPainter *painter;

    Canvas();
    ~Canvas();

    void setPenColor(Qt::GlobalColor);
    void setPenSize(float size);

    void draw(Figure &figure);
    void drawBasePoints();

    void addFigure(Figure &figure);
    void moveAllFigures(Vector2&);
    void drawAllFigures();
    void cleanCanvas();
    void removeAllFigures();

    void setFlag(mouseFlag);
    void setSize(int w,int h);

    void moveAll(bool);

    Figure& currentFigure();

    std::vector<Figure*>& getAllFigures();

    bool isScribbling;

private:
    void moveFigures(Vector2 &newPos);
    mouseFlag flag = mouseFlag::center_point;
    QPen *pen;
    std::vector<Figure*> allFigures;
    Figure *curFigure = nullptr;
    bool mvAll = false;

signals:
    void setP(float);
    void setS(float);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
};

#endif // AREA_H
