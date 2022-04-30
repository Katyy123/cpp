/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:29:39 by cfiliber          #+#    #+#             */
/*   Updated: 2022/04/30 19:19:32 by cfiliber         ###   ########.fr       */
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

void	check_add_command(std::string *buff) {
	
	for (unsigned long i = 0; i < buff->length() || buff->empty(); i++) {
		if (!std::isprint(*buff[i]) || buff->empty()) {
			buff->erase();
			std::cout << "\x1b[31m""Error: first name not valid""\x1b[0m" << std::endl;
			std::cout << std::endl;
			std::cout << "First name: ";
			std::cin >> *buff;
			i = 0;
		}
	}
}

void	PhoneBook::ft_add(void) {
	
	// std::string name;
	// std::string	last_name;
	// std::string	nickname;
	// std::string phone;
	// std::string secret;
	
	std::cout << std::endl;
	std::cout << "Type the info of the contanct you want to add" << std::endl;
	std::cout << std::endl;
	std::cout << "First name: ";
	std::cin >> this->_arr_contacts->_name;
	// if (name[0] == '\n') {
	// 	name.erase();
	// 	std::cout << "\x1b[31m""Error: first name not valid""\x1b[0m" << std::endl;
	// 	std::cout << std::endl;
	// 	std::cout << "First name: ";
	// 	std::cin >> name;
	// }
	//while (std::all_of(name.begin(), name.end(), [](unsigned char c){ return !std::isprint(c); })) {
	for (unsigned long i = 0; i < name.length() || name.empty(); i++) {
		if (!std::isprint(name[i]) || name.empty()) {
			name.erase();
			std::cout << "\x1b[31m""Error: first name not valid""\x1b[0m" << std::endl;
			std::cout << std::endl;
			std::cout << "First name: ";
			std::cin >> name;
			i = 0;
		}
	}
	std::cout << "Last name: ";
	std::cin >> last_name;
	for (unsigned long i = 0; i < last_name.length() || last_name.empty(); i++) {
		if (!std::isprint(last_name[i]) || last_name.empty()) {
			last_name.erase();
			std::cout << "\x1b[31m""Error: last name not valid""\x1b[0m" << std::endl;
			std::cout << std::endl;
			std::cout << "Last name: ";
			std::cin >> last_name;
			i = 0;
		}
	}
	//std::cout << name << std::endl;
}

void	PhoneBook::ft_search(void) {
	
	
}

void	PhoneBook::ft_exit(void) {
	
	
}
