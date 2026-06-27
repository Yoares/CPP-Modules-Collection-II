#include "Array.hpp"

#include "Array.hpp"
#include <iostream>

int main() {
    Array<int> numbers(5);
    Array<std::string> names(6);
    try {
        numbers[0] = 1337;
        std::cout << "Index 0: " << numbers[0] << std::endl;
        names[0] = "yasser";
        std::cout <<  "Index 0: " << names[0] << std::endl;
        std::cout << "size of nums is " << names.size() << std::endl;
        std::cout << "Attempting out of bounds access..." << std::endl;
        numbers[10] = 42; 
        names[10] = "khoussi";
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}