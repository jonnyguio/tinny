#include <vertex.h>

Vertex::Vertex() {
    this->x = 0;
    this->y = 0;
}

Vertex::Vertex(float nx, float ny) {
    this->x = nx;
    this->y = ny;
}

float Vertex::X() { return this->x; }
void Vertex::X(float nx) { this->x = nx; }
float Vertex::Y() { return this->y; }
void Vertex::Y(float ny) { this->y = ny; }
