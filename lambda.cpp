#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::string username = "John";
    
    std::cout << "lambda function:\n";

    //auto func =[&, username]() {std::cout << username << \n"; };
    auto func =[](std::string username) {std::cout << username << "\n"; };
    func(username);

    //int factor = 2;
    //auto multiply = [factor](int x) { return x * factor; };

    std::cout << "lambda function with for_each \n";

    std::vector<std::string> my_vector = {"hello", "world", "foo", "bar"};

    auto print_element = [](const std::string & elem) { std::cout << elem << "\n"; };

    std::for_each(my_vector.begin(), my_vector.end(), print_element);

    std::cout << "lambda function with for loop \n";

    for(std::string & elem2 : my_vector)
    {
        print_element(elem2);
    }
}