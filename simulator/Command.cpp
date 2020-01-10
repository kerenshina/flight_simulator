//
// Created by alex on 10.1.2020.
//

#include "Command.h"

bool Command::isInInputMap(string str) {
    for(map<string, Variable>::const_iterator it = inputVals.begin();
        it != inputVals.end(); ++it)
    {
       if (it->first.compare(str)==0) {return true;}
    }
    return false;
}
bool Command::isInOutMap(string str) {
    for(map<string, Variable>::const_iterator it = outputVals.begin();
        it != outputVals.end(); ++it)
    {
        if (it->first.compare(str)==0) {return true;}
    }
    return false;
}


