#include <iostream>
#include <mutex>
#include "Interpreter.h"

bool running;
map<string, Variable>inputVals;
map<string, Variable>outputVals;
vector<string> tokens;
map<string,Command*> commands;
mutex mutexLock;

int main() {
    running=true;
    Interpreter i = Interpreter("file_name");
    return 0;
}
