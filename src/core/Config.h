#pragma once

#include "Types.h"

// core
#include "GameEngine.h"
#include "GameObject.h"

// entities
#include "../entities/Character.h"
#include "../entities/Ghost.h"
#include "../entities/Blinky.h"
#include "../entities/Pinky.h"
#include "../entities/Inky.h"
#include "../entities/Clyde.h"
#include "../entities/Pacman.h"

// items
#include "../items/Item.h"
#include "../items/Dot.h"
#include "../items/PowerPellet.h"
#include "../items/Fruit.h"

// managers
#include "../managers/ScoreManager.h"
#include "../managers/SoundManager.h"

// map
#include "../map/MapManager.h"
#include "../map/Wall.h"

// ui
#include "../ui/UIManager.h"

namespace Config {//游戏配置常量
    constexpr int TILE_SIZE = 32;
    constexpr int MAP_WIDTH = 28;
    constexpr int MAP_HEIGHT = 31;
    const std::string HIGHSCORE_PATH = "save/highscore.txt";
}

enum class Difficulty {
    Easy,
    Normal,
    Hard
};

struct DifficultyConfig {
    float pacmanSpeed;
    float ghostSpeed;
    int initialLives;
    double frightenedDuration;
    const wchar_t* displayName;
};

inline DifficultyConfig getDifficultyConfig(Difficulty d) {
    switch (d) {
        case Difficulty::Easy:   return {8.0f, 1.5f, 5, 9.0, L"简单"};
        case Difficulty::Normal: return {8.0f, 2.0f, 3, 6.0, L"普通"};
        case Difficulty::Hard:   return {8.0f, 3.0f, 2, 4.0, L"困难"};
    }
    return {8.0f, 2.0f, 3, 6.0, L"普通"};
}

// states
#include "../states/GameState.h"
#include "../states/MenuState.h"
#include "../states/PlayingState.h"
#include "../states/PausedState.h"
#include "../states/GameOverState.h"
