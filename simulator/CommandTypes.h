#ifndef SIMULATOR_COMMAND_TYPES_H
#define SIMULATOR_COMMAND_TYPES_H

#include "Command.h"
#include <string>
#include <vector>

using namespace std;

class OpenServerCommand : public Command {
public:
    int execute(vector<string> parameters);
    ~OpenServerCommand();
};

class ConnectCommand : public Command  {
public:
    int execute(vector<string> parameters);
    ~ConnectCommand();
};

class DefineVarCommand : public Command {
public:
    int execute(vector<string> parameters);
    ~DefineVarCommand();
};



#endif //SIMULATOR_COMMAND_TYPES_H
