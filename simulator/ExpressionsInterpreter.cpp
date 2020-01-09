#include "ExpressionsInterpreter.h"
#include <iostream>

using namespace std;

Expression* ExpressionsInterpreter::interpret(string str) {

    for (int j = 0; j < str.length(); j++) {
        if (isDigit(str[j])) {
            string number = "" + str[j];
            int dots = 0;
            ++j;
            while (j < str.length() && isDigit(str[j]) && dots <= 1) {
                number += str[j];
                if (str[j] == '.') {
                    if (isDigit(str[j + 1])) {
                        dots++;
                    } else {
                        throw "invalid input";
                    }
                }
                j++;
            }
            if (dots > 1) {
                throw "invalid input";
            }
            j--;
            this->output.push(number);
        } else if (isOperator(str[j])) {
            if (j == 0) {
                if (str[j] == '-') {
                    operations.push('#');  //Unary minus's sign.
                } else if (str[j] == '+') {
                    operations.push('@'); //Unary plus's sign
                }
            } else {

            }
        }
    }
}



bool ExpressionsInterpreter::isDigit(char c) {
    return c >= '0' && c <= '9';
}
bool ExpressionsInterpreter::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
bool ExpressionsInterpreter::isValidUnary(char op, char next) {

}
bool ExpressionsInterpreter::isValidBinary(char prev, char op, char next) {

}