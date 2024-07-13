#include <iostream>
#include <string>
#include <cstring>

void PrintString(const std::string & string) //make sure to pass as const and reference
{
    std::cout << string << std::endl;
}

int main()
{
    char* name = "Cherno";
    char name2[7] = { 'C', 'h', 'e', 'r', 'n', 'o', 0 };
    std::string name3 = "Cherno";
    
    std::cout << name << ", size = " << strlen(name) << std::endl;
    std::cout << name2 << ", size = " << strlen(name2) << std::endl;
    std::cout << name3 << ", size = " << name3.size() << std::endl;

    std::string name4 = std::string("Cherno ") + "hello!";
    bool contains = name4.find("no") != std::string::npos;
    std::cout << name4 << ", size = " << name4.size() << std::endl;

}