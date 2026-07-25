#include "Input.h"

#include <SDL2/SDL.h>

bool Input::Update()
{
    SDL_Event event;

    while(SDL_PollEvent(&event))
    {
        if(event.type==SDL_QUIT)
            return false;

        if(event.type==SDL_KEYDOWN)
        {
            if(event.key.keysym.sym==SDLK_ESCAPE)
                return false;
        }
    }

    return true;
}
