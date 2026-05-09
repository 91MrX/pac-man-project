#pragma once
#include "Character.h"
class Pacman : public Character {
    public:
    Pacman();
    Pacman(int x,int y,int lives,double speed,Direction dir,MapManager* map);
    virtual ~Pacman();
    int lives;
    double moveCooldown;
    double animTimer;
    Point spawnPoint;
    void setDirection(Direction dir);
    void update(float deltaTime) override;
    void render(sf::RenderWindow &window) override;
    sf::FloatRect getBounds() const override;
    void reset();
    void die();
};