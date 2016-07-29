#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

#include "../headers/drawer.h"
#include "../headers/face.h"
#include "../headers/halfedge.h"
#include "../headers/interpreter.h"
#include "../headers/vertex.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void drawPoint(float cx, float cy, ALLEGRO_COLOR color = al_map_rgb(0,0,0), float thickness = 5) {
    al_draw_circle(cx, cy, 1, color, thickness);
}

void drawLine(float x1, float y1, float x2, float y2, ALLEGRO_COLOR color = al_map_rgb(0,0,0), float thickness = 1) {
    al_draw_line(x1, y1, x2, y2, color, thickness);
}

int main(int argc, char **argv) {
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_COLOR lineColor;

    vector<Face*> faces;
    vector<HalfEdge*> halfEdges;
    vector<Vertex*> vertexs;

    Interpreter *interpreter = new Interpreter("./input/1.in");
    string line;

    interpreter->read(vertexs, halfEdges, faces);

    if(!al_init())
    {
        al_show_native_message_box(NULL, NULL, NULL, "failed to initialize allegro!", NULL, 0);
        return -1;
    }

    if (!al_init_primitives_addon()) {
        al_show_native_message_box(NULL, NULL, NULL, "failed to initialize primitives!", NULL, 0);
    }

    display = al_create_display(640, 480);

    if(!display)
    {
        al_show_native_message_box(NULL, NULL, NULL, "failed to initialize display!", NULL, 0);
        return -1;
    }
    al_clear_to_color(al_map_rgb(255,255,255));

    for (HalfEdge *HE: halfEdges) {
        Vertex *v1 = HE->V(), *v2 = HE->ETwin()->V();
        // if (v1->index() < v2->index()) {
            drawLine(v1->X(), v1->Y(), v2->X(), v2->Y());
        // }
    }
    for (Vertex *v: vertexs) {
        drawPoint(v->X(), v->Y());
    }

    al_flip_display();
    al_rest(5.0);
    
    al_destroy_display(display);

    return 0;

}
