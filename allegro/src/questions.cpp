
void drawPoint(float cx, float cy, ALLEGRO_COLOR color, float thickness);

void drawLine(float x1, float y1, float x2, float y2, ALLEGRO_COLOR color, float thickness);

void v2v(Vertex *vertex, HalfEdge* he, Face* face) {
    he = vertex->H();
    do {
        drawPoint(he->ENext()->V()->X(), he->ENext()->V()->Y(), al_map_rgb(255,0,0));
        he = he->ETwin()->ENext();
    } while (he != vertex->H());
}

void v2e(Vertex *vertex, HalfEdge* he, Face* face) {
    he = vertex->H();
    do {
        drawLine(vertex->X(), vertex->Y(), he->ENext()->V()->X(), he->ENext()->V()->Y(), al_map_rgb(0,0,0), 3);
        he = he->ETwin()->ENext();
    } while (he != vertex->H());
}

// void v2f(Vertex *vertex, HalfEdge* he, Face* face) {
//     HalfEdge *he = vertex->H();
//     do {
//         drawLine(vertex->X(), vertex->Y(), he->ENext()->V()->X(), he->ENext()->V()->Y(), al_map_rgb(0,0,0), 3);
//         he = he->ETwin()->ENext();
//     } while (he != vertex->H());    

// 	HE he = v.he;
// 	do {
// 		// log he.f
// 		he = he.twin.next;
// 	} while (he != v.he);
// }

void e2v(Vertex *vertex, HalfEdge* he, Face* face) {
    Vertex *v1 = he->V(), *v2 = he->ETwin()->V();
    drawLine(v1->X(), v1->Y(), v2->X(), v2->Y(), al_map_rgb(0,255,0),1);
    drawPoint(v1->X(), v1->Y(), al_map_rgb(255,0,0));
    drawPoint(v2->X(), v2->Y(), al_map_rgb(255,0,0));
}

void e2e(Vertex *vertex, HalfEdge* he, Face* face) {
    Vertex *v1 = he->V(), *v2 = he->ETwin()->V();
    drawLine(v1->X(), v1->Y(), v2->X(), v2->Y(), al_map_rgb(0,255,0),3);
    Vertex *vertex = he->V();
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
    edge = face->H();
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
        e2f(edge);
        previous = edge->ETwin()->V();
        edge = edge->ENext();
    } while (edge != face->H());
    e2f(edge);

    previous = edge->ETwin()->V();
    edge = edge->ENext();
    do {
        drawLine(previous->X(), previous->Y(), edge->ETwin()->V()->X(), edge->ETwin()->V()->Y());
        previous = edge->ETwin()->V();
        edge = edge->ENext();
    } while (edge != face->H());
    drawLine(previous->X(), previous->Y(), edge->ETwin()->V()->X(), edge->ETwin()->V()->Y());
}