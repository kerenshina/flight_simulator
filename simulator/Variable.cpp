#include "Variable.h"

using namespace std;

void Variable::setSim(string simStr) {
    string newSim = "";
    if (simStr[0] == '"') {
        int i = 1;
        while (i < simStr.length() && simStr[i] != '"') {
            newSim += simStr[i];
        }
        this->sim = newSim;
    } else {
        this->sim = simStr;
    }

}
void Variable::setValue(double val) {
    this->value = val;
}
void Variable::setDirectionByStr(string arrow) {
    if (arrow[0] == '<') {
        this->direction = left;
    } else {
        this->direction = right;
    }
}
void Variable::setDirectionByInt(Directions nDirection) {
    this->direction = nDirection;
}
Directions Variable::getDirection() {
    return this->direction;
}
string Variable::getSim() {
    return this->sim;
}
double Variable::getValue() {
    return this->value;
}

Variable& Variable::operator++() {
    this->value = ++(this->value);
    return *this;
}

Variable& Variable::operator--() {
    this->value = --(this->value);
    return *this;
}

Variable& Variable::operator+=(double val) {
    this->value = this->value + val;
    return *this;
}

Variable& Variable::operator-=(double val) {
    this->value = this->value - val;
    return *this;
}

Variable& Variable::operator++(int num) {
    return ++*this;
}
Variable& Variable::operator--(int num) {
    return --*this;
}
double Variable::calculate() {
    return this->value;
}

