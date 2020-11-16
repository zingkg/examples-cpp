#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Shape.hpp"

class Circle : public Shape {
public:
    Circle();

    Circle(float radius);

    virtual ~Circle();

    virtual float area() const override;

    virtual float perimeter() const override;

private:
    float radius;

    static constexpr double pi();
};

#endif // CIRCLE_HPP
