#include <vector>
#include <iostream>

// variables in classes a private by default
class Player 
{
public:
    int x, y;
    int speed;

    void Move(int xa, int ya)
    {
        x += xa * speed;
        y += ya * speed;
    }
};

int main()
{
    Player player;
    player.Move(1, -1);

    std::cin.get();
}