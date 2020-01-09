<<<<<<< HEAD
#ifndef EXPRESSIONS_BINARY_OPERATOR_H
#define EXPRESSIONS_BINARY_OPERATOR_H
=======
#ifndef SIMULATOR_BINARY_OPERATOR_H
#define SIMULATOR_BINARY_OPERATOR_H
>>>>>>> da606779dfbbd53e2ef3cbc2a726be7dff63a512

#include "Expression.h"

using namespace std;

class BinaryOperator: public Expression {

<<<<<<< HEAD
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


#endif //EXPRESSIONS_BINARY_OPERATOR_H
=======
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
>>>>>>> da606779dfbbd53e2ef3cbc2a726be7dff63a512
