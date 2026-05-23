#include"PausedState.h"
#include "../core/GameEngine.h"
#include "MenuState.h"

void PausedState::handleInput(GameEngine& engine, sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) {
        engine.popState(); // Return to PlayingState
    }
    if ((event.type == sf::Event::Closed)||(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
    {
        engine.popState();
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R)
    {
        engine.restartGame(new MenuState());
    }
    // 手柄: A键(0)或Start键(7)继续，B键(1)退出，X键(2)重新开始
    if (event.type == sf::Event::JoystickButtonPressed) {
        if (event.joystickButton.button == 0 || event.joystickButton.button == 7) {
            engine.popState();
        }
        if (event.joystickButton.button == 1) {
            engine.popState();
        }
        if (event.joystickButton.button == 2) {
            engine.restartGame(new MenuState());
        }
    }
}
void PausedState::update(GameEngine& engine, float deltaTime)
{
}
void PausedState::render(sf::RenderWindow& window)
{
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/MiSans-Bold.ttf")) {
        return;
    }
    float winW = static_cast<float>(window.getSize().x);
    float winH = static_cast<float>(window.getSize().y);

    sf::Text titleText(L"游戏暂停", font, 60);
    titleText.setFillColor(sf::Color::Red);
    auto titleBounds = titleText.getLocalBounds();
    titleText.setPosition((winW - titleBounds.width) / 2, winH * 0.3f);
    window.draw(titleText);

    sf::Text hintText(L"按P键继续 | 按ESC键退出", font, 30);
    hintText.setFillColor(sf::Color::White);
    auto hintBounds = hintText.getLocalBounds();
    hintText.setPosition((winW - hintBounds.width) / 2, winH * 0.5f);
    window.draw(hintText);

    sf::Text restartText(L"按R键重新开始", font, 30);
    restartText.setFillColor(sf::Color::Yellow);
    auto restartBounds = restartText.getLocalBounds();
    restartText.setPosition((winW - restartBounds.width) / 2, winH * 0.7f);
    window.draw(restartText);
}
