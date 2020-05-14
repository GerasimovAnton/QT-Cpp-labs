#include "operation.h"

Operation::Operation(double (*func)(double left,double right),int priority)
{
    this->priority = priority;
    this->func = func;
}


double Operation::apply(double left,double right)
{
    if(func == nullptr) return -1; // Надо бы кидать ошибку а не -1
    else return func(left,right);
}
