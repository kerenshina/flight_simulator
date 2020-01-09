#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "Interpreter.h"
#include "Command.h"
#include "CommandTypes.h"
#include "FuncCommand.h"
#include "ConditionCommandTypes.h"
#include <map>
#include <unordered_map>

using namespace std;


Interpreter::Interpreter(string fileName) {
    this->fileName = fileName;
    this->tokens = lexer();
    mapCommands(0);
    cout<<"Print tokens: " << endl;
    for (int i = 0; i < tokens.size(); i++) {
        cout << tokens[i] << endl;
    }
    cout<<"Print commands: "<<endl;
    for (auto const& pair:commands){
        cout<<pair.first<<" "<<pair.second<<endl;
    }
    cout<<"going to prser: "<<endl;
    parser();
    //
   // commands.at("openDataServer")->execute({"5400"});
    //map::const iterator pos
    //this->commands.find("openDataServer")
}
bool Interpreter::inVec(char c) {
    for (char i : this->operatorVec) {
        if (c == i) {
            return true;
        }
    }
    return false;
}

vector<string> Interpreter::lexer() {
    vector<string> tokens;
    vector<string> lines = this->getLinesFromFile();
    for (int k = 0; k < lines.size(); k++) {
            string newWord;
            int size = strlen(lines[k].c_str());
            int i, j;
            for (i = 0; i < size; i++) {
                if (lines[k][i] == '\t') {
                    continue;
                }

                if (lines[k][i] == '"') {
                    newWord += lines[k][i];
                    for (j = i + 1; lines[k][j] != '"'; j++) {
                        newWord += lines[k][j];
                    }
                    newWord += lines[k][j];
                    i = j;
                } else if (lines[k][i] == '-' && lines[k][i + 1] == '>') {

                    if (newWord.length() > 0) {
                        tokens.push_back(newWord);
                        newWord = "";
                    }

                    newWord += lines[k][i];
                    newWord += lines[k][i + 1];
                    tokens.push_back(newWord);
                    newWord = "";
                    i = i + 1;
                } else if (inVec(lines[k][i])) {

                    if (newWord.length() > 0) {
                        tokens.push_back(newWord);
                        newWord = "";
                    }

                    if (inVec(lines[k][i + 1])) {
                        newWord += lines[k][i];
                        newWord += lines[k][i + 1];
                        tokens.push_back(newWord);
                        newWord = "";
                        j = i + 2;
                        // creates the <-
                    } else if (lines[k][i + 1] == '-') {
                        newWord += lines[k][i];
                        newWord += lines[k][i + 1];
                        tokens.push_back(newWord);
                        newWord = "";
                        i = i + 1;
                        continue;
                    } else {
                        // if we have only one operator: >, <, =, -
                        newWord += lines[k][i];
                        tokens.push_back(newWord);
                        newWord = "";
                        j = i + 1;
                    }

                    for (j; lines[k][j] != '{' && j < size; j++) {
                        if (lines[k][j] != ' ') {
                            newWord += lines[k][j];
                        }
                    }
                    tokens.push_back(newWord);
                    newWord = "";

                    if (lines[k][j] == '{') {
                        newWord += lines[k][j];
                        tokens.push_back(newWord);
                        newWord = "";
                        j++;
                    }
                    i = j;
                } else if (lines[k][i] != ' ' && lines[k][i] != '(' && lines[k][i] != ')' && lines[k][i] != ',') {
                    newWord += lines[k][i];
                } else {
                    if(newWord.length() > 0) {
                        tokens.push_back(newWord);
                        newWord = "";
                    }
                }
            }
            if (!newWord.empty()) {
                tokens.push_back(newWord);
            }
        }

    return tokens;
}

