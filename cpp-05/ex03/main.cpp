
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"


int main() {
    // 1. Create the Factory Worker (The Intern)
    Intern  someRandomIntern;

    // 2. Create the Boss (To sign/execute the forms)
    Bureaucrat boss("The Boss", 1);

    std::cout << "\n--- TEST 1: ROBOTOMY REQUEST ---" << std::endl;
    {
        // The Intern creates the form on the Heap
        AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        
        // We must check if rrf is not NULL (in case of typos)
        if (rrf) {
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            
            // CLEANUP: The Intern created it with 'new', we must 'delete' it.
            delete rrf;
        }
    }

    std::cout << "\n--- TEST 2: SHRUBBERY CREATION ---" << std::endl;
    {
        AForm* form = someRandomIntern.makeForm("shrubbery creation", "Home");
        
        if (form) {
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
        }
    }

    std::cout << "\n--- TEST 3: PRESIDENTIAL PARDON ---" << std::endl;
    {
        AForm* form = someRandomIntern.makeForm("presidential pardon", "Criminal");
        
        if (form) {
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
        }
    }

    std::cout << "\n--- TEST 4: INVALID FORM (Handling Errors) ---" << std::endl;
    {
        // Try to ask for a form that doesn't exist
        AForm* form = someRandomIntern.makeForm("make me coffee", "Boss");
        
        if (form) {
            boss.signForm(*form);
            delete form;
        } else {
            // This is expected
            std::cout << "Main: The pointer is NULL, so we didn't crash!" << std::endl;
        }
    }

    return 0;
}