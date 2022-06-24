/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:06:58 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/23 16:06:59 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm() {

    std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", target, 72, 45) {

    std::cout << "RobotomyRequestForm Parametric constructor called" << std::endl;
    try {
        if (this->getGradeToSign() < 1)
            throw GradeTooHighException();
        else if (this->getGradeToSign() > 150)
            throw GradeTooLowException();
    }
    catch (GradeTooHighException & e) {
        std::cout << "RobotomyRequestForm " << this->getName() << ": grade required to sign: " << e.what() << std::endl;
    }
    catch (GradeTooLowException & e) {
        std::cout << "RobotomyRequestForm " << this->getName() << ": grade required to sign: " << e.what() << std::endl;
    }

    try {
        if (this->getGradeToExec() < 1)
            throw GradeTooHighException();
        else if (this->getGradeToExec() > 150)
            throw GradeTooLowException();
    }
    catch (GradeTooHighException & e) {
        std::cout << "RobotomyRequestForm " << this->getName() << ": grade required to execute: " << e.what() << std::endl;
    }
    catch (GradeTooLowException & e) {
        std::cout << "RobotomyRequestForm " << this->getName() << ": grade required to execute: " << e.what() << std::endl;
    }
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & form) : AForm(form) {

    std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {

    std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & form) {

    if (this != &form) {
        this->setIsSigned(form.getIsSigned());
		this->setTarget(form.getTarget());
	}
    return *this;
}

void RobotomyRequestForm::executeConcrete() const {

    std::cout << "Some drilling noises" << std::endl;
    srand(time(NULL));
    if (rand() % 2 == 1)
        std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
    else
        std::cout << "The robotomy of " << this->getTarget() << " failed" << std::endl;
}

std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & form) {

    o << std::endl;
    o << "Form " << form.getName() << ": " << std::endl;
    o << "target: " << form.getTarget() << std::endl;
    o << std::boolalpha << "is signed: " << form.getIsSigned() << std::endl;
    o << "grade required to sign: " << form.getGradeToSign() << std::endl;
    o << "grade required to execute: " << form.getGradeToExec() << std::endl;
    o << std::endl;
    return o;
}