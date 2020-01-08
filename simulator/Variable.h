
#ifndef SIMULATOR_VARIABLE_H
#define SIMULATOR_VARIABLE_H

#include <string>
using namespace std;


class Variable {
    double value;
    string sim;
    bool isLeft;
public:
    Variable(double value,string direction);
    void setSim(string sim);
    void updateValue(double newVal);
    ~Variable(){}
};
#endif //SIMULATOR_VARIABLE_H