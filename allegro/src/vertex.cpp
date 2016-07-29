#include "../headers/vertex.h"

Vertex::Vertex() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vertex::Vertex(float nx, float ny, float nz) {
    this->x = nx;
    this->y = ny;
    this->z = nz;
}

float Vertex::X() { return this->x; }
void Vertex::X(float nx) { this->x = nx; }
float Vertex::Y() { return this->y; }
void Vertex::Y(float ny) { this->y = ny; }
float Vertex::Z() { return this->z; }
void Vertex::Z(float nz) { this->z = nz; }
