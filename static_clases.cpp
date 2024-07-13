#include <iostream>

struct Entity
{
    static int x, y;

    //A static method can only have access to static variables
    static void Print()
    {
        std::cout << x << ", " << y << std::endl;
    }
};

int Entity::x;
int Entity::y;
//void Print();

int main()
{
    Entity e;
    e.x = 2;
    e.y = 3;
    
    Entity e1;
    e1.x = 5;
    e1.y = 8;
    //Entity::x = 5;
    //En tity::y = 8;

    e.Print();
    e1.Print();
    //Entity::print();
    //Entity::print();

    return 0;

}