#include "RobotomyRequestForm.hpp"
#include <cstdlib> // For rand() and srand()
// #include <ctime>   // For time() if you seed here

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        // _target is const, so we cannot assign to it. It must be initialized in the constructor.
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::performExecute() const{

    std::cout << "* VRRRRRRR... Drilling noises ... BZZZZZT *";

    if (std::rand() % 2 == 0)
    {
        std::cout << _target << "has been robotomized successfully" << std::endl;
    }
    else {
        std::cout << "Robotomy on " << _target << " failed." << std::endl;
    }
}

std::string RobotomyRequestForm::getTarget() const{
    return this->_target;
}

void RobotomyRequestForm::setTarget(std::string& target){
    this->_target = target;
}