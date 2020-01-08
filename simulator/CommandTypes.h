#ifndef SIMULATOR_COMMAND_TYPES_H
#define SIMULATOR_COMMAND_TYPES_H

#include "Command.h"
#include <string>
#include <vector>
#include <map>
#include "Variable.h"

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
    //private
    map<string, Variable*> symbolTable;
public:
    DefineVarCommand(map<string, Variable*> symbolTable);
    int execute(vector<string> parameters);
    ~DefineVarCommand();
};

class SleepCommand : public Command  {
public:
    int execute(vector<string> parameters);
    ~SleepCommand();
};

class PrintCommand : public Command  {
public:
    int execute(vector<string> parameters);
    ~PrintCommand();
};





#endif //SIMULATOR_COMMAND_TYPES_H