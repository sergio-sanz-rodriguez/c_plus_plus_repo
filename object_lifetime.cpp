#include <iostream>
#include <string>

class Entity
{

public:
    Entity()
    {
        std::cout << "Created Entity!" << std::endl;
    }

    ~Entity()
    {
        std::cout << "Destroyed Entity!" << std::endl;
    }

};

int* CreateArray()
{
    // This will fail as the pointer is created on the stack. The function returns a pointer to that stack memory that gets clear as sson as we go out of the scope
    int array[50];
    return array;
}

class ScopedPtr
{
private:
    Entity* m_Ptr;
public:
    ScopedPtr(Entity* ptr)
        : m_Ptr(ptr)
    {
    }

    ~ScopedPtr()
    {
        delete m_Ptr;
    }
};

int main() {

    // Create on the stack
    {
        Entity e;
    }
    // Create the object on the heap, the pointer gets destroyed outside the scope.
    {
        Entity *e = new Entity();
    }
    //std::cout << e << std::endl

    // Object gets destroyed when we go out of the scope, as the object is created on the heap
    {
        ScopedPtr e = new Entity();
    }

    std::cout << "entro!" << std::endl;

}