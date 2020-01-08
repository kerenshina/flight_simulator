#ifndef SIMULATOR_CONDITION_COMMAND_TYPES_H
#define SIMULATOR_CONDITION_COMMAND_TYPES_H


#include "Command.h"
#include "ConditionParser.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;


class IfCommand : public ConditionParser {
    map<string, Command*> commands;
public:
    IfCommand() {}
    void getCommands(map<string, Command*> commands);
    int execute(vector<string> parameters);
    ~IfCommand();

private:
    bool createCondition(vector<string> parameters);
};

class LoopCommand : public ConditionParser {
    map<string, Command*> commands;
public:
    LoopCommand() {}
    void getCommands(map<string, Command*> commands);
    int execute(vector<string> parameters);
    ~LoopCommand();

private:
    bool createCondition(vector<string> parameters);
};

#endif