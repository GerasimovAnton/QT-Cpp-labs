#ifndef OPERATION_H
#define OPERATION_H


class Operation
{
public:
    Operation(double(*)(double ,double),int);
    double apply(double  left,double right);
    int priority = 0;

private:
    double(*func)(double ,double) = nullptr;
};

#endif // OPERATOR_H
