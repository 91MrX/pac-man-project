#include "PausedState.h"
#include "../core/GameEngine.h"

void PausedState::handleInput(GameEngine& engine, sf::Event& event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) {
        engine.popState();
    }
    if ((event.type == sf::Event::Closed) ||
        (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
        engine.popState();
    }
}

void PausedState::update(float deltaTime) {
    (void)deltaTime;
}

void PausedState::render(sf::RenderWindow& window) {
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/arial.ttf")) {
        return;
    }
    sf::Text pausedText("Game Paused : Press P to Resume \n Press Escape to Quit", font, 50);
    pausedText.setFillColor(sf::Color::Red);
    pausedText.setPosition(200, 200);
    window.draw(pausedText);
}
