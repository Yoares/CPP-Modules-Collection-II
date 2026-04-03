#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);

    AForm* form1 = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm* form2 = someRandomIntern.makeForm("shrubbery creation", "home");
    AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Arthur");
    AForm* form4 = someRandomIntern.makeForm("unknown form", "???");

    if (form1)
    {
        boss.signForm(*form1);
        boss.executeForm(*form1);
        delete form1;
    }

    if (form2)
    {
        boss.signForm(*form2);
        boss.executeForm(*form2);
        delete form2;
    }

    if (form3)
    {
        boss.signForm(*form3);
        boss.executeForm(*form3);
        delete form3;
    }

    delete form4; // probably NULL, safe

    return 0;
}