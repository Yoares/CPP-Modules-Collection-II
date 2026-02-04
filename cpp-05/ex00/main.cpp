#include "Bureaucrat.hpp"

#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    std::cout << "--- TEST 1: The 'Happy Path' (Working normally) ---" << std::endl;
    try {
        // Create a valid Bureaucrat (Grade 2 is valid)
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl; // Testing << operator

        // Increment grade (2 -> 1)
        std::cout << "Promoting Bob..." << std::endl;
        bob.incrementGrade();
        std::cout << bob << std::endl;

        // Decrement grade (1 -> 2)
        std::cout << "Demoting Bob..." << std::endl;
        bob.decrementGrade();
        std::cout << bob << std::endl;
    }
    catch (std::exception& e) {
        // We should NOT end up here in this test
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 2: Constructor Too Low (Grade 151) ---" << std::endl;
    try {
        // This should throw GradeTooLowException immediately
        Bureaucrat jim("Jim", 151); 
        
        // This line will NEVER print
        std::cout << "Jim created successfully (This shouldn't happen)" << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << "Caught expected error: " << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Caught generic error: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 3: Constructor Too High (Grade 0) ---" << std::endl;
    try {
        // This should throw GradeTooHighException immediately
        Bureaucrat alice("Alice", 0);
    }
    catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << "Caught expected error: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 4: Operation Too High (Incrementing past 1) ---" << std::endl;
    try {
        Bureaucrat ceo("CEO", 1); // Valid
        std::cout << ceo << std::endl;
        
        std::cout << "Attempting to promote CEO..." << std::endl;
        ceo.incrementGrade(); // Should fail! 1 -> 0 is impossible
    }
    catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << "Caught expected error: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 5: Operation Too Low (Decrementing past 150) ---" << std::endl;
    try {
        Bureaucrat intern("Intern", 150); // Valid
        std::cout << intern << std::endl;
        
        std::cout << "Attempting to demote Intern..." << std::endl;
        intern.decrementGrade(); // Should fail! 150 -> 151 is impossible
    }
    catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << "Caught expected error: " << e.what() << std::endl;
    }

    return 0;
}