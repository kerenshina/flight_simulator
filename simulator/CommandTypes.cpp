#include "CommandTypes.h"
#include "Command.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

OpenServerCommand::OpenServerCommand(){

}

int OpenServerCommand::execute(vector<string> parameters) {

}

OpenServerCommand::~OpenServerCommand() {

}


ConnectCommand::ConnectCommand(){

}

int ConnectCommand::execute(vector<string> parameters) {

}

ConnectCommand::~ConnectCommand() {

}


DefineVarCommand::DefineVarCommand(map<string, Variable*>* symbolTable) {
    this->symbolTable = symbolTable;
}

int DefineVarCommand::execute(vector<string> parameters) {
    Variable newVar;

    if (symbolTable->find(parameters[0]) != symbolTable->end()) {
        cout << "Invalid variable definition!" << endl;
        return 0;
    }

    if (parameters[1].compare("->") || parameters[1].compare("<-")) {
        newVar.setDirectionByStr(parameters[1]);
        if (parameters[2].compare("sim") != 0) {
            cout << "Invalid variable definition!" << endl;
            return 0;
        }
        newVar.setSim(parameters[3]);
        symbolTable->insert({parameters[0], &newVar});
        return parameters.size();
    } else if (parameters[1].compare("=") && symbolTable->find(parameters[2]) != symbolTable->end()) {
        newVar.setSim(symbolTable->find(parameters[2])->second->getSim());
        newVar.setDirectionByInt(symbolTable->find(parameters[2])->second->getDirection());
        newVar.setValue(symbolTable->find(parameters[2])->second->getValue());
        symbolTable->insert({parameters[0], &newVar});
        return parameters.size();
    } else {
        cout << "Invalid variable definition!" << endl;
        return 0;
    }

}

DefineVarCommand::~DefineVarCommand() {

}


UpdateVarCommand::UpdateVarCommand(map<string, Variable*>* symbolTable) {
    this->symbolTable = symbolTable;
}

int UpdateVarCommand::execute(vector<string> parameters) {
    auto itr = symbolTable->find(parameters[0]);
    if (itr == symbolTable->end()) {
        cout << "Invalid variable!" << endl;
        return 0;
    }
    itr->second->setValue(atof(parameters[0].c_str()));
    return parameters.size() + 1;
}

UpdateVarCommand::~UpdateVarCommand() {

}


SleepCommand::SleepCommand() {

}

int SleepCommand::execute(vector<string> parameters) {

}

SleepCommand::~SleepCommand() {

}


PrintCommand::PrintCommand() {

}

int PrintCommand::execute(vector<string> parameters) {

}

PrintCommand::~PrintCommand() {

}

