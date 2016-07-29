#ifndef __DGUARD_FACE__
#define __DGUARD_FACE__

#include <stdlib.h>
#include <vector>

class Face;

#include "halfedge.h"

using namespace std;

class Face {
    private:
        HalfEdge *h;

    public:
        Face();
        Face(HalfEdge *nh);

        HalfEdge* H();
        void H(HalfEdge *nh);

        static void printAll(vector<Face*>& fs);
};

#endif
