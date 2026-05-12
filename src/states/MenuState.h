#pragma once
#include "GameState.h"
class MenuState : public GameState 
{
public:
    MenuState(int highScore=0);
    void handleInput(GameEngine& engine, sf::Event& event) override;
    void update(GameEngine& engine, float deltaTime) override;
    void render(sf::RenderWindow& window) override;
    private:
    int highScore;
};