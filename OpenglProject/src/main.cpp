#include <iostream>
#include <ECS/ECS.h>

struct Label : public ECS::Component
{
    Label() 
    {
        word = "Movivel";
    }

    std::string word;
};

struct Potition : public ECS::Component
{
    Potition(int a, int b) : A(a), B(b) {}

    int A;
    int B;
};

struct Name : public ECS::Component
{
    Name(const std::string nome) : nome(nome) {}

    std::string nome;
};

struct system1 : public ECS::System
{
    system1()
    {
        addComponentSignature<Name>();
        addComponentSignature<Label>();
        addComponentSignature<Potition>();
    }
};

struct system2 : public ECS::System
{
    system2()
    {
        addComponentSignature<Label>();
        addComponentSignature<Potition>();
    }
};

struct system3 : public ECS::System
{
    system3()
    {
        addComponentSignature<Name>();
    }
};

int main(int argc, char** argv)
{
    ECS::EntityManager mgr;

    mgr.registerSystem<system1>();
    mgr.registerSystem<system2>();
    mgr.registerSystem<system3>();

    auto entity = mgr.addNewEntity();
    mgr.addComponent<Label>(entity);
    mgr.addComponent<Potition>(entity,1, 8);
  

    ECS::Entity entity2(mgr.addNewEntity(), &mgr);
    entity2.addComponent<Label>();
    entity2.addComponent<Potition>(13, 17);
    entity2.addComponent<Name>("nominho top");

    mgr.update();


    return 0;
}