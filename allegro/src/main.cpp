#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

#include "../headers/button.h"
#include "../headers/face.h"
#include "../headers/halfedge.h"
#include "../headers/interpreter.h"
#include "../headers/vertex.h"
// #include "questions.cpp"

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

void v2v(Vertex *vertex, HalfEdge* he, Face* face) {
    he = vertex->H();
    drawPoint(he->V()->X(), he->V()->Y(), al_map_rgb(0,255,0));
    do {
        drawPoint(he->ENext()->V()->X(), he->ENext()->V()->Y(), al_map_rgb(255,0,0));
        he = he->ETwin()->ENext();
    } while (he != vertex->H());
}

void v2e(Vertex *vertex, HalfEdge* he, Face* face) {
    he = vertex->H();
    do {
        drawLine(vertex->X(), vertex->Y(), he->ENext()->V()->X(), he->ENext()->V()->Y(), al_map_rgb(255,0,0), 3);
        he = he->ETwin()->ENext();
    } while (he != vertex->H());
}

void v2f(Vertex *vertex, HalfEdge* he, Face* face) {
 //    HalfEdge *he = vertex->H();
 //    do {
 //        drawLine(vertex->X(), vertex->Y(), he->ENext()->V()->X(), he->ENext()->V()->Y(), al_map_rgb(0,0,0), 3);
 //        he = he->ETwin()->ENext();
 //    } while (he != vertex->H());    

 // HE he = v.he;
 // do {
 //     // log he.f
 //     he = he.twin.next;
 // } while (he != v.he);
}

void e2v(Vertex *vertex, HalfEdge* he, Face* face) {
    Vertex *v1 = he->V(), *v2 = he->ETwin()->V();
    drawLine(v1->X(), v1->Y(), v2->X(), v2->Y(), al_map_rgb(0,255,0),1);
    drawPoint(v1->X(), v1->Y(), al_map_rgb(255,0,0));
    drawPoint(v2->X(), v2->Y(), al_map_rgb(255,0,0));
}

void e2e(Vertex *vertex, HalfEdge* he, Face* face) {
    Vertex *v1 = he->V(), *v2 = he->ETwin()->V();
    drawLine(v1->X(), v1->Y(), v2->X(), v2->Y(), al_map_rgb(0,255,0),3);
    vertex = he->V();
    HalfEdge *edge = vertex->H();
    do {
        if (edge->ETwin()->V() != he->ETwin()->V()) {
            v1 = edge->V(), v2 = edge->ETwin()->V();
            drawLine(v1->X(), v1->Y(), v2->X(), v2->Y(), al_map_rgb(255,0,0),1);
        }
        edge = edge->ETwin()->ENext();
    } while (edge != vertex->H());
    vertex = he->ETwin()->V();
    edge = vertex->H();
    do {
        if (edge->ETwin()->V() != he->V()) {
            v1 = edge->V(), v2 = edge->ETwin()->V();
            drawLine(v1->X(), v1->Y(), v2->X(), v2->Y(), al_map_rgb(255,0,0),1);
        }
        edge = edge->ETwin()->ENext();
    } while (edge != vertex->H());
}

void e2f(Vertex *vertex, HalfEdge* he, Face* face) {
    face = he->F();
    HalfEdge *edge = face->H();
    vector<Vertex*> points;
    if (edge != NULL) {
        do {
            drawPoint(edge->ETwin()->V()->X(), edge->ETwin()->V()->Y(), al_map_rgb(255, 0, 0));
            points.push_back(edge->ETwin()->V());
            edge = edge->ENext();
        } while (edge != face->H());

        al_draw_filled_triangle(points[0]->X(), points[0]->Y(), points[1]->X(), points[1]->Y(),
                                points[2]->X(), points[2]->Y(), al_map_rgb(0,255,0));
    }

    points.clear();
    face = he->ETwin()->F();
    edge = face->H();
    if (edge != NULL) {
        do {
            points.push_back(edge->ETwin()->V());
            edge = edge->ENext();
        } while (edge != face->H());    
        al_draw_filled_triangle(points[0]->X(), points[0]->Y(), points[1]->X(), points[1]->Y(),
                                points[2]->X(), points[2]->Y(), al_map_rgb(0,255,0));
    }

    Vertex *v1 = he->V(), *v2 = he->ETwin()->V();
    drawLine(v1->X(), v1->Y(), v2->X(), v2->Y(), al_map_rgb(255,0,0),3);
}

