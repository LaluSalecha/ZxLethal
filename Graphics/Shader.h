#ifndef SHADER_H
#define SHADER_H

#include <GLES3/gl3.h>

class Shader
{
public:
    Shader();

    bool Create();

    void Use();

    void Destroy();

private:
    GLuint program;
};

#endif
