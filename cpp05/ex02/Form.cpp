/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:07:10 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/23 21:02:51 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name(""), _target(""), _isSigned(0), _gradeToSign(1), _gradeToExec(1) {

    std::cout << "Default constructor called" << std::endl;
}

AForm::AForm(std::string name, std::string target, int gradeToSign, int gradeToExec)
        : _name(name), _target(target), _isSigned(0), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {

    std::cout << "Parametric constructor called" << std::endl;
    try {
        if (this->getGradeToSign() < 1)
            throw GradeTooHighException();
        else if (this->getGradeToSign() > 150)
            throw GradeTooLowException();
    }
    catch (GradeTooHighException & e) {
        std::cout << "AForm " << this->getName() << ": grade required to sign: " << e.what() << std::endl;
    }
    catch (GradeTooLowException & e) {
        std::cout << "AForm " << this->getName() << ": grade required to sign: " << e.what() << std::endl;
    }

    try {
        if (this->getGradeToExec() < 1)
            throw GradeTooHighException();
        else if (this->getGradeToExec() > 150)
            throw GradeTooLowException();
    }
    catch (GradeTooHighException & e) {
        std::cout << "AForm " << this->getName() << ": grade required to execute: " << e.what() << std::endl;
    }
    catch (GradeTooLowException & e) {
        std::cout << "AForm " << this->getName() << ": grade required to execute: " << e.what() << std::endl;
    }
}

AForm::AForm(AForm const & form) : _name(form.getName()), _gradeToSign(form.getGradeToSign()), _gradeToExec(form.getGradeToExec()) {

    std::cout << "Copy constructor called" << std::endl;
    this->setTarget(form.getTarget());
    this->setIsSigned(form.getIsSigned());
}

AForm::~AForm() {

    std::cout << "Destructor called" << std::endl;
}

AForm & AForm::operator=(AForm const & form) {

    if (this != &form) {
        this->setIsSigned(form.getIsSigned());
        this->setTarget(form.getTarget());
    }
    return *this;
}

std::string const & AForm::getName() const {

    return this->_name;
}

std::string AForm::getTarget() const {

    return this->_target;
}

bool AForm::getIsSigned() const {

    return this->_isSigned;
}

int AForm::getGradeToSign() const {

    return this->_gradeToSign;
}

int AForm::getGradeToExec() const {

    return this->_gradeToExec;
}

void AForm::setTarget(std::string target) {

    this->_target = target;
}

void AForm::setIsSigned(bool isSigned) {

    this->_isSigned = isSigned;
}

const char * AForm::GradeTooHighException::what() const throw() {

    return "grade too high";
}

const char * AForm::GradeTooLowException::what() const throw() {

    return "grade too low";
}

const char * AForm::FormNotSignedException::what() const throw() {

    return "form not signed";
}

void AForm::beSigned(Bureaucrat & bureaucrat) {

    if (this->getIsSigned() == 0) {
        try
        {
            if (bureaucrat.getGrade() >= this->getGradeToSign())
                throw GradeTooLowException();
            else
            {
                this->setIsSigned(1);
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
        std::cout << "AForm " << this->getName() << ": already signed" << std::endl;
}

void AForm::execute(Bureaucrat const & executor) const {

    try {
        if (this->getIsSigned() == 0)
            throw FormNotSignedException();
        else {
            try {
                if (executor.getGrade() > this->getGradeToExec())
                    throw GradeTooLowException();
                else {
                    executeConcrete();
                    //add executeForm() in some way. Execute form shold check if that bureaucrat has executed the form
                }
            }
            catch (GradeTooLowException & e) {
                std::cout << "Bureaucrat " << executor.getName() << ": " << e.what();
                //add executeForm() in some way. Execute form shold check if that bureaucrat has executed the form
            }
        }   
    }
    catch (FormNotSignedException & e) {
        std::cout << "Form " << this->getName() << ": " << e.what();
        //add executeForm() in some way. Execute form shold check if that bureaucrat has executed the form
    }
}

std::ostream & operator<<(std::ostream & o, AForm const & form) {

    o << std::endl;
    o << form.getName() << " AForm:" << std::endl;
    o << std::boolalpha << "is signed: " << form.getIsSigned() << std::endl;
    o << "grade required to sign: " << form.getGradeToSign() << std::endl;
    o << "grade required to execute: " << form.getGradeToExec() << std::endl;
    o << std::endl;
    return o;
}