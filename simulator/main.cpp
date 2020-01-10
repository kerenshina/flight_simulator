#include <iostream>
#include <mutex>
#include "Interpreter.h"

bool running;
map<string, Variable>inputVals;
map<string, Variable>outputVals;
mutex mutexLock;

int main() {
    running=true;
    Interpreter i = Interpreter("file_name");
    return 0;
}