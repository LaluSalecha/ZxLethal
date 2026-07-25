#include "Mesh.h"

Mesh::Mesh()
{
    vao = 0;
    vbo = 0;
}

void Mesh::CreateTriangle()
{
    float vertices[] =
    {
         0.0f,  0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f
    };

    glGenVertexArrays(1,&vao);
    glGenBuffers(1,&vbo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER,vbo);

    glBufferData(GL_ARRAY_BUFFER,
                 sizeof(vertices),
                 vertices,
                 GL_STATIC_DRAW);

    glVertexAttribPointer(
            0,
            3,
            GL_FLOAT,
            GL_FALSE,
            3*sizeof(float),
            (void*)0);

    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
}

void Mesh::Draw()
{
    glBindVertexArray(vao);

    glDrawArrays(GL_TRIANGLES,0,3);

    glBindVertexArray(0);
}

void Mesh::Destroy()
{
    if(vbo)
        glDeleteBuffers(1,&vbo);

    if(vao)
        glDeleteVertexArrays(1,&vao);
}
