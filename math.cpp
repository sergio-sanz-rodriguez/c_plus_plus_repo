//g++ -S compiler.cpp -o compiler.s
#include <iostream>
#include <string>

const char* Log(const char* message)
{
    return message;
}

int Multiply(int a, int b)
{
    Log("Multiply");
    return a * b;
}

int main()
{
    std::cout << Multiply(5, 8) << std::endl;
}

