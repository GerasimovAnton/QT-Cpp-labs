#include "tokenaizer.h"

Tokenaizer::Tokenaizer()
{

}


List<QChar> Tokenaizer::splitByToken(QString expression,QChar token)
{
    List<QChar> l;

    for(auto s : expression)
    {
        if(s != token)
        l.pushBack(s);
    }

    return l;
}
