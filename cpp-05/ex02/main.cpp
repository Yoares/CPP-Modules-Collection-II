#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try {
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
    low.signForm(shrub);
    low.executeForm(shrub);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}