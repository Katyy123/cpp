/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:07:07 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/23 17:52:53 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {

    Intern someRandomIntern;
    AForm * form1;
    AForm * form2;
    AForm * form3;
    AForm * form4;
    std::cout << std::endl;

    std::cout << "------- FORM 1 -------" << std::endl;
    form1 = someRandomIntern.makeForm("wrong name", "target1");
    if (form1 != NULL) {
        std::cout << *form1;
        delete form1;
        std::cout << std::endl;
    }
    else std::cout << std::endl;

    std::cout << "------- FORM 2 -------" << std::endl;
    form2 = someRandomIntern.makeForm("shrubbery creation", "target2");
    if (form2 != NULL) {
        std::cout << *form2;
        delete form2;
        std::cout << std::endl;
    }

    std::cout << "------- FORM 3 -------" << std::endl;
    form3 = someRandomIntern.makeForm("robotomy request", "target3");
    if (form3 != NULL) {
        std::cout << *form3;
        delete form3;
        std::cout << std::endl;
    }

    std::cout << "------- FORM 4 -------" << std::endl;
    form4 = someRandomIntern.makeForm("presidential pardon", "target4");
    if (form4 != NULL) {
        std::cout << *form4;
        delete form4;
    }
    std::cout << "----------------------" << std::endl << std::endl;

    return 0;
}
