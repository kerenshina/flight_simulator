#ifndef EXPRESSIONS_VALUE_H
#define EXPRESSIONS_VALUE_H

#include "Expression.h"

using namespace std;

class Value: public Expression {
private:
    const double val;

public:
    Value(double value) : val(value) {};
    double calculate();
};

<<<<<<< HEAD
#endif //EXPRESSIONS_VALUE_H
=======
#endif //EXPRESSIONS_VALUE_H
>>>>>>> da606779dfbbd53e2ef3cbc2a726be7dff63a512
