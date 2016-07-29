#ifndef __DGUARD_BUTTON__
#define __DGUARD_BUTTON__

#include "face.h"
#include "halfedge.h"
#include "vertex.h"
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class Button {
    private:
        int x, y;
        Vertex *v;
        HalfEdge *h;
        Face *f;
        //ALLEGRO_BITMAP *image;
        void (*func)(Vertex *v, HalfEdge *h, Face *f);
        char const *text;

    public:
        Button(int nx, int ny, char const *ntext);
        Button(int nx, int ny, char const *ntext, void (*nfunc)(Vertex *v, HalfEdge *h, Face *f));
        //Button(int nx, int ny, void (*nfunc)(Vertex *v, HalfEdge *h, Face *f), ALLEGRO_BITMAP *nimage);

        int X(); void X(int nx);
        int Y(); void Y(int ny);

        Vertex* V(); void V(Vertex *nv);
        HalfEdge* H(); void H(HalfEdge *nh);
        Face* F(); void F(Face *nf);

        void Func(void (*nfunc)(Vertex *v, HalfEdge *h, Face *f));
        void Func(Vertex *nv, HalfEdge *he, Face *f);
        void Func();
        void draw(ALLEGRO_FONT *font);
        //ALLEGRO_BITMAP Image(); void Image(ALLEGRO_IMAGE *nimage);
};

#endif
