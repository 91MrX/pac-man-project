#include "GameObject.h"

bool GameObject::isActive() const {
    return m_active;
}

void GameObject::setActive(bool active) {
    m_active = active;
}
