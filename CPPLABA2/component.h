#ifndef COMPONENT_H
#define COMPONENT_H

#include <QString>

class Component
{
public:
    Component();
    Component(QString type,QString brand,QString model,QString params);


    QString type;
    QString brand;
    QString model;
    QString description;

    int cost;
    int count;
};

#endif // COMPONENT_H
