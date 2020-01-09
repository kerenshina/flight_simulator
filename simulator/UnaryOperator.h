#ifndef EXPRESSIONS_UNARY_OPERATOR_H
#define EXPRESSIONS_UNARY_OPERATOR_H

#include "Expression.h"

using namespace std;

class UnaryOperator: public Expression {

<<<<<<< HEAD
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
=======
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
>>>>>>> da606779dfbbd53e2ef3cbc2a726be7dff63a512
};

#endif //EXPRESSIONS_UNARY_OPERATOR_H
