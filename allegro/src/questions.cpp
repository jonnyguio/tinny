v2v(vertex v) {
	HE he = v.he;
	do {
		// log he.v
		he = he.twin.next;
	} while (he != v.he);
}

v2e(vertex v) {
	HE he = v.he;
	do {
		// log he
		he = he.twin.next;
	} while (he != v.he);
}

v2f(vertex v) {
	HE he = v.he;
	do {
		// log he.f
		he = he.twin.next;
	} while (he != v.he);
}

e2v(he e) {
	vertex v = e.v;
	HE he = v.he;
	do {
		// if (he.v != e.twin.v) log he.v 
		he = he.twin.next;
	} while (he != v.he);
	v = e.twin.v;
	he = v.he;
	do {
		// if (he.v != e.v) log he.v
		he = he.twin.next;
	} while (he != v.he);
}

e2e(he e) {

}

e2f(he f) {
	
}