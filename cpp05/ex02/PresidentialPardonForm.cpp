/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:07:02 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/23 16:07:03 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm() {

    std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", target, 25, 5) {

    std::cout << "PresidentialPardonForm Parametric constructor called" << std::endl;
    try {
        if (this->getGradeToSign() < 1)
            throw GradeTooHighException();
        else if (this->getGradeToSign() > 150)
            throw GradeTooLowException();
    }
    catch (GradeTooHighException & e) {
        std::cout << "PresidentialPardonForm " << this->getName() << ": grade required to sign: " << e.what() << std::endl;
    }
    catch (GradeTooLowException & e) {
        std::cout << "PresidentialPardonForm " << this->getName() << ": grade required to sign: " << e.what() << std::endl;
    }

    try {
        if (this->getGradeToExec() < 1)
            throw GradeTooHighException();
        else if (this->getGradeToExec() > 150)
            throw GradeTooLowException();
    }
    catch (GradeTooHighException & e) {
        std::cout << "PresidentialPardonForm " << this->getName() << ": grade required to execute: " << e.what() << std::endl;
    }
    catch (GradeTooLowException & e) {
        std::cout << "PresidentialPardonForm " << this->getName() << ": grade required to execute: " << e.what() << std::endl;
    }
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & form) : AForm(form) {

    std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {

    std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & form) {

    if (this != &form) {
        this->setIsSigned(form.getIsSigned());
		this->setTarget(form.getTarget());
	}
    return *this;
}

void PresidentialPardonForm::executeConcrete() const {

    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const & form) {

    o << std::endl;
    o << "Form " << form.getName() << ": " << std::endl;
    o << "target: " << form.getTarget() << std::endl;
    o << std::boolalpha << "is signed: " << form.getIsSigned() << std::endl;
    o << "grade required to sign: " << form.getGradeToSign() << std::endl;
    o << "grade required to execute: " << form.getGradeToExec() << std::endl;
    o << std::endl;
    return o;
}