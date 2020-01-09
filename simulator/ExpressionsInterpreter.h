<<<<<<< HEAD
#ifndef EXPRESSIONS_EXPRESSIONS_INTERPRETER_H
#define EXPRESSIONS_EXPRESSIONS_INTERPRETER_H
=======
#ifndef SIMULATOR_EXPRESSIONS_INTERPRETER_H
#define SIMULATOR_EXPRESSIONS_INTERPRETER_H
>>>>>>> da606779dfbbd53e2ef3cbc2a726be7dff63a512

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

<<<<<<< HEAD
#endif //EXPRESSIONS_EXPRESSIONS_INTERPRETER_H
=======
#endif //SIMULATOR_EXPRESSIONS_INTERPRETER_H
>>>>>>> da606779dfbbd53e2ef3cbc2a726be7dff63a512
