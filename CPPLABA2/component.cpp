#include "component.h"

Component::Component()
{

}

Component::Component(QString type,QString brand,QString model,QString description)
{
    this->type = type;
    this->brand = brand;
    this->model = model;
    this->description = description;
}

