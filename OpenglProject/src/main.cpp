#include <iostream>
#include <GL/glew.h>
#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "Transform.h"

int main(int argc, char** argv)
{
    Display display(800, 600, std::string("Hello World"));

    Shader shader("./res/basicShader");
    Texture texture("./res/bricks.jpg");

    Vertex vertices[] = {
        Vertex(glm::vec3(-0.5, -0.5, 0.0), glm::vec2(0.0, 0.0)),
        Vertex(glm::vec3( 0.0, 0.5, 0.0),  glm::vec2(0.5, 1.0)),
        Vertex(glm::vec3( 0.5, -0.5, 0.0), glm::vec2(1.0, 0.0))
    };

    Transform transform;

    Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

    float counter = 0.0f;

    while (!display.isClosed())
    {
        display.clear(0.0f, 0.15f, 0.3f, 1.0f);

        float cosc = cosf(counter);
        float senc = sinf(counter);


        transform.setScale(glm::vec3(cosc, cosc, cosc));

        transform.getPos().x = cosc/2;
        transform.getPos().y = cosc/2;

       transform.getRot().z = counter;

        shader.bind();
        texture.bind(0);
        shader.updateUniforms(transform);

        mesh.draw();

        display.swapBuffers();
        counter += 0.04f;
    }
    
    return 0;
}