void f2v(Vertex *vertex, HalfEdge* he, Face* face) {
    HalfEdge *edge = face->H();
    do {
        drawPoint(edge->ETwin()->V()->X(), edge->ETwin()->V()->Y(), al_map_rgb(255, 0, 0));
        edge = edge->ENext();
    } while (edge != face->H());
}

void f2e(Vertex *vertex, HalfEdge* he, Face* face) {
    HalfEdge *edge = face->H();
    Vertex *previous = edge->ETwin()->V();
    edge = edge->ENext();
    do {
        drawLine(previous->X(), previous->Y(), edge->ETwin()->V()->X(), edge->ETwin()->V()->Y(), al_map_rgb(255, 0, 0));
        previous = edge->ETwin()->V();
        edge = edge->ENext();
    } while (edge != face->H());
    drawLine(previous->X(), previous->Y(), edge->ETwin()->V()->X(), edge->ETwin()->V()->Y(), al_map_rgb(255, 0, 0));
}

void f2f(Vertex *vertex, HalfEdge* he, Face* face) {
    HalfEdge *edge = face->H();
    Vertex *previous = edge->ETwin()->V();
    edge = edge->ENext();
    do {
        e2f(vertex, edge, face);
        previous = edge->ETwin()->V();
        edge = edge->ENext();
    } while (edge != face->H());
    e2f(vertex, edge, face);

    previous = edge->ETwin()->V();
    edge = edge->ENext();
    do {
        drawLine(previous->X(), previous->Y(), edge->ETwin()->V()->X(), edge->ETwin()->V()->Y());
        previous = edge->ETwin()->V();
        edge = edge->ENext();
    } while (edge != face->H());
    drawLine(previous->X(), previous->Y(), edge->ETwin()->V()->X(), edge->ETwin()->V()->Y());
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

    Interpreter *interpreter = new Interpreter("./input/2.in");
    string line;

    bool running = true;
    int val;
    int buttonActive = 0;

    interpreter->read(vertices, halfEdges, faces);
    Button *b1 = new Button(500, 25, &v2v);
    buttons.push_back(b1);
    b1->V(vertices[0]);
    Button *b2 = new Button(500, 75, &v2e);
    buttons.push_back(b2);
    b2->V(vertices[0]);
    Button *b3 = new Button(500, 125, &v2f);
    buttons.push_back(b3);
    b3->V(vertices[0]);
    Button *b4 = new Button(500, 175, &e2v);
    buttons.push_back(b4);
    b4->V(vertices[0]);
    Button *b5 = new Button(500, 225, &e2e);
    buttons.push_back(b5);
    b5->V(vertices[0]);
    Button *b6 = new Button(500, 275, &e2f);
    buttons.push_back(b6);
    b6->V(vertices[0]);
    Button *b7 = new Button(500, 325, &f2v);
    buttons.push_back(b7);
    b7->V(vertices[0]);
    Button *b8 = new Button(500, 375, &f2e);
    buttons.push_back(b8);
    b8->V(vertices[0]);
    Button *b9 = new Button(500, 425, &f2f);
    buttons.push_back(b9);
    b9->V(vertices[0]);

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
            drawLine(v1->X(), v1->Y(), v2->X(), v2->Y());
        }
        for (Vertex *v: vertices) {
            drawPoint(v->X(), v->Y());
        }

        for (auto button: buttons) {
            button->draw();
        }
        // for (int i = 0; i  <)
        // b1->draw();
        // b2->draw();
        // b3->draw();
        // b4->draw();
        // b5->draw();
        // b6->draw();
        // b7->draw();
        // b8->draw();
        // b9->draw();
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
            val = 0;
            buttonActive = val;
            for (vector<Button*>::iterator it = buttons.begin(); it != buttons.end(); it++) {
                val++;
                if (((*it)->X() < ev.mouse.x && ev.mouse.x < (*it)->X() + 100) && ((*it)->Y() < ev.mouse.y && ev.mouse.y < (*it)->Y() + 100)) {
                    buttonActive = val;
                }
            }
        }

    }

    al_destroy_display(display);

    return 0;

}
