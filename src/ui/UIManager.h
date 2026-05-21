#pragma once
#include <SFML/Graphics.hpp>
//UI管理类，负责显示游戏中的分数、剩余生命、剩余点数等信息，并提供更新和渲染方法

class UIManager {
public:
    UIManager(int score = 0, int highScore = 0, int lives = 3, int dotsRemaining = 0);
    ~UIManager();
    void update(int score, int highScore, int lives, int dotsRemaining, float powerTimeRatio = 0.f);
    void render(sf::RenderWindow& window);
private:
    int m_score;
    int m_highScore;
    int m_lives;
    int m_dotsRemaining;
    float m_powerTimeRatio;
};
