#pragma once
#include "GameState.h"
#include "../core/Config.h"
#include <string>
//菜单状态类，显示游戏标题、最高分数，并提供难度选择和开始游戏的选项
class MenuState : public GameState
{
public:
    MenuState(int highScore=0);
    void handleInput(GameEngine& engine, sf::Event& event) override;
    void update(GameEngine& engine, float deltaTime) override;
    void render(sf::RenderWindow& window) override;
    std::string selectMap();
    private:
    int highScore;
    Difficulty m_selectedDifficulty = Difficulty::Normal;
};