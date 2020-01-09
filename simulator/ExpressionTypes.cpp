#include <string>
#include <string.h>
#include <iostream>
#include <queue>
#include <stack>
#include <regex>
#include <vector>

#include "ExpressionTypes.h"
#include "Expression.h"

using namespace std;

bool isDigit(char c);
bool isOperator(char c);
bool isValidUnary(char op, char next);
bool isValidBinary(char prev, char op, char next);
int precedenceOf(char op);
bool isOpStr(string op);
bool isUnary(string s);
Expression* makeUnaryExp(string s, Expression* e);
Expression* makeBinatyExp(string s, Expression* e1, Expression* e2);

BinaryOperator::BinaryOperator(Expression *right, Expression *left) {
    this->left = left;
    this->right = right;
}

UnaryOperator::UnaryOperator(Expression *exp) {
    this->exp = exp;
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


double Value::calculate() {
    return this->val;
}


RelationalOperator::RelationalOperator(Expression *right, Expression *left) {
    this->left = left;
    this->right = right;
}

Greater::Greater(Expression* exp1, Expression* exp2) : RelationalOperator(right, left) {
    this->right = exp1;
    this->left = exp2;
}
bool Greater::compare() {
    return right->calculate() > left->calculate();
}
Greater::~Greater() {
    if (right != NULL)
    {
        delete(this->right);
    }

    if (left != NULL)
    {
        delete(this->left);
    }
}


Smaller::Smaller(Expression* exp1, Expression* exp2) : RelationalOperator(right, left) {
    this->right = exp1;
    this->left = exp2;
}
bool Smaller::compare() {
    return right->calculate() < left->calculate();
}
Smaller::~Smaller() {
    if (right != NULL)
    {
        delete(this->right);
    }

    if (left != NULL)
    {
        delete(this->left);
    }
}


GreaterEqual::GreaterEqual(Expression* exp1, Expression* exp2) : RelationalOperator(right, left) {
    this->right = exp1;
    this->left = exp2;
}
bool GreaterEqual::compare() {
    return right->calculate() >= left->calculate();
}
GreaterEqual::~GreaterEqual() {
    if (right != NULL)
    {
        delete(this->right);
    }

    if (left != NULL)
    {
        delete(this->left);
    }
}


SmallerEqual::SmallerEqual(Expression* exp1, Expression* exp2) : RelationalOperator(right, left) {
    this->right = exp1;
    this->left = exp2;
}
bool SmallerEqual::compare() {
    return right->calculate() <= left->calculate();
}
SmallerEqual::~SmallerEqual() {
    if (right != NULL)
    {
        delete(this->right);
    }

    if (left != NULL)
    {
        delete(this->left);
    }
}


Equal::Equal(Expression* exp1, Expression* exp2) : RelationalOperator(right, left) {
    this->right = exp1;
    this->left = exp2;
}
bool Equal::compare() {
    return right->calculate() == left->calculate();
}
Equal::~Equal() {
    if (right != NULL)
    {
        delete(this->right);
    }

    if (left != NULL)
    {
        delete(this->left);
    }
}


NotEqual::NotEqual(Expression* exp1, Expression* exp2) : RelationalOperator(right, left) {
    this->right = exp1;
    this->left = exp2;
}
bool NotEqual::compare() {
    return right->calculate() != left->calculate();
}
NotEqual::~NotEqual() {
    if (right != NULL)
    {
        delete(this->right);
    }

    if (left != NULL)
    {
        delete(this->left);
    }
}

Expression* ExpressionInterpreter::interpret(string tokens) {
    for (int i = 0; i < tokens.length(); i++) {
        if (i != 0 && i+1 < tokens.length()) {
            char str[] = {tokens[i], tokens[i+1]};
        }


        if (isDigit(tokens[i]))
        {
            string number;
            number.push_back(tokens[i]);

            while (i+1 < tokens.length() && isDigit(tokens[i+1]))
            {
                ++i;
                number.push_back(tokens[i]);
            }
            if (tokens[i+1] == '.' && isDigit(tokens[i+2]))
            {
                ++i;
                number.push_back(tokens[i]);
                while (i+1 < tokens.length() && isDigit(tokens[i+1]))
                {
                    ++i;
                    number.push_back(tokens[i]);
                }
            }
            output.push(number);

        } else if (isOperator(tokens[i]))
        {
            if ((i == 0 || tokens[i-1] == '(')
                && i+1 < tokens.length()
                && isValidUnary(tokens[i], tokens[i+1]))
            {
                if (tokens[i] == '-')
                {
                    operations.push('#'); //Unary minus's sign (my choice).
                } else
                {
                    operations.push('@'); //Unary plus's sign (my choice).
                }
            } else if (i != 0 && i+1 < tokens.length()
                       && isValidBinary(tokens[i-1], tokens[i], tokens[i+1]))
            {
                while (!operations.empty() && (precedenceOf(operations.top()) > precedenceOf(tokens[i])))
                {
                    string op(1,operations.top());
                    output.push(op);
                    operations.pop();
                }

                operations.push(tokens[i]);
            } else
            {
                throw "input isn't valid!";
            }
        } else if (tokens[i] == '(')
        {
            operations.push(tokens[i]);
        } else if (tokens[i] == ')')
        {
            while (operations.top() != '(' && !operations.empty())
            {
                string op(1,operations.top());
                output.push(op);
                operations.pop();
            }
            if (operations.top() == '(')
            {
                operations.pop();
            } else
            {
                throw "input isn't valid!";
            }
        } else
        {
            bool foundInVars = false;
            for (int j = 0; j < variables.size(); j++)
            {
                string check = tokens.substr(i, variables[j].first.length());

                if (check.compare(variables[j].first) == 0)
                {
                    output.push(variables[j].second);
                    foundInVars = true;
                    break;
                }
            }

            if (!foundInVars)
            {
                throw "input isn't valid!";
            }
        }
    }

    while (!operations.empty()) {
        string op(1, operations.top());
        output.push(op);
        operations.pop();
    }

    deque<Expression*> final;

    while (!output.empty()) {
        if (isDigit(output.front()[0]))
        {
            final.push_back(new Value(stod(output.front())));
            output.pop();
        } else if (isOpStr(output.front()))
        {
            string op = output.front();
            output.pop();

            if (isUnary(op))
            {
                Expression* e = final.back();
                final.pop_back();
                final.push_back(makeUnaryExp(op,e));
            } else {
                Expression* e2 = final.back();
                final.pop_back();
                Expression* e1 = final.back();
                final.pop_back();
                final.push_back(makeBinatyExp(op, e1, e2));
            }
        }
    }
    return final.back();
}

bool isDigit(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    } else {
        return false;
    }
}

bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        return true;
    } else {
        return false;
    }
}

bool isValidUnary(char op, char next) {
    if (op == '-' || op == '+')
    {
        return true;
    } else
    {
        return false;
    }
}

bool isValidBinary(char prev, char op, char next) {
    if (!isOperator(prev) && !isOperator(next) && prev != '(')
    {
        if (op == '-' && (!isDigit(next) || next != '('))
        {
            return false;
        }
        return true;
    } else
    {
        return false;
    }
}

int precedenceOf(char op) {
    if (op == '-' || op == '+')
    {
        return 1;
    }
    else if(op == '*' || op == '/')
    {
        return 2;
    }
    else if (op == '#' || op == '@') //# = unary minus, @ = unary plus
    {
        return 3;
    }
    else
    {
        return 0;
    }
}

bool isOpStr(string op) {
    if ((op.compare("+") == 0) || (op.compare("-") == 0)
        || (op.compare("*") == 0) || (op.compare("/") == 0)
        || (op.compare("@") == 0) || (op.compare("#") == 0))
    {
        return true;
    } else
    {
        return false;
    }
}

bool isUnary(string s) {
    if (s.compare("@") == 0 || s.compare("#") == 0)
    {
        return true;
    } else
    {
        return false;
    }
}

Expression* makeUnaryExp(string s, Expression* e) {
    if (s.compare("@") == 0)
    {
        return new UPlus(e);
    } else
    {
        return new UMinus(e);
    }
}

Expression* makeBinatyExp(string s, Expression* e1, Expression* e2) {
    if (s.compare("+") == 0)
    {
        return new Plus(e1, e2);
    } else if (s.compare("-") == 0)
    {
        return new Minus(e1, e2);
    } else if (s.compare("*") == 0)
    {
        return new Mul(e1, e2);
    } else
    {
        return new Div(e1, e2);
    }
}

void ExpressionInterpreter::setVariables(string vars) {
    vector<string> tokens;

    for (size_t i = 0; i < vars.length(); i++)
    {
        size_t pos = vars.find(';');
        tokens.push_back(vars.substr(i, pos));
        i += tokens.back().length();
    }

    for (int j = 0; j < tokens.size(); j++)
    {
        string varName = tokens[j].substr(0, tokens[j].find('='));
        string value = tokens[j].substr(tokens[j].find('=') + 1);
        if (regex_match(varName, regex("[_[:alpha:]][[:w:]]*"))
            && regex_match(value, regex("(-?[[:d:]]+)(\\.(([[:d:]]+)?))?")))
        {
            for (int k = 0; k < variables.size(); k++)
            {
                if (variables[k].first.compare(varName) == 0)
                {
                    variables.erase(variables.begin() + k);
                }
            }

            variables.insert(variables.end(), pair<string, string>(varName, value));
        } else
        {
            throw "invalid input!";
        }
    }
}