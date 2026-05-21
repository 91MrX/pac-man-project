# Pac-Man Game

C++ 课程设计项目 —— 使用 SFML 2.6.1 实现的经典吃豆人游戏。

## 功能特性

- **经典玩法** — 吃豆子、能量豆、水果，躲避幽灵
- **4 个幽灵 AI** — Blinky(红)、Pinky(粉)、Inky(青)、Clyde(橙)，各有独立追击逻辑
- **幽灵状态机** — 追逐/散开/恐慌/被吃 完整循环
- **多张地图** — 3 张地图随机选择
- **音效系统** — 背景音乐 + 吃豆/能量豆/幽灵/受伤/胜利/失败音效
- **UI 界面** — 分数、最高分、生命值(红心)、剩余豆子、能量豆计时条
- **最高分持久化** — 自动保存到 highscore.txt
- **手柄支持** — Xbox 手柄，摇杆/D-pad 移动，Start 暂停，A/B 确认/返回

## 操作说明

| 操作 | 键盘 | 手柄 |
|------|------|------|
| 移动 | WASD / 方向键 | 左摇杆 / D-pad |
| 暂停 | P / Escape | Start |
| 确认 | Enter | A |
| 返回/退出 | Escape | B |

## 编译环境

- **编译器** — MSYS2 UCRT64 (g++)
- **库** — SFML 2.6.1
- **构建工具** — CMake 3.15+ / Ninja

## 编译步骤

```bash
# 1. 安装 MSYS2 和 UCRT64 工具链
# 2. 下载 SFML 2.6.1 (MinGW 64-bit)
# 3. 在项目根目录执行：

mkdir build && cd build
cmake .. -G Ninja -DSFML_ROOT="你的SFML路径"
cmake --build .

# 4. 将 SFML 的 bin/*.dll 复制到 build/ 目录
# 5. 将 assets/ 目录复制到 build/ 目录
# 6. 运行 PacmanGame.exe
```

## 项目结构

```
├── assets/
│   ├── fonts/          # 字体文件
│   ├── maps/           # 地图文件 (map1-3.txt)
│   ├── sounds/         # 音效文件
│   └── textures/       # 背景图片
├── src/
│   ├── core/           # 游戏引擎、配置、类型定义
│   ├── entities/       # Pacman、Ghost 及其子类
│   ├── items/          # Dot、PowerPellet、Fruit
│   ├── managers/       # SoundManager、ScoreManager
│   ├── map/            # MapManager、Wall
│   ├── states/         # MenuState、PlayingState、PausedState、GameOverState
│   └── ui/             # UIManager
└── CMakeLists.txt
```

## 地图格式

28x31 的文本文件，每个字符代表一个格子：

| 字符 | 含义 |
|------|------|
| `#` | 墙壁 |
| `.` | 豆子 |
| `O` | 能量豆 |
| `F` | 水果 |
| `M` | Pacman 出生点 |
| `B/P/I/C` | 四个幽灵出生点 |
| `E` | 幽灵门 |
| `S` | 空地 |
