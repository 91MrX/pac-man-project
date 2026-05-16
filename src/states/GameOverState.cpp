#include"GameOverState.h"
#include "../core/GameEngine.h"
#include "MenuState.h"
#include "PlayingState.h"

GameOverState::GameOverState(bool won, int finalScore) : m_won(won), m_finalScore(finalScore) {
}
void GameOverState::handleInput(GameEngine& engine, sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
        engine.changeState(new MenuState()); // Return to menu
    }
    if ((event.type == sf::Event::Closed)||(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
    {
        engine.popState(); // Close the game
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R)
    {
        engine.changeState(new PlayingState()); // Restart the game
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

    sf::Text hintText("Press Enter to Return to Menu\nPress R to Restart\nPress Escape to Quit", font, 28);
    hintText.setFillColor(sf::Color::White);
    auto hintBounds = hintText.getLocalBounds();
    hintText.setPosition((winW - hintBounds.width) / 2, winH * 0.55f);
    window.draw(hintText);
}
