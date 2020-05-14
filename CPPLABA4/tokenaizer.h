#ifndef TOKENAIZER_H
#define TOKENAIZER_H

#include <QChar>
#include <QString>
#include <list.h>

class Tokenaizer
{
public:
    Tokenaizer();
    List<QChar> splitByToken(QString expression,QChar token);
};

#endif // TOKENAIZER_H
