#ifndef RENDERER_H
#define RENDERER_H

#include "Shader.h"
#include "Mesh.h"

class Renderer
{
public:

    bool Init();

    void Render();

    void Shutdown();

private:

    Shader shader;

    Mesh mesh;
};

#endif
