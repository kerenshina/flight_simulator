#include "Command.h"
#include "FuncCommand.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>


int FuncCommand::execute(vector<string> parameters) {

}

void FuncCommand::getCommands(map<string, Command*> commands){
    this->commands = commands;
}

FuncCommand::~FuncCommand() {

}
