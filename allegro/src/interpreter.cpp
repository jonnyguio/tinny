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

void Interpreter::read(vector<Vertex*>& vs, vector<HalfEdge*>& hes, vector<Face*>& fs) {
    int countV = 0, countH = 0, countF = 0;
    char type;
    float a, b, c;
    HalfEdge *h1, *h2, *h3, *h4, *h5, *h6;
    Vertex *v;
    Face *f;

    while (this->file >> type) {
        if (type == 'v') {
            this->file >> a >> b;
            v = new Vertex(a, b);
            vs.push_back(v);
            countV++;
        }
        if (type == 'f') {
            this->file >> a >> b >> c;

            h1 = new HalfEdge(vs[a-1]); h2 = new HalfEdge(vs[b-1]); h3 = new HalfEdge(vs[c-1]);
            h4 = new HalfEdge(vs[b-1], h1); h5 = new HalfEdge(vs[c-1], h2); h6 = new HalfEdge(vs[a-1], h3);

            hes.push_back(h1); hes.push_back(h2); hes.push_back(h3);
            hes.push_back(h4); hes.push_back(h5); hes.push_back(h6);

            h1->ENext(h2); h2->ENext(h3); h3->ENext(h1);
            h4->ENext(h5); h5->ENext(h6); h6->ENext(h4);

            f = new Face(h1);
            fs.push_back(f);
            h1->F(f); h2->F(f); h3->F(f); h4->F(f); h5->F(f); h6->F(f);

            countF++;
            countH += 6;
        }
    }

}
