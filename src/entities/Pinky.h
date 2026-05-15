#pragma once
#include "Ghost.h"

class Pinky : public Ghost {
public:
    Point chase(const Point& pacmanPos, const Point& blinkyPos,Direction pacmanDir) override;
    sf::Color getColor() const override { return sf::Color(255, 192, 203); }
    using Ghost::Ghost;
    Point GetPinkyPoint()const ;
    Point GetPinkyStartPoint()const;
};