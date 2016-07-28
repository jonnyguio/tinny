#ifndef __DGUARD_FACE__
#define __DGUARD_FACE__

#include "halfedge.h"

class Face {
    private:
        HalfEdge *h;

    public:
        Face();
        Face(HalfEdge *nv);

        HalfEdge* V();
        void V(HalfEdge *nv);
}

#endif
