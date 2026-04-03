#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    Bureaucrat boss("Boss", 1);
    Bureaucrat intern("Intern", 150);

    Form contract("Contract", 50, 25);

    std::cout << contract << std::endl;

    intern.signForm(contract); // should fail
    boss.signForm(contract);   // should succeed

    std::cout << contract << std::endl;

    return 0;
}