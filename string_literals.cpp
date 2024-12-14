#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>

void print_with_zeros(auto const note, std::string const& s)
{
    std::cout << note;
    for (const char c : s)
        c ? std::cout << c : std::cout << "₀";
    std::cout << " (size = " << s.size() << ")\n";
}

void PrintString(const std::string & string) //make sure to pass as const and reference
{
    std::cout << string << std::endl;
}

//STRING LITERALS ARE ALWAYS STORE IN READ-ONLY MEMORY
int main()
{
    char* name = "Cherno"; //This string is stored in a const section in the binary, you cannot modifiy it.
    // = to say const char* name = "Cherno";
    //name[2] = 'a'; //In release mode the character is not overwriten, in debug mode it throws an exception as you are trying to wrie to read-only memory
    std::cout << name << ", size = " << strlen(name) << std::endl;

    //To modify the string you define as an array instead of a pointer
    char name2[] = "Cherno";
    name2[2] = 'a';
    std::cout << name2 << ", size = " << strlen(name2) << std::endl;

    const wchar_t* name3 = L"Cherno"; 
    const char16_t* name4 = u"Cherno"; //2 bytes
    const char32_t* name5 = U"Cherno"; //4 bytes


    //The statement using namespace std::string_literals; allows you to use the string literal operator suffix "s" defined in the C++ Standard Library,
    //which creates std::string objects directly from string literals.
    using namespace std::string_literals; //C++ 14

    std::string name0 = "Cherno"s + " hello"s;
    std::cout << name0 << ", size = " << std::endl;

    //Ignores scape character
    const char* example = R"((Line1
    Line2
    Line3
    Line4))";
    std::cout << example << std::endl;

    //Ignores scape character
    const char* example2 = "(Line1\nLine2\nLine3\nLine4)";
    std::cout << example2 << std::endl;

     std::string s1 = "abc\0\0def";
    std::string s2 = "abc\0\0def"s;
    print_with_zeros("s1: ", s1);
    print_with_zeros("s2: ", s2);



}