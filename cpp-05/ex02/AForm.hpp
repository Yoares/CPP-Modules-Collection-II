#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm {
private:
    const std::string   _name;
    bool                _isSigned;
    const int           _gradeToSign;
    const int           _gradeToExecute;

public:
    AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    // Getters
    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Main Functionality
    void beSigned(const Bureaucrat& b);

    // Execution Logic (Template Method Pattern)
    void execute(const Bureaucrat& executor) const;

protected:
    // Abstract function for child classes to implement the actual action
    virtual void performExecute() const = 0;

public:
    // Custom Exceptions
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class NotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

// Stream Operator Overload
std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif