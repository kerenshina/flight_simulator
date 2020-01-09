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

<<<<<<< HEAD
}
=======
}
>>>>>>> da606779dfbbd53e2ef3cbc2a726be7dff63a512
