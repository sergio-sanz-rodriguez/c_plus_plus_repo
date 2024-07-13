#include <iostream>
#include <string>

class MyClass
{
    public:
    MyClass(int a) {
        if (a < 5 || a > 25)
        {
            throw std::runtime_error("Integer out of range");
        }
    }

    MyClass( const std::string &s) : MyClass( std::stoi(s)) {
        
    };
};

int main() {
    MyClass m1{10};
}