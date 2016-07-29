#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

#include "../headers/button.h"
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

void test(Vertex *v, HalfEdge *h, Face *f) {
    cout << "yay" << endl;
}

void v2v(Vertex *vertex, HalfEdge *h, Face *f) {
    HalfEdge *he = vertex->H();
    drawPoint(he->V()->X(), he->V()->Y(), al_map_rgb(0,255,0));
    do {
        // log he.v
        //cout << "meh" << ", " << he->V()->X() << ", " << he->V()->Y() << endl;
        drawPoint(he->ENext()->V()->X(), he->ENext()->V()->Y(), al_map_rgb(255,0,0));
        he = he->ETwin()->ENext();
    } while (he != vertex->H());
}

int main(int argc, char **argv) {
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *evQueue = NULL;
    ALLEGRO_EVENT ev;
    ALLEGRO_COLOR lineColor;
    ALLEGRO_MOUSE_STATE msState;

    vector<Button*> buttons;
    vector<Face*> faces;
    vector<HalfEdge*> halfEdges;
    vector<Vertex*> vertices;

    Button *b = new Button(500, 50, &v2v);
    buttons.push_back(b);
    Interpreter *interpreter = new Interpreter("./input/2.in");
    string line;

    bool running = true;
    int val;
    int buttonActive = 0;

    interpreter->read(vertices, halfEdges, faces);
    b->V(vertices[0]);

    Vertex::printAll(vertices);
    HalfEdge::printAll(halfEdges);
    Face::printAll(faces);

    if(!al_init())
    {
        al_show_native_message_box(NULL, NULL, NULL, "failed to initialize allegro!", NULL, 0);
        return -1;
    }

    if (!al_init_primitives_addon()) {
        al_show_native_message_box(NULL, NULL, NULL, "failed to initialize primitives!", NULL, 0);
    }

    al_install_keyboard();
    al_install_mouse();
    display = al_create_display(640, 480);
    evQueue = al_create_event_queue();
    al_register_event_source(evQueue, al_get_keyboard_event_source());
    al_register_event_source(evQueue, al_get_mouse_event_source());
    al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);

    if(!display)
    {
        al_show_native_message_box(NULL, NULL, NULL, "failed to initialize display!", NULL, 0);
        return -1;
    }

    while (running) {
        al_clear_to_color(al_map_rgb(255,255,255));

        for (HalfEdge *HE: halfEdges) {
            Vertex *v1 = HE->V(), *v2 = HE->ETwin()->V();
            // if (v1->index() < v2->index()) {
                drawLine(v1->X(), v1->Y(), v2->X(), v2->Y());
            // }
        }
        for (Vertex *v: vertices) {
            drawPoint(v->X(), v->Y());
        }

        b->draw();
        if (buttonActive > 0) {
            buttons[buttonActive-1]->Func();
        }

        al_flip_display();

        al_wait_for_event(evQueue, &ev);
        al_get_mouse_state(&msState);
        if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            if (ev.keyboard.keycode == ALLEGRO_KEY_DOWN) {
                running = false;
            }
        }
        if (ev.type == ALLEGRO_EVENT_MOUSE_AXES) {
            for (vector<Button*>::iterator it = buttons.begin(); it != buttons.end(); it++) {
                if (((*it)->X() < ev.mouse.x && ev.mouse.x < (*it)->X() + 100) && ((*it)->Y() < ev.mouse.y && ev.mouse.y < (*it)->Y() + 100)) {
                    if (msState.buttons & 1) {
                        buttonActive = 1;
                    }
                }
            }
        }

    }

    al_destroy_display(display);

    return 0;

}
