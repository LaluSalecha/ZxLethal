#include "Renderer.h"

bool Renderer::Init()
{
    shader.Create();

    mesh.CreateTriangle();

    return true;
}

void Renderer::Render()
{
    shader.Use();

    mesh.Draw();
}

void Renderer::Shutdown()
{
    mesh.Destroy();

    shader.Destroy();
}
