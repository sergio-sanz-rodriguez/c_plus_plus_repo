#include <vector>
#include <iostream>

#define struct class

// variables in classes a private by default
struct Player 
//class Player
{
private:
    int x, y;
    int speed;
public:
    void Move(int xa, int ya)
    {
        x += xa * speed;
        y += ya * speed;
    }
};

struct Vec2
{
    float x, y;
    void Add(const Vec2& other)
    {
        x += other.x;
        y += other.y;
    }
};

int main()
{
    Player player;
    player.Move(1, -1);

    std::cin.get();
}