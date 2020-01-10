#ifndef SIMULATOR_COMMAND_H
#define SIMULATOR_COMMAND_H
#include <map>
#include <string>
#include <vector>
#include "Variable.h"

using namespace std;

extern map<string, Variable>inputVals;
extern map<string, Variable>outputVals;

/**
 * Command Interface
 */
class Command {

public:
    Command() {}
    virtual int execute(vector<string> parameters) = 0;
    virtual ~Command() {}
    bool isInInputMap(string str);
    bool isInOutMap(string str);
};

#endif //SIMULATOR_COMMAND_H