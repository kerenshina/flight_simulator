#ifndef SIMULATOR_INTERPRETER_H
#define SIMULATOR_INTERPRETER_H

#include <string>
#include <map>
#include "Command.h"

using namespace std;

class Interpreter {
    string fileName;
    vector<string> tokens;
    map<string,Command*> commands;
public:
    Interpreter(string fileName);
    void parser();
    ~Interpreter();

private:
    vector<string> lexer();
    vector<string> getLinesFromFiles();
    Command* getFromMap(string key);
    vector<string> getParameters(int position);
    void mapCommands();

};

#endif //SIMULATOR_INTERPRETER_H