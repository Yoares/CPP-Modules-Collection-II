#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
    std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other){
    std::cout << "Bureaucrat Copy constructor called" << std::endl;
    *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
    std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
    if (this != &other) {
        _grade = other._grade; // Only copy the grade, name is const
    }
    return *this;
}

const std::string& Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::incrementGrade() {
    if (_grade <= 1) { // Cannot go higher than 1
        throw GradeTooHighException();
    }
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150) { // Cannot go lower than 150
        throw GradeTooLowException();
    }
    _grade++;
}

// Bureaucrat.cpp

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException(); 
    }
    if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }

    _grade = grade;
    std::cout << "Bureaucrat " << _name << " was born!" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high! (Highest possible is 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too Low! (Lower possible is 1)";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}


void Bureaucrat::signForm(AForm& form){
    try{
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch(std::exception& e){
        std::cout << _name << " couldn't sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) {
    try{
        form.execute(*this);

        std::cout << _name << "executed" << form.getName() << std::endl;
    }
    catch(std::exception& e){
        std::cout << _name << " couldn't execute " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}