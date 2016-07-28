#include "../headers/face.h"

Face::Face() {
    this->h = (HalfEdge *) NULL;
}

Face::Face(HalfEdge *nh) {
    this->h = nh;
}


HalfEdge* Face::H() { return this->h; }
void Face::H(HalfEdge *nh) { this->h = nh; }
