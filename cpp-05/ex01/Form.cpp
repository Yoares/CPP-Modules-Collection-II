#include "Form.hpp"

Form::Form() : _name("Default Form"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1) {}

Form::~Form() {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

Form::Form(const Form& other)
    : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}
 
const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > this->_gradeToSign)
        throw Form::GradeTooHighException();
    this->_isSigned = true;
}

std::string Form::getName() const{
    return this->_name;
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << "Form: " << f.getName();
    os << ", Signed: ";

    if (f.getIsSigned())
        os << "Yes";
    else
        os << "No";

    os << ", Grade to Sign: " << f.getGradeToSign();
    os << ", Grade to Execute: " << f.getGradeToExecute();

    return os;
}

bool Form::getIsSigned() const { return _isSigned; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExecute; }