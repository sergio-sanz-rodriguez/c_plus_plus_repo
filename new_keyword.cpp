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

    // const String&: This specifies that the function returns a reference to a constant String object. 
    // This ensures that the returned reference cannot be modified and avoids copying the String object, which can be more efficient.
    // const: The const after the function indicates that this method doesn't modify the state of the object.
    const String& GetName() const { return m_Name; }


    
};

int main()
{
    int a = 2;
    int* b = new int[50]; // 200 byes (8 * 50)

    Entity* e1 = new Entity(); // allocates memory on the heap and calls the constructor. Kind of (Entity*)malloc(sizeof(Entity)) but it does not call the constructor.

    Entity* e2 = new Entity[50]; //allocates memory for 50 entities on the heap just continously in memory.

    delete[] b; // use square brackets if brackets are use for new operator
    delete e1;
    delete[] e2;
}