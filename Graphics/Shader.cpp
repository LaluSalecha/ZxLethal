#include "Shader.h"

static const char* vertexSource =
R"(#version 300 es

layout(location=0) in vec3 aPos;

void main()
{
    gl_Position = vec4(aPos,1.0);
}
)";

static const char* fragmentSource =
R"(#version 300 es

precision mediump float;

out vec4 FragColor;

void main()
{
    FragColor = vec4(0.2,0.8,1.0,1.0);
}
)";

Shader::Shader()
{
    program = 0;
}

bool Shader::Create()
{
    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs,1,&vertexSource,nullptr);
    glCompileShader(vs);

    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs,1,&fragmentSource,nullptr);
    glCompileShader(fs);

    program = glCreateProgram();

    glAttachShader(program,vs);
    glAttachShader(program,fs);

    glLinkProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return true;
}

void Shader::Use()
{
    glUseProgram(program);
}

void Shader::Destroy()
{
    if(program)
        glDeleteProgram(program);
}
