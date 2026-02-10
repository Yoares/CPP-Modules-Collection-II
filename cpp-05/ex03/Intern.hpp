#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
    Intern();
    ~Intern();
    // Copy/Assign...

    // The Factory Method
    AForm* makeForm(std::string formName, std::string target);
};

#endif
