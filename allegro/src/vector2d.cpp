#include "../headers/vector2d.h"

Vector2D::Vector2D() {
    this->a = 0;
    this->b = 0;
}

Vector2D::Vector2D(float na, float nb) {
    this->a = na;
    this->b = nb;
}

float Vector2D::A() { return this->a; }
float Vector2D::B() { return this->b; }
void Vector2D::A(float na) { this->a = na; }
void Vector2D::B(float nb) { this->b = nb; }

float Vector2D::dot(Vector2D *v2) {
    return this->a * v2->A() + this->b * v2->B();
}
