#include "../headers/interpreter.h"
#include <iostream>

Interpreter::Interpreter(char const *fn) {
    this->filename = fn;
    this->file.open(fn);
}

Interpreter::~Interpreter() {
    this->file.close();
}

ifstream* Interpreter::File() { return &(this->file); }

void Interpreter::read(vector<Vertex*>& vs, vector<HalfEdge*>& hes, vector<Face*>& fs) {
    // int countV = 0, countH = 0, countF = 0;
    char type;
    HalfEdge *h1, *h2, *h3;
    Vertex *v;
    // Face *f;

    vector<HalfEdge*> HEvec;

    using Edge = pair<int,int>; 
    map<Edge, int> S;
    vector<vector<int> > faces;

    while (this->file >> type) {
        if (type == 'v') {
            float a, b, c;
            this->file >> a >> b >> c;
            cout << type << ", " << a << ", " << b << ", " << c << endl;
            v = new Vertex(a, b, c);
            vs.push_back(v);
            // countV++;
        }
        if (type == 'f') {
            int p1, p2, p3;
            this->file >> p1 >> p2 >> p3;
            cout << type << ", " << p1 << ", " << p2 << ", " << p3 << endl;
            // if (!ccw(p1,p2,p3)) swap(p2,p3);
            pair<int,int> a(p1,p2), b(p2,p3), c(p3,p2);

            h1 = new HalfEdge(vs[p2-1]); h2 = new HalfEdge(vs[p3-1]); h3 = new HalfEdge(vs[p1-1]);

            HEvec.push_back(h1);
            cout << HEvec.size()-1 << ", " << p1 << ", " << p2 << endl;
            auto it = S.find(Edge(min(p1,p2), max(p1,p2)));
            if (it != S.end()) {
                int ind = S[Edge(min(p1,p2), max(p1,p2))];
                cout << "    tem twin: " << ind << endl;
                HEvec[ind]->ETwin(HEvec.back());
                HEvec.back()->ETwin(HEvec[ind]);
            }
            S[Edge(min(p1,p2), max(p1,p2))] = HEvec.size()-1;

            HEvec.push_back(h2);
            cout << HEvec.size()-1 << ", " << p2 << ", " << p3 << endl;
            it = S.find(Edge(min(p2,p3), max(p2,p3)));
            if (it != S.end()) {
                // tem twin
                int ind = S[Edge(min(p2,p3), max(p2,p3))];
                cout << "    tem twin: " << ind << endl;
                HEvec[ind]->ETwin(HEvec.back());
                HEvec.back()->ETwin(HEvec[ind]);
            }
            S[Edge(min(p2,p3), max(p2,p3))] = HEvec.size()-1;

            HEvec.push_back(h3);
            cout << HEvec.size()-1 << ", " << p3 << ", " << p1 << endl;
            it = S.find(Edge(min(p3,p1), max(p3,p1)));
            if (it != S.end()) {
                // tem twin
                int ind = S[Edge(min(p3,p1), max(p3,p1))];
                cout << "    tem twin: " << ind << endl;
                HEvec[ind]->ETwin(HEvec.back());
                HEvec.back()->ETwin(HEvec[ind]);
            }
            S[Edge(min(p3,p1), max(p3,p1))] = HEvec.size()-1;


            // h4 = new HalfEdge(vs[b-1], h1); h5 = new HalfEdge(vs[c-1], h2); h6 = new HalfEdge(vs[a-1], h3);

            // hes.push_back(h1); hes.push_back(h2); hes.push_back(h3);
            // hes.push_back(h4); hes.push_back(h5); hes.push_back(h6);

            // h1->ENext(h2); h2->ENext(h3); h3->ENext(h1);
            // h4->ENext(h5); h5->ENext(h6); h6->ENext(h4);

            // f = new Face(h1);
            // fs.push_back(f);
            // h1->F(f); h2->F(f); h3->F(f); h4->F(f); h5->F(f); h6->F(f);

            // countF++;
            // countH += 6;
        }
    }
    for (int i = 0; i < (int) HEvec.size(); i++) {
        cout << HEvec[i]->V()->X();
        if (HEvec[i]->ETwin() != NULL)
            cout << ", " << HEvec[i]->ETwin()->V()->X();
        cout << endl;
    }
}
