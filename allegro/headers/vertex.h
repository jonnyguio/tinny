#ifndef __DGUARD_VERTEX__
#define __DGUARD_VERTEX__

#include <stdlib.h>

class Vertex {
    private:
        int index;
        float x, y, z;

    public:
        Vertex();
        Vertex(float nx, float ny, float nz);

        float X();
        void X(float nx);
        float Y();
        void Y(float ny);
        float Z();
        void Z(float nz);
};

#endif
