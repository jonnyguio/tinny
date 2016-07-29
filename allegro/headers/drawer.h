#ifndef __DGUARD_DRAWER__
#define __DGUARD_DRAWER__

#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <vector>

#include "face.h"
#include "halfedge.h"
#include "vertex.h"

using namespace std;

class Drawer {
    private:
        vector<HalfEdge*> halfEdges;
        vector<Vertex*> vertexs;
    public:
        Drawer();
        Drawer(vector<HalfEdge*> halfEdges, vector<Vertex*> vertexs);
        ~Drawer();

        void drawPoint(float cx, float cy, ALLEGRO_COLOR color, float thickness);
        void drawLine(float x1, float y1, float x2, float y2, ALLEGRO_COLOR color, float thickness);
        void drawMesh();

};

#endif
