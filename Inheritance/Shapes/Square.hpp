#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "Rectangle.hpp"

class Square : public Rectangle {
public:
    Square();

    Square(float length);

    virtual ~Square();
};

#endif // SQUARE_HPP
