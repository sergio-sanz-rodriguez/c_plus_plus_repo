#include <iostream>
#include <array>

int main()
{
    static const int size = 5;
    int example[size]; //stack memory
    for (int i = 0; i < size; i++)
    {
        example[i] = 2;       
    }
    int* another = new int[size]; //heap memory
    for (int i = 0; i < size; i++)
    {
        another[i] = 2;       
    }
    delete[] another;

    std::array<int, size> another2;
    for (int i = 0; i < another2.size(); i++)
    {
        another2[i] = 2;       
    }


    return 0;
}