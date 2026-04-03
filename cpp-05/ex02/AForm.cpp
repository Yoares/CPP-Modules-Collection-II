#include "AForm.hpp"
#include "Bureaucrat.hpp"

// --- Constructors & Destructor ---

AForm::AForm() 
    : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : _name(other._name), 
      _isSigned(other._isSigned), 
      _gradeToSign(other._gradeToSign), 
      _gradeToExecute(other._gradeToExecute) {}

AForm::~AForm() {}


AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

// --- Getters ---

const std::string& AForm::getName() const {
    return _name;
}

bool AForm::getIsSigned() const {
    return _isSigned;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _gradeToSign) {
        throw GradeTooLowException();
    }
    _isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const {
    if (!this->_isSigned) {
        throw NotSignedException();
    }

    if (executor.getGrade() > this->_gradeToExecute) {
        throw GradeTooLowException();
    }
    this->performExecute();
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high! (Highest possible is 1)";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low! (Lowest possible is 150)";
}

const char* AForm::NotSignedException::what() const throw() {
    return "Form is not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "Form: " << f.getName() 
       << " | Signed: " << (f.getIsSigned() ? "Yes" : "No")
       << " | Sign Grade: " << f.getGradeToSign()
       << " | Exec Grade: " << f.getGradeToExecute();
    return os;
}