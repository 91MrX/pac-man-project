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

static const wchar_t* DIFFICULTY_NAMES[] = { L"简单", L"普通", L"困难" };
static const int DIFFICULTY_COUNT = 3;

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
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Left) {
            int d = static_cast<int>(m_selectedDifficulty);
            d = (d + DIFFICULTY_COUNT - 1) % DIFFICULTY_COUNT;
            m_selectedDifficulty = static_cast<Difficulty>(d);
            return;
        }
        if (event.key.code == sf::Keyboard::Right) {
            int d = static_cast<int>(m_selectedDifficulty);
            d = (d + 1) % DIFFICULTY_COUNT;
            m_selectedDifficulty = static_cast<Difficulty>(d);
            return;
        }
        if (event.key.code == sf::Keyboard::Enter) {
            engine.changeState(new PlayingState(selectMap(), m_selectedDifficulty));
        }
        if (event.key.code == sf::Keyboard::Escape) {
            engine.quit();
        }
    }
    if ((event.type == sf::Event::Closed))
    {
        engine.quit();
    }
    // 手柄: D-pad 左右选择难度
    if (event.type == sf::Event::JoystickMoved) {
        if (event.joystickMove.axis == sf::Joystick::PovX) {
            if (event.joystickMove.position > 50.f) {
                int d = static_cast<int>(m_selectedDifficulty);
                d = (d + 1) % DIFFICULTY_COUNT;
                m_selectedDifficulty = static_cast<Difficulty>(d);
            } else if (event.joystickMove.position < -50.f) {
                int d = static_cast<int>(m_selectedDifficulty);
                d = (d + DIFFICULTY_COUNT - 1) % DIFFICULTY_COUNT;
                m_selectedDifficulty = static_cast<Difficulty>(d);
            }
        }
    }
    // 手柄: A键(0)或Start键(7)开始，B键(1)退出
    if (event.type == sf::Event::JoystickButtonPressed) {
        if (event.joystickButton.button == 0 || event.joystickButton.button == 7) {
            engine.changeState(new PlayingState(selectMap(), m_selectedDifficulty));
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

    // 标题
    sf::Text titleText(L"经典吃豆人", font, 70);
    titleText.setFillColor(sf::Color::Yellow);
    auto titleBounds = titleText.getLocalBounds();
    titleText.setPosition((winW - titleBounds.width) / 2, winH * 0.12f);
    window.draw(titleText);

    // 最高分
    sf::Text highScoreText(L"最高分: " + std::to_wstring(highScore), font, 40);
    highScoreText.setFillColor(sf::Color::Green);
    auto hsBounds = highScoreText.getLocalBounds();
    highScoreText.setPosition((winW - hsBounds.width) / 2, winH * 0.28f);
    window.draw(highScoreText);

    // 难度选择器
    int diffIdx = static_cast<int>(m_selectedDifficulty);
    std::wstring diffStr = L"难度:  <  " + std::wstring(DIFFICULTY_NAMES[diffIdx]) + L"  >";
    sf::Text diffText(diffStr, font, 38);
    diffText.setFillColor(sf::Color::Cyan);
    auto diffBounds = diffText.getLocalBounds();
    diffText.setPosition((winW - diffBounds.width) / 2, winH * 0.42f);
    window.draw(diffText);

    // 难度选择提示
    sf::Text diffHint(L"按 ← → 或方向键选择难度", font, 22);
    diffHint.setFillColor(sf::Color(160, 160, 160));
    auto hintBounds = diffHint.getLocalBounds();
    diffHint.setPosition((winW - hintBounds.width) / 2, winH * 0.50f);
    window.draw(diffHint);

    // 操作说明
    sf::Text instructionText(L"按回车键开始 | 按ESC键退出", font, 30);
    instructionText.setFillColor(sf::Color::White);
    auto instBounds = instructionText.getLocalBounds();
    instructionText.setPosition((winW - instBounds.width) / 2, winH * 0.60f);
    window.draw(instructionText);
}
