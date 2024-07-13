#include <iostream>
#include <vector>
#include <string>
#include <map>

int main() {
    std::vector<std::string> my_vector;

    my_vector.push_back("foo");
    my_vector.push_back("bar");
    my_vector.push_back("baz");

    for(std::string & e: my_vector)
    {
        e = e + "modified";
        std::cout << e << "\n";        
    }

    std::map<std::string, std::string> my_map;

    my_map["foo"] = "foo_value";
    my_map["bar"] = "bar_value";
    my_map["baz"] = "baz_value";

    // std::pair<std::string, std::string>
    for(auto e : my_map) 
    {
        std::cout << e.first << " : " << e.second << "\n";
    }
    
    return 0;

}