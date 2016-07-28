#ifndef __DGUARD_FACE__
#define __DGUARD_FACE__

#include <stdlib.h>

class Face;

#include "halfedge.h"

class Face {
    private:
        HalfEdge *h;

    public:
        Face();
        Face(HalfEdge *nh);

        HalfEdge* H();
        void H(HalfEdge *nh);
};

#endif
