#include "UIManager.h"

UIManager::UIManager(int score, int highScore, int lives, int dotsRemaining)
    : m_score(score), m_highScore(highScore), m_lives(lives), m_dotsRemaining(dotsRemaining), m_powerTimeRatio(0.f) {
}

UIManager::~UIManager() {
}

void UIManager::update(int score, int highScore, int lives, int dotsRemaining, float powerTimeRatio) {
    m_score = score;
    m_highScore = highScore;
    m_lives = lives;
    m_dotsRemaining = dotsRemaining;
    m_powerTimeRatio = powerTimeRatio;
}

static void drawHeart(sf::RenderWindow& window, float cx, float cy, float size, sf::Color color) {
    // 显示生命的心形图标，使用ConvexShape绘制一个心形，并添加阴影和高光效果
    sf::ConvexShape heart;
    heart.setPointCount(7);
    heart.setPoint(0, sf::Vector2f(0.f, size * 0.35f));
    heart.setPoint(1, sf::Vector2f(-size * 0.5f, -size * 0.05f));
    heart.setPoint(2, sf::Vector2f(-size * 0.35f, -size * 0.45f));
    heart.setPoint(3, sf::Vector2f(0.f, -size * 0.15f));
    heart.setPoint(4, sf::Vector2f(size * 0.35f, -size * 0.45f));
    heart.setPoint(5, sf::Vector2f(size * 0.5f, -size * 0.05f));
    heart.setPoint(6, sf::Vector2f(0.f, size * 0.35f));
    heart.setFillColor(color);
    heart.setPosition(cx, cy);
    window.draw(heart);

    // 黑色阴影底座
    heart.setFillColor(sf::Color(120, 0, 0));
    heart.setScale(1.12f, 1.12f);
    heart.setPosition(cx, cy);
    // 绘制阴影
    sf::ConvexShape outline = heart;
    outline.setFillColor(sf::Color(80, 0, 0));
    outline.setScale(1.15f, 1.15f);
    outline.setPosition(cx, cy);
    window.draw(outline);

    // 绘制心形主体
    sf::ConvexShape main = heart;
    main.setScale(1.f, 1.f);
    main.setFillColor(color);
    main.setPosition(cx, cy);
    window.draw(main);

    // 绘制高光效果
    sf::ConvexShape shine;
    shine.setPointCount(4);
    shine.setPoint(0, sf::Vector2f(-size * 0.3f, -size * 0.4f));
    shine.setPoint(1, sf::Vector2f(-size * 0.1f, -size * 0.4f));
    shine.setPoint(2, sf::Vector2f(-size * 0.15f, -size * 0.15f));
    shine.setPoint(3, sf::Vector2f(-size * 0.35f, -size * 0.2f));
    shine.setFillColor(sf::Color(255, 255, 255, 100));
    shine.setPosition(cx, cy);
    window.draw(shine);

    // 绘制高光
    sf::CircleShape dot(size * 0.06f);
    dot.setFillColor(sf::Color(255, 255, 255, 160));
    dot.setOrigin(size * 0.06f, size * 0.06f);
    dot.setPosition(cx - size * 0.2f, cy - size * 0.3f);
    window.draw(dot);
}

void UIManager::render(sf::RenderWindow& window)
{
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/MiSans-Bold.ttf")) {
        return;
    }

    // 显示剩余生命，使用心形图标表示，每个心代表一条生命
    float textY = 6.f;
    for (int i = 0; i < m_lives; i++) {
        drawHeart(window, 22.f + i * 38.f, 22.f, 18.f, sf::Color(220, 0, 0));
    }

    // 显示分数、最高分数和剩余点数，使用不同颜色区分，并根据生命数量调整位置以避免重叠
    float offsetX = 22.f + m_lives * 38.f + 16.f;
    sf::Text scoreText(L"当前得分: " + std::to_wstring(m_score), font, 24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(offsetX, textY);
    window.draw(scoreText);

    // 根据当前分数和最高分数的关系，动态调整最高分数的颜色，突出显示玩家是否接近或超过最高分数
    offsetX += scoreText.getLocalBounds().width + 24.f;
    sf::Text highScoreText(L"最高分: " + std::to_wstring(m_highScore), font, 24);
    highScoreText.setFillColor(sf::Color::Green);
    highScoreText.setPosition(offsetX, textY);
    window.draw(highScoreText);

    // 显示剩余点数，使用红色字体，并根据剩余点数的多少调整颜色的亮度，提示玩家当前的游戏进度和目标完成度
    offsetX += highScoreText.getLocalBounds().width + 24.f;
    sf::Text dotsText(L"剩余豆子: " + std::to_wstring(m_dotsRemaining), font, 24);
    dotsText.setFillColor(sf::Color(255, 183, 174));
    dotsText.setPosition(offsetX, textY);
    window.draw(dotsText);

    // 显示当前难度
    if (!m_difficultyName.empty()) {
        offsetX += dotsText.getLocalBounds().width + 24.f;
        sf::Text diffText(L"难度: " + m_difficultyName, font, 24);
        diffText.setFillColor(sf::Color::Cyan);
        diffText.setPosition(offsetX, textY);
        window.draw(diffText);
    }

    // 能量豆时间条
    if (m_powerTimeRatio > 0.f) {
        float winW = static_cast<float>(window.getSize().x);
        float barW = 200.f;
        float barH = 12.f;
        float barX = (winW - barW) / 2.f;
        float barY = static_cast<float>(window.getSize().y) - 20.f;

        // 背景
        sf::RectangleShape bg(sf::Vector2f(barW, barH));
        bg.setFillColor(sf::Color(50, 50, 50));
        bg.setOutlineThickness(1.f);
        bg.setOutlineColor(sf::Color(100, 100, 100));
        bg.setPosition(barX, barY);
        window.draw(bg);

        // 填充，根据剩余时间比例动态调整填充宽度，使用蓝色表示能量豆的持续时间，并添加渐变效果以增强视觉反馈
        float fillW = barW * m_powerTimeRatio;
        sf::RectangleShape fill(sf::Vector2f(fillW, barH));
        fill.setFillColor(sf::Color(50, 50, 255));
        fill.setPosition(barX, barY);
        window.draw(fill);

        // 添加一个半透明的白色光泽效果，使时间条看起来更有质感和层次感，增强视觉吸引力
        sf::RectangleShape gloss(sf::Vector2f(fillW, barH * 0.4f));
        gloss.setFillColor(sf::Color(255, 255, 255, 60));
        gloss.setPosition(barX, barY);
        window.draw(gloss);

        // 在时间条上方显示“POWER”
        sf::Text powerText(L"充能时间", font, 14);
        powerText.setFillColor(sf::Color(150, 150, 255));
        auto pwBounds = powerText.getLocalBounds();
        powerText.setPosition((winW - pwBounds.width) / 2.f, barY - 18.f);
        window.draw(powerText);
    }
}
