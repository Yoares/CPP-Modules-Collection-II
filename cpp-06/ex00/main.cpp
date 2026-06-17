#include "ScalarConverte.hpp"
#include <iostream>

int main(int ac, char **av)
{
    (void)ac;
    const std::string& s = av[1];
    ScalarConverte::convert(s);
}