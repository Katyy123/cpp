/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:06:56 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/23 20:47:53 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm() {

    std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", target, 145, 137) {

    std::cout << "ShrubberyCreationForm Parametric constructor called" << std::endl;
    try {
        if (this->getGradeToSign() < 1)
            throw GradeTooHighException();
        else if (this->getGradeToSign() > 150)
            throw GradeTooLowException();
    }
    catch (GradeTooHighException & e) {
        std::cout << "ShrubberyCreationForm " << this->getName() << ": grade required to sign: " << e.what() << std::endl;
    }
    catch (GradeTooLowException & e) {
        std::cout << "ShrubberyCreationForm " << this->getName() << ": grade required to sign: " << e.what() << std::endl;
    }

    try {
        if (this->getGradeToExec() < 1)
            throw GradeTooHighException();
        else if (this->getGradeToExec() > 150)
            throw GradeTooLowException();
    }
    catch (GradeTooHighException & e) {
        std::cout << "ShrubberyCreationForm " << this->getName() << ": grade required to execute: " << e.what() << std::endl;
    }
    catch (GradeTooLowException & e) {
        std::cout << "ShrubberyCreationForm " << this->getName() << ": grade required to execute: " << e.what() << std::endl;
    }
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & form) : AForm(form) {

    std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & form) {

    if (this != &form) {
        this->setIsSigned(form.getIsSigned());
		this->setTarget(form.getTarget());
	}
    return *this;
}

void ShrubberyCreationForm::executeConcrete() const {

    
}

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & form) {

    o << std::endl;
    o << form.getName() << " ShrubberyCreationForm:" << std::endl;
    o << std::boolalpha << "is signed: " << form.getIsSigned() << std::endl;
    o << "grade required to sign: " << form.getGradeToSign() << std::endl;
    o << "grade required to execute: " << form.getGradeToExec() << std::endl;
    o << std::endl;
    return o;
}