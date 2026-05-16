#include "Dot.h"

Dot::Dot(int x, int y) {
    m_position = Point(x, y);
}

ItemType Dot::onCollect() {
    return ItemType::Dot;
}

int Dot::getScore() const {
    return m_score;
}

void Dot::render(sf::RenderWindow& window) {
    if (!m_active) return;
    static constexpr float TILE_SIZE = 32.0f;
    float cx = m_position.x * TILE_SIZE + TILE_SIZE / 2.0f;
    float cy = m_position.y * TILE_SIZE + TILE_SIZE / 2.0f;
    sf::CircleShape shape(3.f);
    shape.setFillColor(sf::Color(255, 183, 174));
    shape.setOrigin(3.f, 3.f);
    shape.setPosition(cx, cy);
    window.draw(shape);
}
