#include <iostream>
#include <GL/glew.h>
#include "Display.h"
#include "Shader.h"
#include "Mesh.h"

int main(int argc, char** argv)
{
    Display display(800, 600, std::string("Hello World"));

    Shader shader("./res/basicShader");

    Vertex vertices[] = {
        Vertex(glm::vec3(-0.5, -0.5, 0.0)),
        Vertex(glm::vec3( 0.0, 0.5, 0.0)),
        Vertex(glm::vec3( 0.5, -0.5, 0.0))
    };

    Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

    while (!display.isClosed())
    {
        display.clear(0.0f, 0.15f, 0.3f, 1.0f);
        
        shader.bind();
        mesh.draw();

        display.swapBuffers();
    }
    
    return 0;
}