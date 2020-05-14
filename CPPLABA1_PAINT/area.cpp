#include "area.h"
#include <QLabel>
#include <QString>
//#include <QObject>

Canvas::Canvas()
{
    //this->parent = parent;
    //this->resize(400,400);
    painter = nullptr;

    image = new QImage(this->size().width(),this->size().height(),QImage::Format_ARGB32_Premultiplied);

    painter = new QPainter(image);

    pen = new QPen(Qt::red);

    pen->setWidth(5);
    pen->setCapStyle(Qt::RoundCap);
    pen->setJoinStyle(Qt::RoundJoin);

    painter->setPen(*pen);
}

Canvas::~Canvas()
{
    delete this->image;
    delete this->painter;
}

void Canvas::setPenColor(Qt::GlobalColor color)
{
    pen->setColor(color);
    painter->setPen(*pen);
}

void Canvas::setPenSize(float size)
{
    pen->setWidthF(size);
    painter->setPen(*pen);
}

Vector2 *beginPos = nullptr;
Vector2 *prevPos = nullptr;

void Canvas::setSize(int w, int h)
{
    QImage *newImage = new QImage(w,h,QImage::Format_ARGB32_Premultiplied);
    newImage->fill(0);

    delete painter;
    painter = new QPainter(newImage);
    painter->setPen(*pen);

    this->painter->drawImage(0,0,*image);
    delete image;

    image = newImage;
}

void Canvas::moveAll(bool mvAll)
{
    this->mvAll = mvAll;
}

Figure &Canvas::currentFigure()
{
    return *curFigure;
}

std::vector<Figure *> &Canvas::getAllFigures()
{
    return allFigures;
}

void Canvas::draw(Figure &figure)
{
    figure.drawMethod(*painter);
    update();
}

void Canvas::drawBasePoints()
{
    for(Figure *f : allFigures)
    {
        setPenColor(Qt::green);
        painter->drawEllipse(f->center().x,f->center().y,5,5);
        setPenColor(Qt::blue);
        painter->drawEllipse(f->pos->x,f->pos->y,5,5);
        setPenColor(Qt::red);
    }
}

void Canvas::addFigure(Figure &figure)
{
    curFigure = &figure;
    allFigures.push_back(&figure);
}

void Canvas::moveAllFigures(Vector2 &delta)
{
    for(Figure *f : allFigures)
    {
        f->move(delta);
    }
}

void Canvas::drawAllFigures()
{
    for(Figure *f : allFigures)
    {
        draw(*f);
    }

    drawBasePoints();
}

void Canvas::cleanCanvas()
{
//    for (Figure *f : allFigures)
//    {
//        delete f;
//        f = nullptr;
//    }

    //allFigures.clear();
    image->fill(0);
    update();
}

void Canvas::removeAllFigures()
{

    for (Figure *f : allFigures)
    {
       delete f;
       f = nullptr;
    }

    curFigure = nullptr;
    allFigures.clear();
}

void Canvas::setFlag(mouseFlag f)
{
 this->flag = f;
}

void Canvas::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(0,0,*image);
}

void Canvas::resizeEvent(QResizeEvent *event)
{
    setSize(this->size().width(),this->size().height());
}

void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    float x,y;

    x = event->x();
    y = event->y();

    if(event->buttons() == Qt::LeftButton){
        switch(flag)
        {
            case mouseFlag::center_point:
            break;
            case mouseFlag::closed_curve:
            case mouseFlag::curve:
                curFigure->points.push_back(new Vector2(x,y));
                draw(*curFigure);
            break;
        }

    }
    else if(event->buttons() == Qt::RightButton && curFigure != nullptr)
    {
       Vector2 *delta = new Vector2((x - prevPos->x)
                                    ,(y - prevPos->y));
       cleanCanvas();

       mvAll ? moveAllFigures(*delta) : curFigure->move(*delta);
       drawAllFigures();
    }


    prevPos->x = x;
    prevPos->y = y;
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
    isScribbling = 1;
    float x,y;

    x = event->x();
    y = event->y();

    Vector2 *np = new Vector2(x,y);

    beginPos = new Vector2(x,y);
    prevPos = new Vector2(x,y);

    if(event->buttons() == Qt::LeftButton){
        switch(flag)
        {
            case mouseFlag::center_point:
               if(curFigure != nullptr)
               {
                    delete curFigure->pos;
                    curFigure->pos = np;

                    drawBasePoints();
               }
            break;

            case mouseFlag::closed_curve:
            case mouseFlag::curve:
                curFigure = new Figure();
                curFigure->points.push_back(np);
                allFigures.push_back(curFigure);
            break;
        }
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{
    isScribbling = 0;
    float x,y;

    x = event->x();
    y = event->y();

    if(event->button() == Qt::LeftButton && flag != mouseFlag::center_point){
        curFigure->points.push_back(new Vector2(x,y));

        if(flag == mouseFlag::closed_curve)
        {
            curFigure->points.push_back(new Vector2(curFigure->points[0]->x,curFigure->points[0]->y));

            //Vector2 &fp = *curFigure->points[0];
            //Vector2 &lp = *curFigure->points.back();

            //float dx = abs(fp.x - lp.x),dy = abs(fp.y - lp.y);

            emit setS(curFigure->square());
        }

        curFigure->center();
        curFigure->pos = new Vector2(curFigure->center().x,curFigure->center().y);

        draw(*curFigure);
        setPenColor(Qt::green);
        painter->drawEllipse(curFigure->center().x,curFigure->center().y,5,5);
        setPenColor(Qt::red);

        if(curFigure != nullptr) emit setP(curFigure->length());
    }
}
