#include "../headers/interpreter.h"
#include <iostream>

using namespace std;

Interpreter::Interpreter(char const *fn) {
    this->filename = fn;
    this->file.open(fn);
}

Interpreter::~Interpreter() {
    this->file.close();
}

ifstream* Interpreter::File() { return &(this->file); }
