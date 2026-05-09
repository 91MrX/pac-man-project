cmake_minimum_required(VERSION 3.16)
project(pac-man-project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_ROOT "C:/Users/MrX/Downloads/SFML-2.6.1-windows-gcc-13.1.0-mingw-64-bit/SFML-2.6.1")

set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML 2.6 COMPONENTS system window graphics audio network REQUIRED)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/entities/Ghost.cpp
        src/core/GameObject.h
        src/core/GameObject.cpp
        src/entities/Character.h
        src/entities/Character.cpp
        src/ui/UIManager.h
        src/ui/UIManager.cpp
        src/states/PlayingState.h
        src/states/PlayingState.cpp
        src/states/PausedState.cpp
        src/states/PausedState.h
        src/states/MenuState.h
        src/states/MenuState.cpp
        src/states/GameState.h
        src/states/GameState.cpp
        src/states/GameOverState.h
        src/states/GameOverState.cpp
        src/map/Wall.h
        src/map/Wall.cpp
        src/map/MapManager.h
        src/map/MapManager.cpp
        src/managers/SoundManager.cpp
        src/managers/SoundManager.h
        src/managers/ScoreManager.h
        src/managers/ScoreManager.cpp
        src/items/PowerPellet.h
        src/items/PowerPellet.cpp
        src/items/Item.h
        src/items/Item.cpp
        src/items/Fruit.h
        src/items/Fruit.cpp
        src/items/Dot.h
        src/items/Dot.cpp
        src/entities/Pinky.h
        src/entities/Pinky.cpp
        src/entities/Pacman.h
        src/entities/Pacman.cpp
        src/entities/Inky.h
        src/entities/Inky.cpp
        src/entities/Ghost.h
        src/entities/Ghost.cpp
        src/entities/Clyde.h
        src/entities/Clyde.cpp
        src/entities/Character.h
        src/entities/Character.cpp
        src/entities/Blinky.h
        src/entities/Blinky.cpp
        src/core/InputHandler.h
        src/core/InputHandler.cpp
        src/core/GameObject.h
        src/core/GameObject.cpp
        src/core/GameEngine.h
        src/core/GameEngine.cpp
        src/core/Config.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE
        sfml-system
        sfml-window
        sfml-graphics
        sfml-audio
        sfml-network
        opengl32
        winmm
        gdi32
)

target_include_directories(${PROJECT_NAME} PRIVATE ${SFML_INCLUDE_DIR})