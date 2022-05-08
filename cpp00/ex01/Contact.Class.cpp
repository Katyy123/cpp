/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:28:49 by cfiliber          #+#    #+#             */
/*   Updated: 2022/05/08 17:33:00 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact(void) {
	
	return;
}

Contact::~Contact(void) {
	
	return;
}

std::string	Contact::get_name(void) const {

	return this->_name;
}

std::string	Contact::get_last_name(void) const {

	return this->_last_name;
}

std::string	Contact::get_nickname(void) const {

	return this->_nickname;
}

void	Contact::_check_add_command(std::string buff, std::string field) {
	
	for (unsigned long i = 0; i < buff.length() || buff.empty(); i++) {	
		if (!std::isprint(buff[i]) || buff.empty() ||
			(field == "Phone number" && (!std::isdigit(buff[i]) && buff[i] != ' '))) {
			buff.erase();
			std::cout << "\x1b[31m""Error: ";
			std::cout << field;
			std::cout << " not valid""\x1b[0m" << std::endl;
			std::cout << field;
			std::cout << ": ";
			std::getline(std::cin >> std::ws, buff);
			i = 0;
		}
	}
}

void	Contact::add_contact_fields(void) {
	
	std::cout << std::endl;
	std::cout << "\x1b[3m""Type the info of the contact you want to add""\x1b[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "First name: ";
	std::getline(std::cin >> std::ws, this->_name);
	//std::cout << this->_name << std::endl;
	_check_add_command(this->_name, "First name");
	std::cout << "Last name: ";
	std::getline(std::cin >> std::ws, this->_last_name);
	//std::cout << _last_name << std::endl;
	_check_add_command(this->_last_name, "Last name");
	std::cout << "Nickname: ";
	std::getline(std::cin >> std::ws, this->_nickname);
	//std::cout << _nickname << std::endl;
	_check_add_command(this->_nickname, "Nickname");
	std::cout << "Phone number: ";
	std::getline(std::cin >> std::ws, this->_phone);
	//std::cout << _phone << std::endl;
	_check_add_command(this->_phone, "Phone number");
	std::cout << "Darkest secret: ";
	std::getline(std::cin >> std::ws, this->_secret);
	//std::cout << _secret << std::endl;
	_check_add_command(this->_secret, "Darkest secret");
}