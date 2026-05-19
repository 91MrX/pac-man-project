#pragma once
#include "GameState.h"
#include <vector>
#include <string>
#include "../map/MapManager.h"
#include "../entities/Pacman.h"
#include "../entities/Ghost.h"
#include "../ui/UIManager.h"
#include "../managers/ScoreManager.h"
#include "../managers/SoundManager.h"
#include "../items/Item.h"
#include "../map/Wall.h"

class PlayingState : public GameState {
public:
    PlayingState(const std::string& mapName="assets/maps/map1.txt");
    ~PlayingState();
    void handleInput(GameEngine& engine, sf::Event& event) override;
    void update(GameEngine& engine, float deltaTime) override;
    void render(sf::RenderWindow& window) override;

private:
    Pacman* m_pacman;
    std::vector<Ghost*> m_ghosts;
    std::vector<Item*> m_items;
    std::vector<Wall*> m_walls;
    std::string m_mapName;
    MapManager* m_map;
    UIManager* m_uiManager;
    ScoreManager* m_scoreManager;
    SoundManager* m_soundManager;
    Point revivePoint; 
};
