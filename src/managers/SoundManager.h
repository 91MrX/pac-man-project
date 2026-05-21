#pragma once
#include <SFML/Audio.hpp>
#include <string>
//声音管理类，负责加载和播放游戏中的各种声音效果和背景音乐
class SoundManager {
public:
    SoundManager();
    ~SoundManager() = default;
    
    void playBackgroundMusic();
    void stopBackgroundMusic();
    void playEatDot();
    void playEatPowerPellet();
    void playEatGhost();
    void playDeath();
    void playHurt();
    void playGameOver();
    void playVictory();
    void setMusicVolume(float volume);
    void setSoundVolume(float volume);
    bool isBackgroundMusicPlaying() const;

private:
    sf::Music m_backgroundMusic;
    sf::SoundBuffer m_eatDotBuffer;
    sf::SoundBuffer m_eatPowerPelletBuffer;
    sf::SoundBuffer m_eatGhostBuffer;
    sf::SoundBuffer m_deathBuffer;
    sf::SoundBuffer m_hurtBuffer;
    sf::SoundBuffer m_gameOverBuffer;
    sf::SoundBuffer m_victoryBuffer;
    sf::Sound m_eatDotSound;
    sf::Sound m_eatPowerPelletSound;
    sf::Sound m_eatGhostSound;
    sf::Sound m_deathSound;
    sf::Sound m_hurtSound;
    sf::Sound m_gameOverSound;
    sf::Sound m_victorySound;
    bool m_musicLoaded = false;
};
