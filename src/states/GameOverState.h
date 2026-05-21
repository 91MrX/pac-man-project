#pragma once
#include "GameState.h"
//游戏结束状态类，显示游戏结果和最终分数，并提供返回菜单或退出游戏的选项
class GameOverState : public GameState {
public:
    GameOverState(bool won, int finalScore);
    void handleInput(GameEngine& engine, sf::Event& event) override;
    void update(GameEngine& engine, float deltaTime) override;
    void render(sf::RenderWindow& window) override;
private:
    bool m_won;
    int m_finalScore;
};
