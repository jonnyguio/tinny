#include "../headers/interpreter.h"
#include "../headers/vector2d.h"
#include <iostream>

using namespace std;

Interpreter::Interpreter(char const *fn) {
    this->filename = fn;
    this->file.open(fn);
}

Interpreter::~Interpreter() {
    this->file.close();
}

ifstream* Interpreter::File() { return &(this->file); }

void Interpreter::read(vector<Vertex*>& vs, vector<HalfEdge*>& hes, vector<Face*>& fs) {
    int countV = 0, countH = 0, countF = 0, counter[4];
    char type;
    float a, b, c, aux = 0.0;
    HalfEdge *h1, *h2, *h3, *haux;
    Vertex *v;
    Face *f;
    Vector2D *v1, *v2;
    vector<vector<float>> faces;
    vector<vector<int>> vertices;
    bool outsideFace = false;

    while (this->file >> type) {
        if (type == 'v') {
            this->file >> a >> b;
            v = new Vertex(a, b);
            vs.push_back(v);
            countV++;
        }
        if (type == 'f') {
            this->file >> a >> b >> c;

            v1 = new Vector2D(vs[b-1]->X() - vs[a-1]->X(), vs[b-1]->Y() - vs[a-1]->Y());
            v2 = new Vector2D(vs[c-1]->X() - vs[a-1]->X(), vs[c-1]->Y() - vs[a-1]->Y());

            if (v1->cross(v2) < 0) {
                aux = b;
                b = c;
                c = aux;
            }

            cout << a << " " << b << " " << c << endl;

            h1 = new HalfEdge(vs[a-1]); h2 = new HalfEdge(vs[b-1]); h3 = new HalfEdge(vs[c-1]);

            hes.push_back(h1); hes.push_back(h2); hes.push_back(h3);

            h1->ENext(h2); h2->ENext(h3); h3->ENext(h1);

            f = new Face(h1);
            fs.push_back(f);
            h1->F(f); h2->F(f); h3->F(f);

            countF++;
            countH += 6;

            counter[3] = 0;
            for (vector<vector<float>>::iterator it = faces.begin(); it != faces.end(); it++) {
                counter[0] = 0;
                counter[1] = 0;
                counter[2] = 0;
                for (int i = 0; i < 3; i++) {
                    if ((*it)[i] == a || (*it)[i] == b)
                        counter[0]++;
                    if ((*it)[i] == b || (*it)[i] == c)
                        counter[1]++;
                    if ((*it)[i] == c || (*it)[i] == a)
                        counter[2]++;
                }
                if (counter[0] == 2) {
                    haux = HalfEdge::searchHalfEdge(hes, vs[b-1], fs[counter[3]]);
                    haux->ETwin(h1);
                    h1->ETwin(haux);
                    break;
                }
                if (counter[1] == 2) {
                    haux = HalfEdge::searchHalfEdge(hes, vs[c-1], fs[counter[3]]);
                    haux->ETwin(h2);
                    h2->ETwin(haux);
                    break;
                }
                if (counter[2] == 2) {
                    haux = HalfEdge::searchHalfEdge(hes, vs[a-1], fs[counter[3]]);
                    haux->ETwin(h3);
                    h3->ETwin(haux);
                    break;
                }
                counter[3]++;
            }
            vector<float> faceInput;
            faceInput.push_back(a); faceInput.push_back(b); faceInput.push_back(c);
            faces.push_back(faceInput);

            delete v1;
            delete v2;
        }
    }

    counter[0] = 0;
    counter[1] = 0;
    for (vector<vector<float>>::iterator it = faces.begin(); it != faces.end(); it++) {

        for (int i = 0; i < 3; i++) {
            if (hes[counter[0] * 3 + i]->ETwin() == NULL) {
                haux = new HalfEdge(vs[faces[counter[0]][(i + 1) % 3] - 1], hes[counter[0] * 3 + i]);
                hes[counter[0] * 3 + i]->ETwin(haux);
                hes.push_back(haux);
                counter[1]++;
                vector<int> vertexInput;
                vertexInput.push_back(faces[counter[0]][(i + 1) % 3]);
                vertexInput.push_back(faces[counter[0]][i % 3]);
                vertices.push_back(vertexInput);
            }
        }
        counter[0]++;
    }

    for (int i = counter[1]; i > 0; i--) {
        cout << vertices[counter[1] - i][0] << "," << vertices[counter[1] - i][1] << endl;
        for (int j = counter[1];  j > 0 ; j--) {
            cout << "\t" << vertices[counter[1] - j][0] << "," << vertices[counter[1] - j][1] << endl;
            if (vertices[counter[1] - i][1] == vertices[counter[1] - j][0] && i != j) {
                hes[hes.size() - i]->ENext(hes[hes.size() - j]);
            }
        }
    }
}
