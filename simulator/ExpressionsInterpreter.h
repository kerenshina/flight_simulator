#ifndef SIMULATOR_EXPRESSIONS_INTERPRETER_H
#define SIMULATOR_EXPRESSIONS_INTERPRETER_H

#include "Expression.h"
#include <queue>
#include <string>
#include <stack>

using namespace std;

class ExpressionsInterpreter {
private:
    queue<string> output;
    stack<char> operations;
    vector< pair <string, string> > variables;


public:
    Expression* interpret(string str);

private:
    static bool isDigit(char c);
    static bool isOperator(char c);
    static bool isValidUnary(char op, char next);
    static bool isValidBinary(char prev, char op, char next);
};

#endif //SIMULATOR_EXPRESSIONS_INTERPRETER_H