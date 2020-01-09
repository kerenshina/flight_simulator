#ifndef SIMULATOR_BINARY_OPERATOR_H
#define SIMULATOR_BINARY_OPERATOR_H

#include "Expression.h"

using namespace std;

class BinaryOperator: public Expression {

protected:
    Expression *right, *left;

public:
    BinaryOperator(Expression *right, Expression *left);
    virtual double calculate() = 0;
};

class Plus: public BinaryOperator {
public:
    Plus(Expression* exp1, Expression* exp2);
    double calculate();
    ~Plus();
};

class Minus: public BinaryOperator {
public:
    Minus(Expression* exp1, Expression* exp2);
    double calculate();
    ~Minus();
};

class Mul: public BinaryOperator {
public:
    Mul(Expression* exp1, Expression* exp2);
    double calculate();
    ~Mul();
};

class Div: public BinaryOperator {
public:
    Div(Expression* exp1, Expression* exp2);
    double calculate();
    ~Div();
};


#endif //SIMULATOR_BINARY_OPERATOR_H