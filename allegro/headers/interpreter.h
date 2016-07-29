#ifndef __DGUARD_INTERPRETER__
#define __DGUARD_INTERPRETER__

#include <algorithm>
#include <fstream>
#include <map>
#include <tuple>
#include <string>
#include <vector>

#include "face.h"
#include "halfedge.h"
#include "vertex.h"

using namespace std;

class Interpreter {
    private:
        ifstream file;
        char const *filename;
    public:
        Interpreter(char const *fn);
        ~Interpreter();

        ifstream* File();

        void read(vector<Vertex*>& vs, vector<HalfEdge*>& hes, vector<Face*>& fs);

};

#endif
