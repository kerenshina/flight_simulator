<<<<<<< HEAD
#ifndef PROJECT_EX1_H
#define PROJECT_EX1_H

#include "Expression.h"
#include <queue>
#include <string>
#include <stack>

using namespace std;


class BinaryOperator: public Expression {

protected:
    Expression *right, *left;

public:
    BinaryOperator(Expression *right, Expression *left);
    virtual double calculate() = 0;
};

class UnaryOperator: public Expression {

protected:
    Expression *exp;

public:
    UnaryOperator(Expression *exp);
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

class Value: public Expression {
private:
    const double val;

public:
    Value(double value) : val(value) {};
    double calculate();
};

class RelationalOperator {

protected:
    Expression *right, *left;

public:
    RelationalOperator(Expression *right, Expression *left);
    virtual bool compare() = 0;
};

class Greater: public RelationalOperator {
public:
    Greater(Expression* exp1, Expression* exp2);
    bool compare();
    ~Greater();

};

class Smaller: public RelationalOperator {
public:
    Smaller(Expression* exp1, Expression* exp2);
    bool compare();
    ~Smaller();

};

class Equal: public RelationalOperator {
public:
    Equal(Expression* exp1, Expression* exp2);
    bool compare();
    ~Equal();

};

class NotEqual: public RelationalOperator {
public:
    NotEqual(Expression* exp1, Expression* exp2);
    bool compare();
    ~NotEqual();

};

class GreaterEqual: public RelationalOperator {
public:
    GreaterEqual(Expression* exp1, Expression* exp2);
    bool compare();
    ~GreaterEqual();

};

class SmallerEqual: public RelationalOperator {
public:
    SmallerEqual(Expression* exp1, Expression* exp2);
    bool compare();
    ~SmallerEqual();

};
class ExpressionInterpreter {
private:
    queue<string> output;
    stack<char> operations;
    vector< pair <string, string> > variables;

public:
    Expression* interpret(string tokens);
    void setVariables(string vars);
};


#endif
=======
//#ifndef PROJECT_EX1_H
//#define PROJECT_EX1_H
//
//#include "Expression.h"
//#include <queue>
//#include <string>
//#include <stack>
//
//using namespace std;
//
//
//class BinaryOperator: public Expression {
//
//protected:
//    Expression *right, *left;
//
//public:
//    BinaryOperator(Expression *right, Expression *left);
//    virtual double calculate() = 0;
//};
//
//class UnaryOperator: public Expression {
//
//protected:
//    Expression *exp;
//
//public:
//    UnaryOperator(Expression *exp);
//    virtual double calculate() = 0;
//};
//
//class Plus: public BinaryOperator {
//public:
//    Plus(Expression* exp1, Expression* exp2);
//    double calculate();
//    ~Plus();
//
//};
//
//class Minus: public BinaryOperator {
//public:
//    Minus(Expression* exp1, Expression* exp2);
//    double calculate();
//    ~Minus();
//};
//
//class Mul: public BinaryOperator {
//public:
//    Mul(Expression* exp1, Expression* exp2);
//    double calculate();
//    ~Mul();
//};
//
//class Div: public BinaryOperator {
//public:
//    Div(Expression* exp1, Expression* exp2);
//    double calculate();
//    ~Div();
//};
//
//class UPlus: public UnaryOperator {
//public:
//    UPlus(Expression* exp1);
//    double calculate();
//    ~UPlus();
//};
//
//class UMinus: public UnaryOperator {
//public:
//    UMinus(Expression* exp1);
//    double calculate();
//    ~UMinus();
//};
//
//class Value: public Expression {
//private:
//    const double val;
//
//public:
//    Value(double value) : val(value) {};
//    double calculate();
//};
//
//class RelationalOperator {
//
//protected:
//    Expression *right, *left;
//
//public:
//    RelationalOperator(Expression *right, Expression *left);
//    virtual bool compare() = 0;
//};
//
//class Greater: public RelationalOperator {
//public:
//    Greater(Expression* exp1, Expression* exp2);
//    bool compare();
//    ~Greater();
//
//};
//
//class Smaller: public RelationalOperator {
//public:
//    Smaller(Expression* exp1, Expression* exp2);
//    bool compare();
//    ~Smaller();
//
//};
//
//class Equal: public RelationalOperator {
//public:
//    Equal(Expression* exp1, Expression* exp2);
//    bool compare();
//    ~Equal();
//
//};
//
//class NotEqual: public RelationalOperator {
//public:
//    NotEqual(Expression* exp1, Expression* exp2);
//    bool compare();
//    ~NotEqual();
//
//};
//
//class GreaterEqual: public RelationalOperator {
//public:
//    GreaterEqual(Expression* exp1, Expression* exp2);
//    bool compare();
//    ~GreaterEqual();
//
//};
//
//class SmallerEqual: public RelationalOperator {
//public:
//    SmallerEqual(Expression* exp1, Expression* exp2);
//    bool compare();
//    ~SmallerEqual();
//
//};
//class ExpressionInterpreter {
//private:
//    queue<string> output;
//    stack<char> operations;
//    vector< pair <string, string> > variables;
//
//public:
//    Expression* interpret(string tokens);
//    void setVariables(string vars);
//};
//
//
//#endif
>>>>>>> da606779dfbbd53e2ef3cbc2a726be7dff63a512
