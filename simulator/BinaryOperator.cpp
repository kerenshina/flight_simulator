#define NULL nullptr
#include "BinaryOperator.h"
#include "Expression.h"

BinaryOperator::BinaryOperator(Expression *right, Expression *left) {
    this->left = left;
    this->right = right;
}

Plus::Plus(Expression* exp1, Expression* exp2) : BinaryOperator(right, left) {
    this->right = exp1;
    this->left = exp2;
}
double Plus::calculate() {
    return right->calculate() + left->calculate();
}
Plus::~Plus() {
    if (right != NULL)
    {
        delete(this->right);
    }

    if (left != NULL)
    {
        delete(this->left);
    }
}

Minus::Minus(Expression* exp1, Expression* exp2) : BinaryOperator(right, left) {
    this->right = exp1;
    this->left = exp2;
}

double Minus::calculate() {
    return right->calculate() - left->calculate();
}

Minus::~Minus() {
    if (right != NULL)
    {
        delete(this->right);
    }

    if (left != NULL)
    {
        delete(this->left);
    }
}

Mul::Mul(Expression* exp1, Expression* exp2) : BinaryOperator(right, left) {
    this->right = exp1;
    this->left = exp2;
}

double Mul::calculate() {
    return right->calculate() * left->calculate();
}

Mul::~Mul() {
    if (right != NULL)
    {
        delete(this->right);
    }

    if (left != NULL)
    {
        delete(this->left);
    }
}

Div::Div(Expression* exp1, Expression* exp2) : BinaryOperator(right, left) {
    this->right = exp1;
    this->left = exp2;
}

double Div::calculate() {
    if (left->calculate() == 0)
    {
        throw "cannot divide by 0";
    } else {
        return right->calculate() / left->calculate();
    }
}

Div::~Div() {
    if (right != NULL)
    {
        delete(this->right);
    }

    if (left != NULL)
    {
        delete(this->left);
    }
}