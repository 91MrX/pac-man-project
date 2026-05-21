#pragma once
#include "GameState.h"
//暂停状态类，显示暂停菜单，并提供继续游戏或返回菜单的选项
class PausedState : public GameState {
public:
    void handleInput(GameEngine& engine, sf::Event& event) override;
    void update(GameEngine& engine, float deltaTime) override;
    void render(sf::RenderWindow& window) override;
};