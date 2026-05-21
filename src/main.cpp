#include "core/Config.h"
#include "states/MenuState.h"
//主函数，创建游戏引擎实例，设置初始状态为菜单，并启动游戏循环
int main() {
    GameEngine engine;
    engine.pushState(new MenuState());
    engine.run();
    return 0;
}
