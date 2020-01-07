#ifndef SIMULATOR_FUNC_COMMAND_H
#define SIMULATOR_FUNC_COMMAND_H

#include <string>
#include <vector>
#include "Command.h"

using namespace std;

class ConditionParser : public Command {

public:
    int execute(vector<string> parameters);
};

#endif //SIMULATOR_FUNC_COMMAND_H
