#ifndef ENGINE_H
#define ENGINE_H

#include "Core/Window.h"
#include "Core/Input.h"
#include "Core/Time.h"
#include "Graphics/Renderer.h"
#include "Game/Game.h"

class Engine
{
public:

    Engine();

    bool Init();

    void Run();

    void Shutdown();

private:

    Window window;
    Input input;
    Time time;
    Renderer renderer;
    Game game;

    bool running;
};

#endif
