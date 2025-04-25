#include <iostream>
#include <string>

class Entity
{
public:
    void Print() const { std::cout << "Hello!" << std::endl; }
};

// I automate the deletion of the pointer object, which is simlar to Entity* but I would have to delete the pointer afterwards.
class ScopedPtr
{
private:
    Entity* m_Ptr;
public:
    ScopedPtr(Entity* ptr)
        : m_Ptr(ptr) {}
    ~ScopedPtr()
    {
        delete m_Ptr;
    }

    Entity* operator->()
    {
        return m_Ptr;
    }

    const Entity* operator->() const
    {
        return m_Ptr;
    }
};

struct Vector3
{
    float x, y, z;
};

int main()
{
    Entity e;
    e.Print();

    Entity* ptr = &e;
    ptr->Print();

    // ScopedPtr deletes the points when I go out of the scope
    const ScopedPtr entity = new Entity();
    entity->Print();

    uintptr_t offsetx = (uintptr_t)&((Vector3*)nullptr)->x;
    uintptr_t offsety = (uintptr_t)&((Vector3*)nullptr)->y;
    uintptr_t offsetz = (uintptr_t)&((Vector3*)nullptr)->z;

    std::cout << offsetx << ", " << offsety << ", " << offsetz << std::endl;

}
