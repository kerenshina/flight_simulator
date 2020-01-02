#ifndef SIMULATOR_COMMAND_H
#define SIMULATOR_COMMAND_H

#include <string>

using namespace std;
/**
 * Command Interface
 */
class Command {

public:
    virtual int execute(string *strArray) = 0;
    virtual ~Command() {}
};

#endif //SIMULATOR_COMMAND_H
