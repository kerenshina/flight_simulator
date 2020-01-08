#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "Interpreter.h"
#include "Command.h"
#include "CommandTypes.h"
#include "ConditionParser.h"
#include "FuncCommand.h"

using namespace std;

Interpreter::Interpreter(string fileName) {
    this->fileName = fileName;
    this->tokens = lexer();
    mapCommands();
}
vector<string> Interpreter::lexer() {
    vector<string> lines = getLinesFromFile();
    vector<string> tokens;
    string newLanguageWord;

    for (int i = 0; i < lines.size(); i++) {
        string line = lines[i];
        int lineLength = line.length();
        newLanguageWord = "";

        for(int j = 0; j < lineLength; j++) {
            if (line[j] == '\t' || line[j] == '\n' || line[j] == ' ') {
                if (newLanguageWord.length() != 0) {
                    tokens.push_back(newLanguageWord);
                    newLanguageWord = "";
                }
                continue;

            } else if (j + 1 < lineLength && ((line[j] == '-' && line[j + 1] == '>')
                                              || (line[j] == '<' && line[j + 1] == '-'))) {
                if (newLanguageWord.length() != 0) {
                    tokens.push_back(newLanguageWord);
                    newLanguageWord = "";
                }
                newLanguageWord = newLanguageWord + line[j] + line[j+1];
                tokens.push_back(newLanguageWord);
                newLanguageWord = "";
                j++;

            } else if (line[j] = '"') {
                if (newLanguageWord.length() != 0) {
                    tokens.push_back(newLanguageWord);
                    newLanguageWord = "";
                }
                newLanguageWord = newLanguageWord + line[j];
                j++;
                while(j < lineLength && line[j] != '"') {
                    newLanguageWord = newLanguageWord + line[j];
                    if (line[j+1] == '"') {
                        newLanguageWord = newLanguageWord + line[j + 1];
                    }
                    j++;
                }
                tokens.push_back(newLanguageWord);
                newLanguageWord = "";

            } else if (line[j] == '=') {
                if (newLanguageWord.length() != 0) {
                    tokens.push_back(newLanguageWord);
                    newLanguageWord = "";
                }
                newLanguageWord = newLanguageWord + tokens[j];
                tokens.push_back(newLanguageWord);
                newLanguageWord = "";

            } else if (line[j] == '(') {
                if (newLanguageWord.length() != 0) {
                    tokens.push_back(newLanguageWord);
                    newLanguageWord = "";
                }
                ++j;
                while(j < lineLength && line[j] != ')') {
                    if (line[j] == ',') {
                        newLanguageWord = "";
                    } else {
                        newLanguageWord = newLanguageWord + line[j];
                    }
                    j++;
                }
                tokens.push_back(newLanguageWord);
                newLanguageWord = "";

            } else if (j + 1 < lineLength && line[j] =='/' && line[j + 1] == '/') {
                break;
            } else if (line[j] == '{' || line[j] == '}') {
                if (newLanguageWord.length() != 0) {
                    tokens.push_back(newLanguageWord);
                    newLanguageWord = "";
                }
                newLanguageWord = newLanguageWord + tokens[j];
                tokens.push_back(newLanguageWord);
                newLanguageWord = "";

            } else {
                newLanguageWord = newLanguageWord + line[j];
            }
        }
    }

    return tokens;
}

void Interpreter::parser(){
    int index = 0;

    while (index < this->tokens.size()) {
        map<string, Command*>::iterator itr = commands.find(tokens[index]);
        if (itr != commands.end()) {
            Command* c = itr->second;
            index += c->execute(getParameters(index));

        }
        index++;
    }
}

Interpreter::~Interpreter() {}

vector<string> Interpreter::getLinesFromFile () {
    vector<string> lines;
    string line;
    ifstream file;
    file.open(fileName, ifstream::in);
    if(!file.is_open()) {
        cout << "Cannot open file!" << endl;
        exit(1);
    } else {
        while(getline(file, line)) {
            if (line.length() != 0) {
                lines.push_back(line);
            }
        }
        file.close();
    }
    return lines;
}


//fixing bugs!!!!
vector<string> Interpreter::getParameters(int position) {
    map<string, Command*>::iterator itr;
    string command = tokens[position];
    vector<string> parameters;
    bool conditionOrFunc = false;

    position++;
    while (position < tokens.size()) {
        itr = commands.find(tokens[position]);
        if (tokens[position].compare("{") == 0) {
            conditionOrFunc = true;
            continue;
        }
        if ((itr != commands.end() && !conditionOrFunc) ||(conditionOrFunc && tokens[position].compare("}"))) {
            break;
        } else {
            parameters.push_back(tokens[position]);
        }
        position++;
    }

    return parameters;
}

void Interpreter::mapCommands() {
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i].compare("openDataServer") == 0) {

        } else if (tokens[i].compare("connectControlClient") == 0) {

        } else if (tokens[i].compare("var") == 0) {

        } else if (tokens[i].compare("while") == 0) {

        } else if (tokens[i].compare("=") == 0) {

        } else if (tokens[i].compare("Sleep") == 0) {

        } else if (tokens[i].compare("Print") == 0) {

        } else if (tokens[i].compare("if") == 0) {

        }
    }
}



