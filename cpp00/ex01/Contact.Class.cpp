/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:28:49 by cfiliber          #+#    #+#             */
/*   Updated: 2022/04/30 19:21:17 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact(void) {
	
	//std::cout << "Constructor called" << std::endl;
	return;
}

Contact::~Contact(void) {
	
	//std::cout << "Destructor called" << std::endl;
	return;
}

// void	Contact::ft_add(void) {
	
// 	// std::string name;
// 	// std::string	last_name;
// 	// std::string	nickname;
// 	// std::string phone;
// 	// std::string secret;
	
// 	std::cout << std::endl;
// 	std::cout << "Type the info of the contanct you want to add" << std::endl;
// 	std::cout << std::endl;
// 	std::cout << "First name: ";
// 	std::cin >> this->_name;
// 	// if (name[0] == '\n') {
// 	// 	name.erase();
// 	// 	std::cout << "\x1b[31m""Error: first name not valid""\x1b[0m" << std::endl;
// 	// 	std::cout << std::endl;
// 	// 	std::cout << "First name: ";
// 	// 	std::cin >> name;
// 	// }
// 	//while (std::all_of(name.begin(), name.end(), [](unsigned char c){ return !std::isprint(c); })) {
// 	for (unsigned long i = 0; i < name.length() || name.empty(); i++) {
// 		if (!std::isprint(name[i]) || name.empty()) {
// 			name.erase();
// 			std::cout << "\x1b[31m""Error: first name not valid""\x1b[0m" << std::endl;
// 			std::cout << std::endl;
// 			std::cout << "First name: ";
// 			std::cin >> name;
// 			i = 0;
// 		}
// 	}
// 	std::cout << "Last name: ";
// 	std::cin >> last_name;
// 	for (unsigned long i = 0; i < last_name.length() || last_name.empty(); i++) {
// 		if (!std::isprint(last_name[i]) || last_name.empty()) {
// 			last_name.erase();
// 			std::cout << "\x1b[31m""Error: last name not valid""\x1b[0m" << std::endl;
// 			std::cout << std::endl;
// 			std::cout << "Last name: ";
// 			std::cin >> last_name;
// 			i = 0;
// 		}
// 	}
// 	//std::cout << name << std::endl;
// }

void	add_contact_fields(void) {
	
	
}