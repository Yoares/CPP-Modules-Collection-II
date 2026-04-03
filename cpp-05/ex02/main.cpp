#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat boss("Boss", 1);
    Bureaucrat low("Low", 150);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Marvin");

    // Signing
    boss.signForm(shrub);
    boss.signForm(robot);
    boss.signForm(pardon);

    // Execution
    boss.executeForm(shrub);
    boss.executeForm(robot);
    boss.executeForm(pardon);

    // Failure case
    low.executeForm(shrub);

    return 0;
}