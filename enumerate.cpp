#include <iostream>

enum Example : unsigned char
{
    A = 5, B, C
};

int main()
{
    Example value = B;

    if (value == B)
    {
        std::cout << value << std::endl;
    }

    return 0;
}