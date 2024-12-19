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
void Print();

int main()
{
    Entity e;
    //e.x = 2; 
    //e.y = 3;
    Entity::x = 2; //correctly
    Entity::y = 3; //correctly
    
    Entity e1;
    //e1.x = 5;
    //e1.y = 8;
    Entity::x = 5; //correctly
    Entity::y = 8; //correctly

    //e.Print();
    //e1.Print();
    Entity::Print();
    Entity::Print();

    return 0;

}