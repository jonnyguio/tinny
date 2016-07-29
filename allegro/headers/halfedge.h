#ifndef __DGUARD_HALFEDGE__
#define __DGUARD_HALFEDGE__

#include <stdlib.h>
#include <vector>

class HalfEdge;

#include "vertex.h"
#include "face.h"

using namespace std;

class HalfEdge {
    private:
        Vertex *v;
        HalfEdge *eTwin, *eNext;
        Face *f;

    public:
        HalfEdge();
        HalfEdge(Vertex *nv);
        HalfEdge(Vertex *nv, HalfEdge *neTwin);
        HalfEdge(Vertex *nv, HalfEdge *neTwin, HalfEdge *neNext);
        HalfEdge(Vertex *nv, HalfEdge *neTwin, HalfEdge *neNext, Face *nf);

        Vertex* V();
        void V(Vertex *nv);

        HalfEdge* ETwin();
        void ETwin(HalfEdge *neTwin);
        HalfEdge* ENext();
        void ENext(HalfEdge *neNext);

        Face* F();
        void F(Face *nf);

        static HalfEdge* searchHalfEdge(vector<HalfEdge*>& hs, Vertex *v, Face *f);
        static void printAll(vector<HalfEdge*>& hs);
};

#endif
