#ifndef __DGUARD_VERTEX__
#define __DGUARD_VERTEX__

class Vertex {
    private:
        float x, y;

    public:
        Vertex();
        Vertex(float nx, float ny);

        float X();
        void X(float nx);
        float Y();
        void Y(float ny);
}

#endif
