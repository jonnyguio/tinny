v2v(Vertex *vertex) {
    HalfEdge *he = vertex->H();
    do {
        // log he.v
        cout << "meh" << ", " << he->V()->X() << ", " << he->V()->Y() << endl;
        drawPoint(he->ENext()->V()->X(), he->ENext()->V()->Y(), al_map_rgb(255,0,0));
        he = he->ETwin()->ENext();
    } while (he != vertex->H());
}

v2e(Vertex *vertex) {
    HalfEdge *he = vertex->H();
    do {
        drawLine(vertex->X(), vertex->Y(), he->ENext()->V()->X(), he->ENext()->V()->Y(), al_map_rgb(0,0,0), 3);
        he = he->ETwin()->ENext();
    } while (he != vertex->H());
}

v2f(vertex v) {
	HE he = v.he;
	do {
		// log he.f
		he = he.twin.next;
	} while (he != v.he);
}

e2v(HalfEdge *he) {
    Vertex *v1 = he->V(), *v2 = he->ETwin()->V();
    drawLine(v1->X(), v1->Y(), v2->X(), v2->Y(), al_map_rgb(0,255,0),1);
    drawPoint(v1->X(), v1->Y(), al_map_rgb(255,0,0));
    drawPoint(v2->X(), v2->Y(), al_map_rgb(255,0,0));
}

e2e(HalfEdge *he) {
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

e2f(he f) {
	// log e.f
	// log e.twin.f
}

f2v(Face *face) {
    HalfEdge *edge = face->H();
    do {
        drawPoint(edge->ETwin()->V()->X(), edge->ETwin()->V()->Y(), al_map_rgb(255, 0, 0));
        edge = edge->ENext();
    } while (edge != face->H());
}

f2e(face f) {
	HE_edge* edge = face->edge;

	 do {

	    // log edge
	    edge = edge->next;

	 } while (edge != face->edge);
}

f2e(face f) {
	HE_edge* edge = face->edge;

	 do {

	    // log edge->face
	    edge = edge->next;

	 } while (edge != face->edge);
}
