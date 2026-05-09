cmake_minimum_required(VERSION 3.16)
project(pac-man-project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# SFML 路径 — 可通过 -DSFML_ROOT=... 覆盖
set(SFML_ROOT "C:/Users/MrX/Downloads/SFML-2.6.1-windows-gcc-13.1.0-mingw-64-bit/SFML-2.6.1"
    CACHE PATH "SFML 安装目录")

set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML 2.6 COMPONENTS system window graphics audio REQUIRED
    PATHS ${SFML_ROOT}
    NO_DEFAULT_PATH)

# 自动收集所有源文件
file(GLOB_RECURSE SOURCES src/*.cpp src/*.h)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
    ${SFML_INCLUDE_DIR}
    src)

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
