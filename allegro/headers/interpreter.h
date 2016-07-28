#ifndef __DGUARD_INTERPRETER__
#define __DGUARD_INTERPRETER__

#include <fstream>
#include <string>

using namespace std;

class Interpreter {
    private:
        ifstream file;
        char const *filename;
    public:
        Interpreter(char const *fn);
        ~Interpreter();

        ifstream* File();

};

#endif
