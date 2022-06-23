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

    // Form form_1("form_1", 42, 30);
    // Form form_2("form_2", 0, 0);
    // Form form_3("form_3", 151, 167);
    // Form form_4("form_4", 4, 102);
    std::cout << std::endl;

    Bureaucrat michela("Michela", 40);
    Bureaucrat luca("Luca", 51);
    
    // std::cout << form_1;
    // std::cout << form_4;

    std::cout << michela;
    std::cout << luca;
    std::cout << std::endl;

    // form_1.beSigned(michela);
    // form_1.beSigned(luca);
    // form_4.beSigned(luca);

    // std::cout << form_1;
    // std::cout << form_4;

    return 0;
}
