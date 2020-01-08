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
    OpenServerCommand();
    int execute(vector<string> parameters);
    ~OpenServerCommand();
};

class ConnectCommand : public Command  {
public:
    ConnectCommand();
    int execute(vector<string> parameters);
    ~ConnectCommand();
};

class DefineVarCommand : public Command {
    //private:
    map<string, Variable*>* symbolTable;
public:
    DefineVarCommand(map<string, Variable*>* symbolTable);
    int execute(vector<string> parameters);
    ~DefineVarCommand();
};

class UpdateVarCommand : public Command {
    //private:
    map<string, Variable*>* symbolTable;
public:
    UpdateVarCommand(map<string, Variable*>* symbolTable);
    int execute(vector<string> parameters);
    ~UpdateVarCommand();
};

class SleepCommand : public Command  {
public:
    SleepCommand();
    int execute(vector<string> parameters);
    ~SleepCommand();
};

class PrintCommand : public Command  {
public:
    PrintCommand();
    int execute(vector<string> parameters);
    ~PrintCommand();
};





#endif //SIMULATOR_COMMAND_TYPES_H