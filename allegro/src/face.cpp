#include "../headers/face.h"
#include <iostream>

using namespace std;

Face::Face() {
    this->h = (HalfEdge *) NULL;
}

Face::Face(HalfEdge *nh) {
    this->h = nh;
}


HalfEdge* Face::H() { return this->h; }
void Face::H(HalfEdge *nh) { this->h = nh; }

void Face::printAll(vector<Face*>& fs) {
    for (vector<Face*>::iterator it = fs.begin(); it != fs.end(); it++) {
        cout << "Info Face (" << *it << ")" << endl;
        cout << "\t" << "HalfEdge: " << (*it)->H() << endl;
    }
}
