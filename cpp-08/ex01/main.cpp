#include "Span.hpp"

int main()
{
    try
    {
        Span sp(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "------------------------" << std::endl;

    try
    {
        Span big(10000);

        std::vector<int> numbers;

        for (int i = 0; i < 10000; i++)
            numbers.push_back(rand());

        big.addRange(numbers.begin(), numbers.end());

        std::cout << "Shortest: " << big.shortestSpan() << std::endl;
        std::cout << "Longest : " << big.longestSpan() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}