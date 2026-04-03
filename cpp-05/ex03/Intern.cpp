#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}


AForm* Intern::makeForm(std::string formName, std::string target) {
    
    std::string names[3] = {
        "shrubbery creation", 
        "robotomy request", 
        "presidential pardon"

    };

    for (int i = 0; i < 3; i++) {
        if (formName == names[i]) {
            switch (i) {
                case 0:
                    std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
                    return new ShrubberyCreationForm(target);
                case 1:
                    std::cout << "Intern creates RobotomyRequestForm" << std::endl;
                    return new RobotomyRequestForm(target);
                case 2:
                    std::cout << "Intern creates PresidentialPardonForm" << std::endl;
                    return new PresidentialPardonForm(target);
            }
        }
    }
    return NULL;
};

