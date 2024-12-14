#include <iostream>

class Entity
{
public:
    float X, Y;

    Entity()
    {
        X = 0.0f;
        Y = 0.0f;
        std::cout << "Created Entity!" << std::endl;
    }

    Entity(float& x, float &y)
    {
        X = x;
        Y = y;
    }

    ~Entity()
    {
        std::cout << "Destroyed Entity!" << std::endl;

    }

    void Print()
    {
        std::cout << X << ", " << Y << std::endl;
    }
};

void Function()
{
    float a = 2;
    float b = 3;
    //Entity e(a, b);
    Entity* e = new Entity();
    e->Print();
    delete e;
}

int main()
{
    Function();

    return 0;

}