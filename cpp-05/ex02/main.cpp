#include <iostream>
#include <cstdlib> // For rand/srand
#include <ctime>   // For time

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    // Seed the random number generator for Robotomy
    std::srand(std::time(0));

    std::cout << "\n--- 1. CREATING BUREAUCRATS ---" << std::endl;
    Bureaucrat boss("The Boss", 1);        // Rank 1 (Can do everything)
    Bureaucrat manager("Manager", 40);     // Rank 40 (Can robotomize, plant trees)
    Bureaucrat intern("Intern", 148);      // Rank 148 (Can't do anything)

    std::cout << boss << std::endl;
    std::cout << manager << std::endl;
    std::cout << intern << std::endl;

    std::cout << "\n--- 2. CREATING FORMS ---" << std::endl;
    ShrubberyCreationForm shrub("Home");      // Req: Sign 145, Exec 137
    RobotomyRequestForm   robot("Bender");    // Req: Sign 72, Exec 45
    PresidentialPardonForm pardon("Criminal"); // Req: Sign 25, Exec 5

    std::cout << shrub << std::endl;
    std::cout << robot << std::endl;
    std::cout << pardon << std::endl;

    std::cout << "\n--- 3. INTERN TRIES TO WORK (FAILURE TEST) ---" << std::endl;
    // Intern (148) tries to sign Shrubbery (Req 145) -> FAIL
    intern.signForm(shrub);
    // Intern (148) tries to execute Shrubbery -> FAIL (Not signed + Grade too low)
    // intern.z(shrub);

    std::cout << "\n--- 4. MANAGER TRIES TO WORK (PARTIAL SUCCESS) ---" << std::endl;
    // Manager (40) signs Shrubbery (Req 145) -> SUCCESS
    manager.signForm(shrub);
    // Manager (40) executes Shrubbery (Req 137) -> SUCCESS (Creates file)
    manager.executeForm(shrub);
    
    // Manager (40) signs Robotomy (Req 72) -> SUCCESS
    manager.signForm(robot);
    // Manager (40) executes Robotomy (Req 45) -> SUCCESS (Drilling noise)
    manager.executeForm(robot);

    // Manager (40) tries to sign Pardon (Req 25) -> FAIL
    manager.signForm(pardon);

    std::cout << "\n--- 5. BOSS TRIES TO WORK (TOTAL SUCCESS) ---" << std::endl;
    // Boss (1) signs Pardon (Req 25) -> SUCCESS
    boss.signForm(pardon);
    // Boss (1) executes Pardon (Req 5) -> SUCCESS
    boss.executeForm(pardon);

    std::cout << "\n--- 6. EXECUTE UNSIGNED FORM TEST ---" << std::endl;
    // Create a new form that no one signed
    RobotomyRequestForm unsignedRobot("UnsignedTarget");
    
    // Boss tries to execute it immediately -> FAIL (Form not signed)
    boss.executeForm(unsignedRobot);

    return 0;
}