#include <string>
#include <iostream>


class Entity
{
private:
    std::string m_Name;
    int m_Age;
public:
    Entity(const std::string& name) : m_Name(name), m_Age(-1) {}
    Entity(int age) : m_Name("Unknown"), m_Age(age) {}
};

class Entity2
{
private:
    std::string m_Name;
    int m_Age;
public:
    explicit Entity2(const std::string& name) : m_Name(name), m_Age(-1) {}
    explicit Entity2(int age) : m_Name("Unknown"), m_Age(age) {} // if you want the constructors to be explicitly called
};

//void PrintEntity(int age)
//{
    // Printing
//}

void PrintEntity(const Entity& entity)
{
    // Printing
}

void PrintEntity2(int age)
{
    // Printing
}

void PrintEntity2(const Entity2& entity2)
{
    // Printing
}

int main()
{
    PrintEntity(22); //22 can be converted into an Entity object because a constructor was declared.
    //PrintEntity("Sergio"); // does not work because "Sergio" is not an std::string but a char array
    PrintEntity(std::string("Sergio"));
    PrintEntity(Entity("Sergio"));

    PrintEntity2(22); //it should fail, it must be PrintEntity2(Entity2(22))

}