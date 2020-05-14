#ifndef INFO_H
#define INFO_H

#include <QString>


class Info
{
public:
    Info(int,QString,QString,QString);
    ~Info();

    int getNum();
    QString getType();
    QString getPlace();
    QString getTime();

    void setNum(int);
    void setType(QString);
    void setPlace(QString);
    void setTime(QString);

    bool operator == (Info& other);

private:
    int num;
    QString type;
    QString place;
    QString time;

};

#endif // INFO_H
