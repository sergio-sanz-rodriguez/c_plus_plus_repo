#include <string>
#include <iostream>

using String = std::string;

class Entity
{
    private:
    String m_Name;
    public:
    Entity() : m_Name("Unknown") {}
    Entity(const String& name) : m_Name(name) {}

    const String& GetName() const { return m_Name; }
};

void Function()
{
    int a = 2;
    Entity entity = Entity("Cherno");
}

int main()
{
    //On the stack
    //If you can create an object like di, do an object like this, it is the fastest way.
    //Entity entity("Sergio");
    Entity entity = Entity("Sergio");
    std::cout << entity.GetName() << std::endl;

    //But there are reasons why you cannot create an object on the stack
    //On the heap
    Entity* e;
    {
        Entity* entity = new Entity("Cherno");
        e = entity;
        std::cout << entity->GetName() << std::endl;
        //Free the memory
        
    }

    delete e;

    return 0;
}