#pragma once
#include "Ghost.h"
class Inky : public Ghost {
    public:
    Point GetInkyPoint() const;
    using Ghost::Ghost;
    Point chase(const Point& pacmanPos, const Point& blinkyPos,Direction pacmanDir) override;
    sf::Color getColor() const override { return sf::Color::Cyan; }
    Point GetInkyStartPoint() const;
};