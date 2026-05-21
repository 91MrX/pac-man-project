#include "GameObject.h"
//核心游戏对象类，所有游戏实体和物品都继承自这个类，提供基本的属性和方法
bool GameObject::isActive() const {
    return m_active;
}

void GameObject::setActive(bool active) {
    m_active = active;
}
