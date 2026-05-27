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
#include "../core/Config.h"
//游戏中状态类，负责处理游戏逻辑、更新游戏对象状态，并渲染游戏场景
class PlayingState : public GameState {
public:
    PlayingState(const std::string& mapName="assets/maps/map1.txt", Difficulty difficulty = Difficulty::Normal);
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
    Difficulty m_difficulty;
};
