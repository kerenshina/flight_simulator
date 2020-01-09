#ifndef SIMULATOR_VARIABLE_H
#define SIMULATOR_VARIABLE_H

#include <string>
#include "Expression.h"
using namespace std;

enum Directions {left, right};

class Variable : public Expression{
private:
    double value;
    string sim;
    Directions direction;
public:
    Variable() {}
    void setSim(string simStr);
    void setValue(double val);
    void setDirectionByStr(string arrow);
    void setDirectionByInt(Directions nDirection);
    Directions getDirection();
    string getSim();
    double getValue();
    Variable& operator++();
    Variable& operator--();
    Variable& operator+=(double val);
    Variable& operator-=(double val);
    Variable& operator++(int num);
    Variable& operator--(int num);
    double calculate();
    ~Variable(){}
};
#endif //SIMULATOR_VARIABLE_H