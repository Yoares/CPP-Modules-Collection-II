#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try{

    Bureaucrat boss("Boss", 1);
    Bureaucrat intern("Intern", 90);

    Form contract("Contract", 100, 10);

    std::cout << contract << std::endl;

    intern.signForm(contract); // should fail
    boss.signForm(contract);   // should succeed

    std::cout << contract << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}