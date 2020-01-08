#ifndef SIMULATOR_INTERPRETER_H
#define SIMULATOR_INTERPRETER_H

#include <string>
#include <map>
#include "Command.h"
#include "Variable.h"

using namespace std;

class Interpreter {
    string fileName;
    vector<string> tokens;
    map<string,Command*> commands;
    map<string, Variable*> symbolTable;
public:
    Interpreter(string fileName);
    void parser();
    ~Interpreter();

private:
    vector<string> lexer();
    vector<string> getLinesFromFile();
    Command* getFromMap(string key);
    vector<string> getParameters(int position);
    void mapCommands();

};

#endif //SIMULATOR_INTERPRETER_H