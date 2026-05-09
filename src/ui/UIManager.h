#pragma once
#include <SFML/Graphics.hpp>

class UIManager {
public:
    void render(sf::RenderWindow& window, int score, int highScore, int lives);
private:
    sf::Font m_font;
    sf::Text m_scoreText;
    sf::Text m_livesText;
};