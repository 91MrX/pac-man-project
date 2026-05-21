#pragma once
#include <SFML/Graphics.hpp>
//核心游戏状态类，所有游戏状态（如菜单、游戏中、暂停、游戏结束）都继承自这个类，定义了处理输入、更新和渲染的接口
class GameEngine;

class GameState {
public:
    virtual ~GameState() = default;
    virtual void handleInput(GameEngine& engine, sf::Event& event) = 0;
    virtual void update(GameEngine& engine, float deltaTime)=0;
    virtual void render(sf::RenderWindow& window) = 0;
};
