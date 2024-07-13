#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {3, 1, 2, 4};

    std::sort(vec.begin(), vec.end(), [](int a, int b) { return a < b; });

    // Output the sorted vector
    for (int n : vec) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}