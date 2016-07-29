#ifndef __DGUARD_VECTOR2D__
#define __DGUARD_VECTOR2D__

#include <cmath>

class Vector2D {
    private:
        float a, b;
    public:
        Vector2D();
        Vector2D(float na, float nb);

        float A();
        void A(float na);
        float B();
        void B(float nb);

        float dot(Vector2D *v2);
};

#endif
