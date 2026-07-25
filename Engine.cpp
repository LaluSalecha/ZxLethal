#include "Engine.h"

Engine::Engine()
{
    running = false;
}

bool Engine::Init()
{
    if(!window.Create("ZxLethal",1280,720))
        return false;

    if(!renderer.Init())
        return false;

    if(!game.Init())
        return false;

    running = true;

    return true;
}

void Engine::Run()
{
    while(running)
    {
        running = input.Update();

        time.Update();

        game.Update();

        window.Clear();

        renderer.Render();

        game.Render();

        window.Present();
    }
}

void Engine::Shutdown()
{
    game.Shutdown();

    renderer.Shutdown();

    window.Destroy();
}
