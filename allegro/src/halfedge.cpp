#include "../headers/halfedge.h"
#include <iostream>

using namespace std;

HalfEdge::HalfEdge() {
    this->v = (Vertex *) NULL;
    this->eTwin = (HalfEdge *) NULL;
    this->eNext = (HalfEdge *) NULL;
    this->f = (Face *) NULL;
}

HalfEdge::HalfEdge(Vertex *nv) {
    this->v = nv;
    this->eTwin = (HalfEdge *) NULL;
    this->eNext = (HalfEdge *) NULL;
    this->f = (Face *) NULL;
}

HalfEdge::HalfEdge(Vertex *nv, HalfEdge *neTwin) {
    this->v = nv;
    this->eTwin = neTwin;
    this->eNext = (HalfEdge *) NULL;
    this->f = (Face *) NULL;
}

HalfEdge::HalfEdge(Vertex *nv, HalfEdge *neTwin, HalfEdge *neNext) {
    this->v = nv;
    this->eTwin = neTwin;
    this->eNext = neNext;
    this->f = (Face *) NULL;
}

HalfEdge::HalfEdge(Vertex *nv, HalfEdge *neTwin, HalfEdge *neNext, Face *nf) {
    this->v = nv;
    this->eTwin = neTwin;
    this->eNext = neNext;
    this->f = nf;
}

Vertex* HalfEdge::V() { return this->v; }
void HalfEdge::V(Vertex *nv) { this->v = nv; }

HalfEdge* HalfEdge::ETwin() { return this->eTwin; }
void HalfEdge::ETwin(HalfEdge *neTwin) { this->eTwin = neTwin; }

HalfEdge* HalfEdge::ENext() { return this->eNext; }
void HalfEdge::ENext(HalfEdge *neNext) { this->eNext = neNext; }

Face* HalfEdge::F() { return this->f; }
void HalfEdge::F(Face *nf) { this->f = nf; }

HalfEdge* HalfEdge::searchHalfEdge(vector<HalfEdge*>& hs, Vertex *v, Face *f) {
    HalfEdge *res = (HalfEdge*) NULL;
    for (vector<HalfEdge*>::iterator it = hs.begin(); it != hs.end(); it++) {
        if ((*it)->F() == f && (*it)->V() == v) {
            res = *it;
            break;
        }
    }
    return res;
}

void HalfEdge::printAll(vector<HalfEdge*>& hs) {
    for (vector<HalfEdge*>::iterator it = hs.begin(); it != hs.end(); it++) {
        cout << "Info Half Edge (" << *it << ")" << endl;
        cout << "\t" << "Vertice:" << (*it)->V() << endl;
        cout << "\t" << "eTwin:" << (*it)->ETwin() << endl;
        cout << "\t" << "eNext:" << (*it)->ENext() << endl;
        cout << "\t" << "Face:" << (*it)->F() << endl;
    }
}
