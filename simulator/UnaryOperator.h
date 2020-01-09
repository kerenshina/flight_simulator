#ifndef EXPRESSIONS_UNARY_OPERATOR_H
#define EXPRESSIONS_UNARY_OPERATOR_H

#include "Expression.h"

using namespace std;

class UnaryOperator: public Expression {

protected:
    Expression *exp;

public:
    UnaryOperator(Expression *exp);
    virtual double calculate() = 0;
};

class UPlus: public UnaryOperator {
public:
    UPlus(Expression* exp1);
    double calculate();
    ~UPlus();
};

class UMinus: public UnaryOperator {
public:
    UMinus(Expression* exp1);
    double calculate();
    ~UMinus();
};

#endif //EXPRESSIONS_UNARY_OPERATOR_H
