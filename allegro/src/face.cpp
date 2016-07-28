#include "../headers/face.h"

Face::Face() {
    this->h = (HalfEdge *) NULL;
}

Face::Face(HalfEdge *nh) {
    this->h = nh;
}


HalfEdge* HalfEdge::V() { return this->v; }
void HalfEdge::V(HalfEdge *nv) { this->v = nv; }
