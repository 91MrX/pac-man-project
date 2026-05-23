#include "MenuState.h"
#include "../core/GameEngine.h"
#include "PlayingState.h"
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

static const std::vector<std::string> MAP_LIST = {
    "assets/maps/map1.txt",
    "assets/maps/map2.txt",
    "assets/maps/map3.txt"
};

MenuState::MenuState(int highScore): highScore(highScore)
{
    std::ifstream file("highscore.txt");
    if (file.is_open()) {
        file >> this->highScore;
    }
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

std::string MenuState::selectMap() {
    return MAP_LIST[std::rand() % MAP_LIST.size()];
}

void MenuState::handleInput(GameEngine& engine, sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
        engine.changeState(new PlayingState(selectMap()));
    }
    if ((event.type == sf::Event::Closed)||(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
    {
        engine.quit();
    }
    // 手柄: A键(0)或Start键(7)开始，B键(1)退出
    if (event.type == sf::Event::JoystickButtonPressed) {
        if (event.joystickButton.button == 0 || event.joystickButton.button == 7) {
            engine.changeState(new PlayingState(selectMap()));
        }
        if (event.joystickButton.button == 1) {
            engine.quit();
        }
    }
}
void MenuState::update(GameEngine& engine, float deltaTime)
{
}
void MenuState::render(sf::RenderWindow& window)
{
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/MiSans-Bold.ttf")) {
        return;
    }
    float winW = static_cast<float>(window.getSize().x);
    float winH = static_cast<float>(window.getSize().y);

    sf::Text titleText(L"经典吃豆人", font, 70);
    titleText.setFillColor(sf::Color::Yellow);
    auto titleBounds = titleText.getLocalBounds();
    titleText.setPosition((winW - titleBounds.width) / 2, winH * 0.18f);
    window.draw(titleText);

    sf::Text highScoreText(L"最高分: " + std::to_wstring(highScore), font, 40);
    highScoreText.setFillColor(sf::Color::Green);
    auto hsBounds = highScoreText.getLocalBounds();
    highScoreText.setPosition((winW - hsBounds.width) / 2, winH * 0.38f);
    window.draw(highScoreText);

    sf::Text instructionText(L"按回车键开始 | 按ESC键退出", font, 30);
    instructionText.setFillColor(sf::Color::White);
    auto instBounds = instructionText.getLocalBounds();
    instructionText.setPosition((winW - instBounds.width) / 2, winH * 0.55f);
    window.draw(instructionText);
}
