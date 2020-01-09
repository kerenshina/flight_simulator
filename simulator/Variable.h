<<<<<<< HEAD

=======
>>>>>>> da606779dfbbd53e2ef3cbc2a726be7dff63a512
#ifndef SIMULATOR_VARIABLE_H
#define SIMULATOR_VARIABLE_H

#include <string>
#include "Expression.h"
using namespace std;

enum Directions {left, right};

class Variable : public Expression{
<<<<<<< HEAD
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
=======
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
>>>>>>> da606779dfbbd53e2ef3cbc2a726be7dff63a512
};
#endif //SIMULATOR_VARIABLE_H