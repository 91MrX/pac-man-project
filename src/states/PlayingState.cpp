#include "PlayingState.h"
#include "../map/MapManager.h"
#include "../entities/Pacman.h"
#include "../entities/Ghost.h"
#include "../ui/UIManager.h"
#include "../managers/ScoreManager.h"

using namespace std;
PlayingState::PlayingState() {
    m_map = new MapManager();
    m_pacman = new Pacman(m_map->getPacmanStartPos());
    m_uiManager = new UIManager();
    m_scoreManager = new ScoreManager();
    for(int i=0; i < 4; i++) {
        m_ghosts.push_back(new Ghost(m_map->getGhostStartPos(i)));
    }
}