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
    cout<<"##### Print tokens: #####" << endl;
    for (int i = 0; i < tokens.size(); i++) {
        cout << tokens[i] << endl;
    }
    cout<<"##### Print commands: #####"<<endl;
    for (auto const& pair:commands){
        cout<<pair.first<<" "<<pair.second<<endl;
    }
    cout<<"##### going to Parser: ##### "<<endl;
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
cout<<"Tokens size: "<<tokens.size()<<endl;
    while (index < this->tokens.size()) {
        cout<< "index: "<<index<<" Key:" <<tokens[index];
        map<string, Command *>::iterator itr = commands.find(tokens[index]);
        if (itr != commands.end()) {
            Command *c = itr->second;

            vector<string> parameters = getParameters(index);
            if (tokens[index].compare("=")==0){
                parameters.push_back(tokens[index-1]);
            }
            cout<<"   Parametrs: [";
            printVector(parameters);
            cout<<"]"<<endl;
            int skip =  c->execute(parameters);
            index += skip;
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
}

void Interpreter::printVector(vector<string> vector) {
for(int i=0 ;i<vector.size();i++){
    cout<<vector[i]<<", ";
}
}



