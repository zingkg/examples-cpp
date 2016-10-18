#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Shape.hpp"

class Rectangle : public Shape {
public:
    Rectangle();

    Rectangle(float length, float width);

    virtual ~Rectangle();

    virtual float area() const override;

    virtual float perimeter() const override;

protected:
    float length;
    float width;
};

#endif // RECTANGLE_HPP
