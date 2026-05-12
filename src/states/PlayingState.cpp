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
    m_ghosts.push_back(new Blinky(m_map->getBlinkyStartPos()));
    m_ghosts.push_back(new Pinky(m_map->getPinkyStartPos()));
    m_ghosts.push_back(new Inky(m_map->getInkyStartPos()));
    m_ghosts.push_back(new Clyde(m_map->getClydeStartPos()));
    for(int i = 0; i < m_map->getWidth(); i++) {
        for(int j = 0; j < m_map->getHeight(); j++) {
            char tile = m_map->getWord(i, j);
            if (tile == '.') {
                m_items.push_back(new Dot(i, j));
            } else if (tile == 'O') {
                m_items.push_back(new PowerPellet(i, j));
            } else if (tile == '#') {
                m_walls.push_back(new Wall(i, j));
            } else if (tile == 'F') {
                m_items.push_back(new Fruit(i, j));
            }
        }
    }
}