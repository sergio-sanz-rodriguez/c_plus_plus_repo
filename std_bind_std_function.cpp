#include <iostream>
#include <string>
#include <functional>

std::string getRandomString() {
    return "this is the random string";
}

std::string fillString(size_t width, char fillCharacter, const std::string & theString)
{
    if(theString.size() >= width)
        return theString;
    
    size_t countFillCharacters = width - theString.size();

    return std::string(countFillCharacters, fillCharacter) + theString;


}

class ExampleClass
{
    public:
    void theMethod()
    {
        std::cout << "Calling theMethod of ExampleClass \n";
    }
};

int main() {

    // Example of std::function. Encapsulates a pointer to a function

    //std::cout << "this is the random string" << std::endl;
    std::function<std::string()> functionPointer = getRandomString;
    std::cout << functionPointer() << "\n";

    std::cout << fillString(20, '_', "Hello world") << "\n";

    std::function<std::string(size_t, char, const std::string &)> myFun = fillString; // this generates a pointer to a function

    std::cout << myFun(20, '_', "Hello world") << "\n";

    // Example of std::bind. Encapsulates a call to a method of a class

    std::function<std::string(const std::string &)> myNewFun = std::bind(fillString, 20, '_', std::placeholders::_1);

    std::cout << myNewFun("Goodbye world") << "\n";

    // Call a method of a class but we want to pass un std::function para una instance of a class.
    // auto refers to std::function<std::string(const std::string &)>
    ExampleClass ExampleClass;
    auto exampleClassFunctionPointer = std::bind(&ExampleClass::theMethod, &ExampleClass);

    exampleClassFunctionPointer();
    return 0;

}