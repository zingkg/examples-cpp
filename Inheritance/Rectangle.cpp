#include "Rectangle.hpp"

Rectangle::Rectangle(): length(0), width(0) {
}

Rectangle::Rectangle(float length, float width): length(length), width(width) {
}

Rectangle::~Rectangle() {
}

float Rectangle::area() const {
    return length * width;
}

float Rectangle::perimeter() const {
    return 2 * length + 2 * width;
}
