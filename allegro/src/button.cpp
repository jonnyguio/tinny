#include "../headers/button.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>

using namespace std;

Button::Button(int nx, int ny) {
    this->x = nx;
    this->y = ny;
    this->func = NULL;
    this->v = NULL;
    this->h = NULL;
    this->f = NULL;
}

Button::Button(int nx, int ny, void (*nfunc)(Vertex *v, HalfEdge *h, Face *f)) {
    this->x = nx;
    this->y = ny;
    this->func = nfunc;
    this->v = NULL;
    this->h = NULL;
    this->f = NULL;
}
//Button::Button(int nx, int ny, void (*nfunc)(Vertex *v, HalfEdge *h, Face *f), ALLEGRO_BITMAP *nimage);

int Button::X() { return this->x; }
void Button::X(int nx) { this->x = nx; }

int Button::Y() { return this->y; }
void Button::Y(int ny) { this->y = ny; }

Vertex* Button::V() { return this->v; }
void Button::V(Vertex *nv) { this->v = nv; }
HalfEdge* Button::H() { return this->h; }
void Button::H(HalfEdge *nh) { this->h = nh; }
Face* Button::F() { return this->f; }
void Button::F(Face *nf) { this->f = nf; }

void Button::Func(void (*nfunc)(Vertex *v, HalfEdge *h, Face *f)) { this->func = nfunc; }
void Button::Func(Vertex *nv, HalfEdge *he, Face *f) {
    this->func(nv, he, f);
}
void Button::Func() {
    this->func(this->v, this->h, this->f);
}

void Button::draw() {
    al_draw_rectangle((float) this->x, (float) this->y, (float) this->x + 100, (float) this->y + 50, al_map_rgb(100, 100, 100), 2);
}

//ALLEGRO_BITMAP Button::Image() { return this->image; }
//void Button::Image(ALLEGRO_IMAGE *nimage) { this->image = nimage; }
