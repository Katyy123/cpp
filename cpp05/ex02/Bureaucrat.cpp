/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:07:12 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/23 20:52:58 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(): _name(""), _grade(150) {

    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {

    std::cout << "Parametric constructor called" << std::endl;
    try {
        if (grade < 1)
            throw GradeTooHighException();
        else if (grade > 150)
            throw GradeTooLowException();
        else
           this->_grade = grade;
    }
    catch (GradeTooHighException & e) {
        std::cout << "Bureaucrat " << this->getName() << ": " << e.what() << std::endl;
        this->_grade = 1;
        std::cout << "The grade was set at 1" << std::endl;
    }
    catch (GradeTooLowException & e) {
        std::cout << "Bureaucrat " << this->getName() << ": " << e.what() << std::endl;
        this->_grade = 150;
        std::cout << "The grade was set at 150" << std::endl;
    }
}

Bureaucrat::Bureaucrat(Bureaucrat const & bureaucrat) : _name(bureaucrat.getName()) {

    std::cout << "Copy constructor called" << std::endl;
    this->_grade = bureaucrat.getGrade();
}

Bureaucrat::~Bureaucrat() {

    std::cout << "Destructor called" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & bureaucrat) {

    if (this != &bureaucrat)
        this->_grade = bureaucrat.getGrade();
    return *this;
}

std::string const & Bureaucrat::getName() const {

    return this->_name;
}

int Bureaucrat::getGrade() const {

    return this->_grade;
}

const char * Bureaucrat::GradeTooHighException::what() const throw() {

    return "grade too high";
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {

    return "grade too low";
}

void Bureaucrat::incrementGrade() {

     std::cout << "incrementGrade() called for Bureaucrat " << this->getName() << std::endl;
    try {
        if (this->_grade == 1)
            throw GradeTooHighException();
        else
            this->_grade--;
    }
    catch (GradeTooHighException & e) {
        std::cout << "Bureaucrat " << this->getName() << ": " << e.what() << " after the increment. Can't do that." << std::endl;
    }
}

void Bureaucrat::decrementGrade() {

   std::cout << "decrementGrade() called for Bureaucrat " << this->getName() << std::endl;
   try {
        if (this->_grade == 150)
            throw GradeTooLowException();
        else
            this->_grade++;
    }
    catch (GradeTooLowException & e) {
        std::cout << "Bureaucrat " << this->getName() << ": " << e.what() << " after the decrement. Can't do that." << std::endl;
    }
}

void Bureaucrat::signForm(AForm const & form) {

    if (form.getIsSigned() == 1)
        std::cout << "Bureaucrat " << this->_name << " signed form " << form.getName() << std::endl;
    else
        std::cout << "Bureaucrat " << this->_name << " couldn't sign form " << form.getName() << std::endl;
}

void Bureaucrat::executeForm(Form const & form) {
    
    
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & bureaucrat) {

    o << bureaucrat.getName() << ", Bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
    return o;
}