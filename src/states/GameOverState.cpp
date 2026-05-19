#include"GameOverState.h"
#include "../core/GameEngine.h"
#include "MenuState.h"

GameOverState::GameOverState(bool won, int finalScore) : m_won(won), m_finalScore(finalScore) {
}
void GameOverState::handleInput(GameEngine& engine, sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
        engine.restartGame(new MenuState());
    }
    if ((event.type == sf::Event::Closed)||(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
    {
        engine.quit();
    }
    // 手柄: A键(0)回菜单，B键(1)退出
    if (event.type == sf::Event::JoystickButtonPressed) {
        if (event.joystickButton.button == 0) {
            engine.restartGame(new MenuState());
        }
        if (event.joystickButton.button == 1) {
            engine.quit();
        }
    }
}
void GameOverState::update(GameEngine& engine, float deltaTime)
{
}
void GameOverState::render(sf::RenderWindow& window)
{
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/MiSans-Bold.ttf")) {
        return;
    }
    float winW = static_cast<float>(window.getSize().x);
    float winH = static_cast<float>(window.getSize().y);

    sf::Text resultText(m_won ? "You Win!" : "You Lose!", font, 70);
    resultText.setFillColor(m_won ? sf::Color::Green : sf::Color::Red);
    auto resultBounds = resultText.getLocalBounds();
    resultText.setPosition((winW - resultBounds.width) / 2, winH * 0.18f);
    window.draw(resultText);

    sf::Text scoreText("Final Score: " + std::to_string(m_finalScore), font, 50);
    scoreText.setFillColor(sf::Color::Yellow);
    auto scoreBounds = scoreText.getLocalBounds();
    scoreText.setPosition((winW - scoreBounds.width) / 2, winH * 0.38f);
    window.draw(scoreText);

    const std::string lines[] = {
        "Press Enter to Return to Menu",
        "Press Escape to Quit"
    };
    for (int i = 0; i < 2; i++) {
        sf::Text line(lines[i], font, 28);
        line.setFillColor(sf::Color::White);
        auto lb = line.getLocalBounds();
        line.setPosition((winW - lb.width) / 2, winH * 0.55f + i * 40.f);
        window.draw(line);
    }
}
