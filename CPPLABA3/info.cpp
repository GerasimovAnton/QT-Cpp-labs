#include "info.h"

Info::Info(int num,QString type,QString place,QString time)
{
    this->num = num;
    this->type = type;
    this->place = place;
    this->time = time;
}

bool Info::operator == (Info& other)
{
    return (other.getNum() == 0 || this->getNum()==other.getNum()) &&
           (other.getTime() == "" || this->getTime()==other.getTime()) &&
           (other.getType() == "" || this->getType()==other.getType()) &&
           (other.getPlace() == "" || this->getPlace()==other.getPlace());

}


int Info::getNum(){
    return num;
}
QString Info::getType()
{
    return type;
}
QString Info::getPlace()
{
    return place;
}
QString Info::getTime()
{
    return time;
}


void Info::setNum(int num)
{
    this->num = num;
}
void Info::setType(QString type)
{
    this->type = type;
}
void Info::setPlace(QString place)
{
    this->place = place;
}
void Info::setTime(QString time)
{
    this->time = time;
}


