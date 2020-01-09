#include "Command.h"
#include "ConditionParser.h"
#include "ConditionCommandTypes.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>


int IfCommand::execute(vector<string> parameters) {

}

void IfCommand::getCommands(map<string, Command*> commands){
    this->commands = commands;
}

IfCommand::~IfCommand() {

}


void LoopCommand::getCommands(map<string, Command*> commands){
    this->commands = commands;
}

int LoopCommand::execute(vector<string> parameters) {

}

LoopCommand::~LoopCommand() {

}