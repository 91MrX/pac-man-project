#include "PowerPellet.h"

PowerPellet::PowerPellet(int x, int y) {
    m_position = Point(x, y);
}

ItemType PowerPellet::onCollect() {
    return ItemType::PowerPellet;
}

int PowerPellet::getScore() const {
    return m_score;
}

void PowerPellet::render(sf::RenderWindow& window) {
    if (!m_active) return;
    static constexpr float TILE_SIZE = 32.0f;
    float cx = m_position.x * TILE_SIZE + TILE_SIZE / 2.0f;
    float cy = m_position.y * TILE_SIZE + TILE_SIZE / 2.0f;
    float radius = 8.f;
    sf::CircleShape shape(radius);
    shape.setFillColor(sf::Color(255, 255, 200));
    shape.setOrigin(radius, radius);
    shape.setPosition(cx, cy);
    window.draw(shape);
}
