#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}


AForm* Intern::makeForm(std::string name, std::string target) {
    if (name == "shrubbery creation")
        return new ShrubberyCreationForm(target);
    else if (name == "robotomy request")
        return new RobotomyRequestForm(target);
    else if (name == "presidential pardon")
        return new PresidentialPardonForm(target);
    
    std::cout << "Error: Form not found" << std::endl;
    return NULL;
}
