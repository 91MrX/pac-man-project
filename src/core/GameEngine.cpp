#include "GameEngine.h"
#include "../states/GameState.h"

GameEngine::GameEngine()
    : m_window(sf::VideoMode(800, 800), "Pacman Game", sf::Style::Resize | sf::Style::Close) {
    m_window.setFramerateLimit(60);
}

GameEngine::~GameEngine() {}

void GameEngine::run() {
    while (m_window.isOpen()) {
        processEvents();
        update(m_clock.restart());
        render();
    }
}

void GameEngine::changeState(std::unique_ptr<GameState> newState) {
    m_currentState = std::move(newState);
}

void GameEngine::processEvents() {
    sf::Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed ||
            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
            m_window.close();
        }
        m_inputHandler.handleEvents(event);
        if (m_currentState) {
            m_currentState->handleInput(*this, event);
        }
    }
}

void GameEngine::update(sf::Time deltaTime) {
    if (m_currentState) {
        m_currentState->update(*this, deltaTime.asSeconds());
    }
}

void GameEngine::render() {
    m_window.clear(sf::Color(144, 238, 144));
    if (m_currentState) {
        m_currentState->render(m_window);
    }
    m_window.display();
}
