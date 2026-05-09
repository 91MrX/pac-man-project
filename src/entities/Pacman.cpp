#include "Pacman.h"
#include "../map/MapManager.h"

Pacman::Pacman() {
}

Pacman::Pacman(int x, int y, int lives, double speed, Direction d, MapManager* map) {
    m_position = Point(x, y);
    this->map = map;
    this->lives = lives;
    this->speed = speed;
    this->dir = d;
    spawnPoint = Point(x, y);
    nextdir = Direction::None;
    moveCooldown = 0.0;
    animTimer = 0.0;
}

Pacman::~Pacman() = default;

void Pacman::setDirection(Direction d) {
    if (d == Direction::None) return;
    nextdir = d;
}

void Pacman::update(float deltaTime) {
    if (!m_active) return;

    moveCooldown -= deltaTime * speed;
    animTimer += deltaTime;

    if (moveCooldown > 0.0) return;
    moveCooldown = 1.0;
    if (nextdir != Direction::None) {
        Point next = m_position;
        switch (nextdir) {
            case Direction::Up:    next.y--; break;
            case Direction::Down:  next.y++; break;
            case Direction::Left:  next.x--; break;
            case Direction::Right: next.x++; break;
            default: break;
        }
        if (canWalkTo(next)) {
            dir = nextdir;
            nextdir = Direction::None;
        }
    }
    if (dir != Direction::None) {
        Point next = m_position;
        switch (dir) {
            case Direction::Up:    next.y--; break;
            case Direction::Down:  next.y++; break;
            case Direction::Left:  next.x--; break;
            case Direction::Right: next.x++; break;
            default: break;
        }
        if (canWalkTo(next)) {
            m_position = next;
            if (map) {
                if (m_position.x < 0) m_position.x = map->getWidth() - 1;
                if (m_position.x >= map->getWidth()) m_position.x = 0;
            }
        }
    }
}

void Pacman::render(sf::RenderWindow& window) {
    static constexpr float TILE_SIZE = 32.0f;
    static constexpr float RADIUS = 13.0f;

    float px = m_position.x * TILE_SIZE + TILE_SIZE / 2.0f;
    float py = m_position.y * TILE_SIZE + TILE_SIZE / 2.0f;

    sf::CircleShape body(RADIUS);
    body.setFillColor(sf::Color::Yellow);
    body.setOrigin(RADIUS, RADIUS);
    body.setPosition(px, py);
    window.draw(body);
    bool open = (static_cast<int>(animTimer * 20) % 2 == 0);
    if (open && dir != Direction::None) {
        float mx = px, my = py;
        float offset = RADIUS * 0.6f;
        switch (dir) {
            case Direction::Up:    my -= offset; break;
            case Direction::Down:  my += offset; break;
            case Direction::Left:  mx -= offset; break;
            case Direction::Right: mx += offset; break;
            default: break;
        }
        float mr = RADIUS * 0.5f;
        sf::CircleShape mouth(mr);
        mouth.setFillColor(sf::Color::Black);
        mouth.setOrigin(mr, mr);
        mouth.setPosition(mx, my);
        window.draw(mouth);
    }
}

sf::FloatRect Pacman::getBounds() const {
    return sf::FloatRect(
        m_position.x * 32.0f, m_position.y * 32.0f,
        32.0f, 32.0f
    );
}

void Pacman::reset() {
    m_position = spawnPoint;
    dir = Direction::None;
    nextdir = Direction::None;
    moveCooldown = 0.0;
}

void Pacman::die() {
    lives--;
    reset();
}
