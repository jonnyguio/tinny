#include "../headers/drawer.h"

Drawer::Drawer() {
}

Drawer::Drawer(vector<HalfEdge*> _halfEdges, vector<Vertex*> _vertexs) {
    this->halfEdges = _halfEdges;
    this->vertexs = _vertexs;
}

Drawer::~Drawer() {
}

void Drawer::drawPoint(float cx, float cy, ALLEGRO_COLOR color = al_map_rgb(0,0,0), float thickness = 5) {
    al_draw_circle(cx, cy, 1, color, thickness);
}

void Drawer::drawLine(float x1, float y1, float x2, float y2, ALLEGRO_COLOR color = al_map_rgb(0,0,0), float thickness = 1) {
    al_draw_line(x1, y1, x2, y2, color, thickness);
}

void Drawer::drawMesh() {
    for (HalfEdge *HE: halfEdges) {
        Vertex *v1 = HE->V(), *v2 = HE->ETwin()->V();
        // if (v1->index() < v2->index()) {
            drawLine(v1->X(), v1->Y(), v2->X(), v2->Y());
        // }
    }
    for (Vertex *v: vertexs) {
        drawPoint(v->X(), v->Y());
    }
}