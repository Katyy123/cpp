#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name(""), _isSigned(0), _gradeToSign(1), _gradeToExec(1) {

    std::cout << "Default constructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : _name(name), _isSigned(0), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {

    std::cout << "Parametric constructor called" << std::endl;
    try {
        if (gradeToSign < 1)
            throw GradeTooHighException();
        else if (gradeToSign > 150)
            throw GradeTooLowException();
    }
    catch (GradeTooHighException & e) {
        std::cout << "Form " << this->getName() << ": grade required to sign: " << e.what() << std::endl;
    }
    catch (GradeTooLowException & e) {
        std::cout << "Form " << this->getName() << ": grade required to sign: " << e.what() << std::endl;
    }

    try {
        if (gradeToExec < 1)
            throw GradeTooHighException();
        else if (gradeToExec > 150)
            throw GradeTooLowException();
    }
    catch (GradeTooHighException & e) {
        std::cout << "Form " << this->getName() << ": grade required to execute: " << e.what() << std::endl;
    }
    catch (GradeTooLowException & e) {
        std::cout << "Form " << this->getName() << ": grade required to execute: " << e.what() << std::endl;
    }
}

Form::Form(Form const & form) : _name(form.getName()), _gradeToSign(form.getGradeToSign()), _gradeToExec(form.getGradeToExec()) {

    std::cout << "Copy constructor called" << std::endl;
    this->_isSigned = form.getIsSigned();
}

Form::~Form() {

    std::cout << "Destructor called" << std::endl;
}

Form & Form::operator=(Form const & form) {

    if (this != &form)
        this->_isSigned = form.getIsSigned();
    return *this;
}

std::string const & Form::getName() const {

    return this->_name;
}
bool Form::getIsSigned() const {

    return this->_isSigned;
}

int Form::getGradeToSign() const {

    return this->_gradeToSign;
}

int Form::getGradeToExec() const {

    return this->_gradeToExec;
}

const char * Form::GradeTooHighException::what() const throw() {

    return "grade too high";
}

const char * Form::GradeTooLowException::what() const throw() {

    return "grade too low";
}

void Form::beSigned(Bureaucrat & bureaucrat) {

    if (this->_isSigned == 0) {
        try
        {
            if (bureaucrat.getGrade() >= this->_gradeToSign)
                throw GradeTooLowException();
            else
            {
                this->_isSigned = 1;
                bureaucrat.signForm(*this);
            }
        }
        catch (GradeTooLowException &e)
        {
            std::cout << "Bureaucrat " << bureaucrat.getName() << ": " << e.what() << ". ";
            bureaucrat.signForm(*this);
        }
    }
    else
        std::cout << "Form " << this->getName() << ": already signed" << std::endl;
}

std::ostream & operator<<(std::ostream & o, Form const & form) {

    o << std::endl;
    o << form.getName() << " Form:" << std::endl;
    o << std::boolalpha << "is signed: " << form.getIsSigned() << std::endl;
    o << "grade required to sign: " << form.getGradeToSign() << std::endl;
    o << "grade required to execute: " << form.getGradeToExec() << std::endl;
    o << std::endl;
    return o;
}