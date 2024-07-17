#include <iostream>
#include <string>

class Example
{
    public:
    Example()
    {
        std::cout << "Created Entity" << std::endl;
    }
    Example(int x)
    {
        std::cout << "Created Entity with " << x << "!" << std::endl;
    }

};

class Entity
{
    private:
    std::string m_Name;
    int m_Score;
    Example m_Example;
        
    public:
    // You should be listing all the member variables in order
    Entity()
        : m_Name("Unknown"), m_Score(0)
    {
        // initializing like this, m_Name would be initialized twice, one with the default constrator and one with the "Unknown" variable: waste of performance.
        //m_Name = "Unknown"

        // this would call two constructors the default one and the one taking "int x". This is like declaring Example m_Example before m_Example = Example(8)
        m_Example = Example(8);
    }

    Entity(const std::string& name)
        : m_Name(name)
    {
    }

    const std::string& GetName() const { return m_Name; }
};

int main()
{
    Entity e0;
    std::cout << e0.GetName() << std::endl;

    Entity e1("Sergio");
    std::cout << e1.GetName() << std::endl;
}