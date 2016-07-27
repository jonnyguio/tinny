#ifndef __DGUARD_HALFEDGE__
#define __DGUARD_HALFEDGE__

#include <vertex.h>
#include <face.h>

class HalfEdge {
    private:
        Vertex *v;
        HalfEdge *eTwin, *eNext;
        Face *f;

    public:
        Vertex* V();
        void V(Vertex *nv);

        HalfEdge* ETwin();
        void ETwin(HalfEdge *neTwin);
        HalfEdge* ENext();
        void ENext(HalfEdge *neNext);

        Face* F();
        void F(Face *nf);
}

#endif
