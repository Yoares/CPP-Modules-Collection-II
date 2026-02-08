#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "--- TEST 1: Form Creation (Valid & Invalid) ---" << std::endl;
    try {
        // Valid Form: Name "Tax", Grade to Sign 50, Grade to Execute 100
        Form tax("Tax", 50, 100);
        std::cout << tax << std::endl;

        // Invalid Form: Grade too high (0)
        std::cout << "Attempting to create invalid form (Grade 0)..." << std::endl;
        Form impossible("Impossible", 0, 50); 
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 2: Signing Success (Boss signs Tax) ---" << std::endl;
    try {
        Bureaucrat boss("Boss", 5); // Grade 5 (Very high rank)
        Form tax("Tax Form", 50, 100); // Requires Grade 50 to sign

        std::cout << "Before: " << tax << std::endl;
        
        // Boss (5) is higher than Tax (50), so this should work.
        boss.signForm(tax);

        std::cout << "After: " << tax << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 3: Signing Failure (Intern tries to sign Constitution) ---" << std::endl;
    try {
        Bureaucrat intern("Intern", 150); // Grade 150 (Lowest rank)
        Form constitution("Constitution", 1, 1); // Requires Grade 1 to sign

        // Intern (150) is lower than Constitution (1).
        // This should print the error message from signForm:
        // "Intern couldn't sign Constitution because..."
        intern.signForm(constitution);
        
        // Verify it was NOT signed
        std::cout << "Status of form: " << constitution << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "This catch block shouldn't run because signForm catches its own errors!" << std::endl;
    }

    return 0;
}