#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

class Window
{
public:

    bool Create(const char* title,int width,int height);

    void Clear();

    void Present();

    void Destroy();

private:

    SDL_Window* window;
    SDL_GLContext context;
};

#endif
