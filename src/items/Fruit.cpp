#include "Fruit.h"

Fruit::Fruit(int x, int y) {
    m_position = Point(x, y);
}

ItemType Fruit::onCollect() {
    return ItemType::Fruit;
}

int Fruit::getScore() const {
    return m_score;
}

void Fruit::render(sf::RenderWindow& window) {
    if (!m_active) return;
    static constexpr float TILE_SIZE = 32.0f;
    float cx = m_position.x * TILE_SIZE + TILE_SIZE / 2.0f;
    float cy = m_position.y * TILE_SIZE + TILE_SIZE / 2.0f;
    sf::CircleShape shape(10.f);
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin(10.f, 10.f);
    shape.setPosition(cx, cy);
    window.draw(shape);
    sf::CircleShape stem(2.f);
    stem.setFillColor(sf::Color(0, 128, 0));
    stem.setOrigin(2.f, 2.f);
    stem.setPosition(cx, cy - 10.f);
    window.draw(stem);
}
