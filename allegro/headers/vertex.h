#ifndef __DGUARD_VERTEX__
#define __DGUARD_VERTEX__

#include <stdlib.h>
#include <vector>

class Vertex;

#include "halfedge.h"

using namespace std;

class Vertex {
    private:
        int index;
        float x, y;
        HalfEdge *h;

    public:
        Vertex();
        Vertex(float nx, float ny);

        float X();
        void X(float nx);
        float Y();
        void Y(float ny);

        HalfEdge* H();
        void H(HalfEdge* nh);

        static void printAll(vector<Vertex*>& vs);
};

#endif
