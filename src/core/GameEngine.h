#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class GameState;//向前声明
//核心游戏引擎类，负责管理游戏状态、窗口和主循环，以及处理事件、更新和渲染
class GameEngine {
public:
    GameEngine();
    ~GameEngine();
    void run();

    void pushState(GameState* state);
    void popState();
    void changeState(GameState* state);
    void restartGame(GameState* state);
    void quit();

private:
    void processEvents();
    void update(float deltaTime);
    void render();
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::RenderWindow m_window;
    sf::Clock m_clock;
    std::vector<GameState*> m_states;
};