void Interpreter::parser() {
    int index = 0;
cout<<tokens.size()<<endl;
    while (index < this->tokens.size()) {
        cout<< "index: "<<index<<" Key:" <<tokens[index]<<" and ";
        map<string, Command *>::iterator itr = commands.find(tokens[index]);
        if (itr != commands.end()) {
            Command *c = itr->second;
            cout<<"parametrs: " << getParameters(index)[0]<< endl;
            index += c->execute(getParameters(index));
        }
        index++;
    }
}

Interpreter::~Interpreter() {}

vector<string> Interpreter::getLinesFromFile() {
    vector<string> lines;
    string line;
    ifstream file;
    file.open(fileName, ifstream::in);
    if (!file.is_open()) {
        cout << "Cannot open file!" << endl;
        exit(1);
    } else {
        while (getline(file, line)) {
            if (line.length() != 0) {
                lines.push_back(line);
            }
        }
        file.close();
    }
    return lines;
}


vector<string> Interpreter::getParameters(int position) {
    map<string, Command *>::iterator itr;
    map<string, Command *> commandsToScope;
    string command = tokens[position];
    vector<string> parameters;
    bool scope = false;

    position++;
    while (position < tokens.size()) {
        itr = commands.find(tokens[position]);
        if (tokens[position].compare("{") == 0) {
            scope = true;
            continue;
        }
        if (scope && itr != commands.end()) {
            commandsToScope.insert({tokens[position], itr->second});
            commands.erase(itr);
        }
        if ((itr != commands.end() && !scope) || (scope && tokens[position].compare("}"))) {
            break;
        } else {
            parameters.push_back(tokens[position]);
        }
        position++;
    }

    return parameters;
}

void Interpreter::mapCommands(int index) {
    commands["openDataServer"]= new OpenServerCommand;
    commands["connectControlClient"]= new ConnectCommand;
    commands["var"]= new DefineVarCommand(&symbolTable);
    commands["while"]= new LoopCommand;
    commands["="]= new UpdateVarCommand(&symbolTable);;
    commands["Sleep"]= new SleepCommand;
    commands["Print"]= new PrintCommand;
    commands["if"]= new IfCommand;
    commands["takeoff"]= new FuncCommand;

//    for (int i = index; i < tokens.size(); i++) {
//        if (tokens[i].compare("openDataServer") == 0) {
//            OpenServerCommand *openServer = new OpenServerCommand();
//            commands.insert({tokens[i], openServer});
//        } else if (tokens[i].compare("connectControlClient") == 0) {
//            ConnectCommand *connect = new ConnectCommand();
//            commands.insert({tokens[i], connect});
//        } else if (tokens[i].compare("var") == 0) {
//            DefineVarCommand *var = new DefineVarCommand(&symbolTable);
//            commands.insert({tokens[i], var});
//        } else if (tokens[i].compare("while") == 0) {
//            LoopCommand *whileCommand = new LoopCommand();
//            commands.insert({tokens[i], whileCommand});
//            conditionCommand = true;
//        } else if (tokens[i].compare("=") == 0) {
//            UpdateVarCommand *upVar = new UpdateVarCommand(&symbolTable);
//            commands.insert({tokens[i], upVar});
//        } else if (tokens[i].compare("Sleep") == 0) {
//            SleepCommand *sleep = new SleepCommand();
//            commands.insert({tokens[i], sleep});
//        } else if (tokens[i].compare("Print") == 0) {
//            PrintCommand *print = new PrintCommand();
//            commands.insert({tokens[i], print});
//        } else if (tokens[i].compare("if") == 0) {
//            IfCommand *ifCommand = new IfCommand();
//            commands.insert({tokens[i], ifCommand});
//            conditionCommand = true;
//        } else if (tokens[i].compare("{")== 0 && !conditionCommand) { //lior change index to i-3
//            FuncCommand *func = new FuncCommand();
//            commands.insert({tokens[i - 2], func});
//        } else if (tokens[i].compare("}") == 0 && conditionCommand) { //lior added
//            conditionCommand = false;
//        }
//    }
}



