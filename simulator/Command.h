#ifndef SIMULATOR_COMMAND_H
#define SIMULATOR_COMMAND_H

#include <string>
#include <vector>

using namespace std;
/**
 * Command Interface
 */
class Command {

public:
    Command() {}
    virtual int execute(vector<string> parameters) = 0;
    virtual ~Command() {}
};

#endif //SIMULATOR_COMMAND_H