#include <iostream>
#include <cstring> // Needed for memset

# define LOG(x) std::cout << x << std::endl

int main() {
    // Allocate memory for an array of 8 characters
    char* buffer = new char[8];

    // Set all bytes of the allocated memory to 0
    memset(buffer, 0, 8);

    char** ptr = &buffer;

    for(int i=0; i<8; i++)
    {
        ptr[0][i] = 'a' + i;
        LOG(ptr[0][i]);
    }

    // Deallocate the memory
    delete[] buffer;

    //int var = 8;
    //int* ptr = &var;
    //*ptr = 10;
    //LOG(var);

    return 0;
}