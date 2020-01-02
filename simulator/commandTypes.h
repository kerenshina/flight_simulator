#ifndef SIMULATOR_COMMAND_TYPES_H
#define SIMULATOR_COMMAND_TYPES_H

#include "command.h"
#include <string>

using namespace std;

class OpenServerCommand : public Command {
    public:
    int execute(string *strArray);
};

class ConnectCommand : public Command  {
    public:
    int execute(string *strArray);
    };

class DefineVarCommand : public Command {
    public:
    int execute(string *strArray);
};



#endif //SIMULATOR_COMMAND_TYPES_H
