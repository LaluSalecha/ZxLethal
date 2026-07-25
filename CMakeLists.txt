cmake_minimum_required(VERSION 3.10)

project(ZxLethal)


set(CMAKE_CXX_STANDARD 17)


include_directories(
    .
    Core
    Graphics
    Math
    Game
)


add_executable(
    ZxLethal

    main.cpp

    Engine.cpp

    Core/Window.cpp
    Core/Input.cpp
    Core/Time.cpp

    Graphics/Shader.cpp
    Graphics/Mesh.cpp
    Graphics/Renderer.cpp

    Game/Game.cpp
)


target_link_libraries(
    ZxLethal

    SDL2
    GLESv2
    log
)
