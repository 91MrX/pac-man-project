#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "InputHandler.h"

class GameState;

class GameEngine {
public:
    GameEngine();
    ~GameEngine();
    void run();
    void changeState(std::unique_ptr<GameState> newState);

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

    sf::RenderWindow m_window;
    sf::Clock m_clock;
    InputHandler m_inputHandler;
    std::unique_ptr<GameState> m_currentState;
};