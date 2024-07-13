#include <iostream>

class Entity
{
    public:
    float X, Y;

    Entity()
    {
        X = 0.0f;
        Y = 0.0f;
    }

    ~Entity()
    {

    }

    void Move(float xa, float ya)
    {
        X += xa;
        Y += ya;
        std::cout << X << ", " << Y << std::endl;
    }

};

class Player : public Entity
{
    public:
    
    const char* Name;

    Player()
    {
        Name = "Player 1";
    }

    ~Player()
    {
        
    }

    void PrintName()
    {
        std::cout << Name << std::endl;
    }
    

};

int main()
{
    Player player;
    player.PrintName();
    player.Move(5, 5);

    return 0;
}