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

using namespace std;


Interpreter::Interpreter(string fileName) {
    this->fileName = fileName;
    this->tokens = lexer();
}
vector<string> Interpreter::lexer() {
<<<<<<< HEAD
    vector<string> tokens;
    vector<string> lines = this->getLinesFromFile();
    int position = 0;
=======
    vector<string> lines = getLinesFromFile();
    vector<string> tokens;
    string newLanguageWord;
>>>>>>> 88d6802badc8dfc8ed10b7ee4e9701e0a8365d75

    for (int i = 0; i < lines.size(); i++)
    {
        string line = lines[i];
        string newWord = "";

        for (int j = 0; j < line.length(); j++)
        {
            if (line[j] == '\t' || line[j] == '\n' || line[j] == ' ')
            {
//                if (newWord.length() != 0)
//                {
//                    tokens.push_back(newWord);
//                    newWord = "";
//                }
                continue;
<<<<<<< HEAD
            }
            else if (j + 1 < line.length()
                     && ((line[j] == '-' && line[j + 1] == '>') || (line[j] == '<' && line[j + 1] == '-')))
            {
                if (newWord.length() != 0)
                {
                    tokens.push_back(newWord);
                    newWord = "";
=======

            } else if (j + 1 < lineLength && ((line[j] == '-' && line[j + 1] == '>')
                                              || (line[j] == '<' && line[j + 1] == '-'))) {
                if (newLanguageWord.length() != 0) {
                    tokens.push_back(newLanguageWord);
                    newLanguageWord = "";
>>>>>>> 88d6802badc8dfc8ed10b7ee4e9701e0a8365d75
                }
                newWord = newWord + line[j] + line[j + 1];
                tokens.push_back(newWord);
                newWord = "";
                j++;
            }
            else if (line[j] == '"')
            {
                if (newWord.length() != 0)
                {
                    tokens.push_back(newWord);
                    newWord = "";
                }
                newWord = newWord + line[j];
                j++;
                while (j < line.length() && line[j] != '"')
                {
                    newWord = newWord + line[j];
                }
                if (line[j] == '"')
                {
                    newWord = newWord + line[j];
                }
                tokens.push_back(newWord);
                newWord = "";
            }
            else if (line[j]== '=' || line[j] == '{' || line[j] == '}')
            {
                if (newWord.length() != 0)
                {
                    tokens.push_back(newWord);
                    newWord = "";
                }
                newWord = newWord + line[j];
                tokens.push_back(newWord);
                newWord = "";
            }
            else if (line[j] == '(')
            {
                if (newWord.length() != 0) {
                    tokens.push_back(newWord);
                    newWord = "";
                }
                ++j;
                while (j < line.length() && line[j] != ')')
                {
                    if (line[j] == ',')
                    {
                        tokens.push_back(newWord);
                        newWord = "";
                    }
                    else
                    {
                        newWord = newWord + line[j];
                    }
                    j++;
                }
                tokens.push_back(newWord);
                newWord = "";
            }
            else if (j + 1 < line.length() && line[j] == '/' && line[j + 1] == '/')
            {
                if (newWord.length() != 0) {
                    tokens.push_back(newWord);
                    newWord = "";
                }
                break;
            }
            else
            {
                newWord = newWord + line[j];
            }
        }
        if (newWord.length() != 0) {
            tokens.push_back(newWord);
            newWord = "";
        }
        mapCommands(position);
        position += line.length();
    }

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


vector<string> Interpreter::getParameters(int position) {
    map<string, Command*>::iterator itr;
    map<string,Command*> commandsToScope;
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
    bool conditionCommand = false;

    for (int i = index; i < tokens.size(); i++) {
        if (tokens[i].compare("openDataServer") == 0) {
            OpenServerCommand openServer;
            commands.insert({tokens[i], &openServer});
            break;
        } else if (tokens[i].compare("connectControlClient") == 0) {
            ConnectCommand connect;
            commands.insert({tokens[i], &connect});
            break;
        } else if (tokens[i].compare("var") == 0) {
            DefineVarCommand var = DefineVarCommand(&symbolTable);
            commands.insert({tokens[i], &var});
            break;
        } else if (tokens[i].compare("while") == 0) {
            LoopCommand whileCommand;
            commands.insert({tokens[i], &whileCommand});
            conditionCommand = true;
        } else if (tokens[i].compare("=") == 0) {
            UpdateVarCommand upVar = UpdateVarCommand(&symbolTable);
            commands.insert({tokens[i], &upVar});
            break;
        } else if (tokens[i].compare("Sleep") == 0) {
            SleepCommand sleep;
            commands.insert({tokens[i], &sleep});
            break;
        } else if (tokens[i].compare("Print") == 0) {
            PrintCommand print;
            commands.insert({tokens[i], &print});
            break;
        } else if (tokens[i].compare("if") == 0) {
            IfCommand ifCommand;
            commands.insert({tokens[i], &ifCommand});
            conditionCommand = true;
        } else if (tokens[i].compare("{") && !conditionCommand) {
            FuncCommand func;
            commands.insert({tokens[index], &func});
            break;
        }
    }
}



