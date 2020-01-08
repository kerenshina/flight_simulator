#include "Variable.h"


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

