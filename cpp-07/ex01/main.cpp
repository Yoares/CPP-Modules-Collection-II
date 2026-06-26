#include "iter.hpp"

int main()
{
    int numbers[] = {1, 2, 3, 4, 5};
    char letters[] = {'A', 'B', 'C', 'D'};
    double values[] = {1.1, 2.2, 3.3};
    std::string words[] = {"yasser", "khoussi", "20"};

    std::cout << "Integers:" << std::endl;
    iter(numbers, 5, print);

    std::cout << "\nCharacters:" << std::endl;
    iter(letters, 4, print);

    std::cout << "\nDoubles:" << std::endl;
    iter(values, 3, print);

    std::cout << "\nStrings:" << std::endl;
    iter(words, 3, print);

    return 0;
}