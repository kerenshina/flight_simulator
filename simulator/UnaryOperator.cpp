#define NULL nullptr
#include "UnaryOperator.h"
#include "Expression.h"

using namespace std;

UnaryOperator::UnaryOperator(Expression *exp) {
    this->exp = exp;
}

UPlus::UPlus(Expression* exp1) : UnaryOperator(exp) {
    this->exp = exp1;
}

double UPlus::calculate() {
    return exp->calculate();
}

UPlus::~UPlus() {
    if (exp != NULL)
    {
        delete(this->exp);
    }
}

UMinus::UMinus(Expression* exp1) : UnaryOperator(exp) {
    this->exp = exp1;
}

double UMinus::calculate() {
    return -(exp->calculate());
}

UMinus::~UMinus() {
    if (exp != NULL)
    {
        delete(this->exp);
    }
}
