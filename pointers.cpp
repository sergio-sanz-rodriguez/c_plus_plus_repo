#include <iostream>
#include <cstring> // Needed for memset

int main() {
    // Allocate memory for an array of 8 characters
    char* buffer = new char[8];

    // Set all bytes of the allocated memory to 0
    memset(buffer, 0, 8);

    // Deallocate the memory
    delete[] buffer;

    return 0;
}