#include <iostream>
#include <string>
#include <functional>

class MyClass {
    public:
    MyClass() = default; //force the default constructor of the compilator
    MyClass(const MyClass & other) = delete; //constructor de copia se fuerza a que sea borrado impidiendo que se hagan copias de esa clase.
    explicit MyClass( const std::string & s) : val(std::stoi(s)) {

    }

    int val = 5;
};

int main() {
    MyClass m1;
    std::cout << m1.val << "\n";

    MyClass m2 { "25" };
    std::cout << m2.val << "\n";

    //MyClass m3 = m1;
}