#include <iostream>
#include <cstring> // Needed for memset

void Increment(int& value)
{
    value++;
}
int main() {

    int a = 5;
    int b = 8;

    int& ref = a;
    ref = b;
    // a = 8, b = 8

    int c = 9;
    Increment(c);

    // Deallocate the memory
    std::cout << "a: " << a << ", b: " << b << ", ref: " << ref << std::endl;

    std::cout << "c: " << c << std::endl;

    return 0;
}