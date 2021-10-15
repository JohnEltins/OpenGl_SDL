#include <iostream>
#include <ECS/ECS.h>

int main(int argc, char** argv)
{
    ECS::EntityManager mgr;

    ECS::Entity canvas(mgr.addNewEntity(), &mgr);
    canvas.addComponent<Canvas>(800, 600, std::string("Hello World"));

    Vertex vertices[] = {
        Vertex(glm::vec3(-0.3, -0.3, 0.0), glm::vec2(0.0, 0.0)),
        Vertex(glm::vec3(0.0, 0.3, 0.0),  glm::vec2(0.5, 1.0)),
        Vertex(glm::vec3(0.3, -0.3, 0.0), glm::vec2(1.0, 0.0))
    };

    Vertex vertices2[] = {
        Vertex(glm::vec3(0.3, 0.3, 0.0), glm::vec2(0.0, 0.0)),
        Vertex(glm::vec3(0.0, -0.3, 0.0),  glm::vec2(0.5, 1.0)),
        Vertex(glm::vec3(-0.3, 0.3, 0.0), glm::vec2(1.0, 0.0))
    };

    ECS::Entity tri(mgr.addNewEntity(), &mgr);
    tri.addComponent<Mesh>(vertices, sizeof(vertices) / sizeof(vertices[0]));
    tri.addComponent<Shader>("./res/basicShader2");
    tri.addComponent<Texture>("./res/bricks.jpg");

    ECS::Entity tri2(mgr.addNewEntity(), &mgr);
    tri2.addComponent<Mesh>(vertices2, sizeof(vertices2) / sizeof(vertices2[0]));
    tri2.addComponent<Shader>("./res/basicShader");
    tri2.addComponent<Transform>();


    mgr.registerSystem<Renderer>(&mgr);
    mgr.registerSystem<ShaderHandler>(&mgr);
    mgr.registerSystem<TextureHandler>(&mgr);
    mgr.registerSystem<TransformHandler>(&mgr);
    mgr.registerSystem<Draw>(&mgr);

    mgr.init();

    mgr.render(canvas.getID());
    return 0;
}