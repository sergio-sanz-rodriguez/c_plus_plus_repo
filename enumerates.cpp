#include <iostream>
#include <string>

// Traditionally it was enum Banderas
enum class Banderas {
    FLAG_ONE,
    FLAG_TWO,
    FLAG_THREE
};

// you can assing the type of data that is able to store all the data inside de enumerate. If a new value of the enumerate is longer than long, then the compiler will complain.
enum class Banderas2 : long long {
    FLAG_ONE = 0x0000FFFF,
    FLAG_TWO = 0x00FFFFFF,
    FLAG_THREE = 0xFFFFFFFF,
    FLAG_FOUR = 0xFFFFFFFFF
};

void myFun(int n){
    std::cout << n << "\n";
}

int main() {
    //Banderas::FLAG_ONE;
    myFun(static_cast<int>(Banderas::FLAG_TWO));

    std::cout << sizeof(Banderas2) << "\n";
    return 0;

}