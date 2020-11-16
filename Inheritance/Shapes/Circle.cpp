#include "Circle.hpp"

#include <cmath>

Circle::Circle(): radius(0) {
}

Circle::Circle(float radius): radius(radius) {
}

Circle::~Circle() {
}

float Circle::area() const {
    return pi() * radius * radius;
}

float Circle::perimeter() const {
    return 2 * pi() * radius;
}

constexpr double Circle::pi() {
    return std::atan(1) * 4;
}
