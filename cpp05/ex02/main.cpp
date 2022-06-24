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

int main() {

    ShrubberyCreationForm form_1("home");
    RobotomyRequestForm form_2("human");
    PresidentialPardonForm form_3("Pinco Pallino");
    std::cout << std::endl;

    Bureaucrat michela("Michela", 2);
    Bureaucrat luca("Luca", 147);
    
    std::cout << form_1;
    std::cout << form_2;
    std::cout << form_3;
    
    std::cout << michela;
    std::cout << luca;
    std::cout << std::endl;

    michela.executeForm(form_1);
    form_1.beSigned(michela);
    michela.executeForm(form_1);
    luca.executeForm(form_1);
    std::cout << std::endl;

    michela.executeForm(form_2);
    form_2.beSigned(michela);
    michela.executeForm(form_2);
    luca.executeForm(form_2);
    std::cout << std::endl;

    michela.executeForm(form_3);
    form_3.beSigned(michela);
    michela.executeForm(form_3);
    luca.executeForm(form_3);
    std::cout << std::endl;

    return 0;
}
