#include "Window.h"

#include <GLES3/gl3.h>

bool Window::Create(const char* title,int width,int height)
{
    if(SDL_Init(SDL_INIT_VIDEO)!=0)
        return false;

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                        SDL_GL_CONTEXT_PROFILE_ES);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,0);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);

    window = SDL_CreateWindow(
            title,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            width,
            height,
            SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    if(!window)
        return false;

    context = SDL_GL_CreateContext(window);

    if(!context)
        return false;

    glViewport(0,0,width,height);

    return true;
}

void Window::Clear()
{
    glClearColor(0.1f,0.1f,0.15f,1.0f);

    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::Present()
{
    SDL_GL_SwapWindow(window);
}

void Window::Destroy()
{
    SDL_GL_DeleteContext(context);

    SDL_DestroyWindow(window);

    SDL_Quit();
}
