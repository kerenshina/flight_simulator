#ifndef SIMULATOR_INTERPRETER_H
#define SIMULATOR_INTERPRETER_H

#include <string>
#include <map>
#include "Command.h"
#include "Variable.h"

using namespace std;
extern map<string, Variable>inputVals;
extern map<string, Variable>outputVals;

class Interpreter {
    string fileName;
    vector<string> tokens;
    map<string,Command*> commands;
    map<string, Variable*> symbolTable;
public:
    Interpreter(string fileName);
    bool isInSymbolTable(string symbol);
        void printVector(vector<string> vector);
    void parser();
    ~Interpreter();

private:
    vector<char> operatorVec = {'<', '>', '!', '='};
    vector<string> lexer();
    vector<string> getLinesFromFile();
    vector<string> getParameters(int position);
    void mapCommands(int index);
    bool inVec(char c);

};

#endif //SIMULATOR_INTERPRETER_H