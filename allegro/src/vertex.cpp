#include "../headers/vertex.h"
#include <iostream>

using namespace std;

Vertex::Vertex() {
    this->x = 0;
    this->y = 0;
}

Vertex::Vertex(float nx, float ny) {
    this->x = nx;
    this->y = ny;
}

float Vertex::X() { return this->x; }
void Vertex::X(float nx) { this->x = nx; }
float Vertex::Y() { return this->y; }
void Vertex::Y(float ny) { this->y = ny; }

void Vertex::printAll(vector<Vertex*>& vs) {
    for (vector<Vertex*>::iterator it = vs.begin(); it != vs.end(); it++) {
        cout << "Info Vertex (" << *it << ")" << endl;
        cout << "\t" << "X: " << (*it)->X() << " Y: " << (*it)->Y() << endl;
    }
}
