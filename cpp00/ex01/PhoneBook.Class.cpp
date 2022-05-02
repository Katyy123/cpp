/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:29:39 by cfiliber          #+#    #+#             */
/*   Updated: 2022/05/02 19:20:43 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	
	//std::cout << "Constructor called" << std::endl;
	return;
}

PhoneBook::~PhoneBook(void) {
	
	//std::cout << "Destructor called" << std::endl;
	return;
}

void	PhoneBook::check_command(std::string buff) {
	
	if (buff == "ADD" || buff == "add")
		this->ft_add();
	else if (buff == "SEARCH" || buff == "search")
		this->ft_search();
	else if (buff == "EXIT" || buff == "exit")
		this->ft_exit();
	else
		std::cout << "\x1b[31m""Error: command not found""\x1b[0m" << std::endl;
}

void	PhoneBook::ft_add(void) {
	
	// std::string name;
	// std::string	last_name;
	// std::string	nickname;
	// std::string phone;
	// std::string secret;
	Contact	contact;
	
	contact.add_contact_fields();

}

void	PhoneBook::ft_search(void) {
	
	
}

void	PhoneBook::ft_exit(void) {
	
	
}
