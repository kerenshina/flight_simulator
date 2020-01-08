
#ifndef SIMULATOR_VARIABLE_H
#define SIMULATOR_VARIABLE_H

#include <string>
using namespace std;

enum Directions {left, right};

class Variable {
    double value;
    string sim;
    Directions direction;
public:
    Variable() {}
    void setSim(string sim);
    void setValue(double value);
    void setDirectionByStr(string arrow);
    void setDirectionByInt(Directions direction);
    Directions getDirection();
    string getSim();
    double getValue();
    Variable& operator++();
    Variable& operator--();
    Variable& operator+=(double val);
    Variable& operator-=(double val);
    Variable& operator++(int num);
    Variable& operator--(int num);
    ~Variable(){}
};
#endif //SIMULATOR_VARIABLE_H