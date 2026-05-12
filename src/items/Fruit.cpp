#include"Fruit.h"
ItemType Fruit::onCollect() {
    return ItemType::Fruit;
}
int Fruit::getScore() const {
    return m_score;
}
Fruit::Fruit(int x, int y) {
    m_position = Point(x, y);
}