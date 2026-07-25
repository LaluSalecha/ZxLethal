#ifndef MESH_H
#define MESH_H

#include <GLES3/gl3.h>

class Mesh
{
public:
    Mesh();

    void CreateTriangle();

    void Draw();

    void Destroy();

private:
    GLuint vao;
    GLuint vbo;
};

#endif
