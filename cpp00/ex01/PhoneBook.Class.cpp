/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:29:39 by cfiliber          #+#    #+#             */
/*   Updated: 2022/05/05 17:06:39 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _index(0) {
	
	return;
}

PhoneBook::~PhoneBook(void) {
	
	return;
}

void	PhoneBook::check_command(std::string buff) {
	
	if (buff == "ADD" || buff == "add")
		this->_ft_add();
	else if (buff == "SEARCH" || buff == "search")
		this->_ft_search();
	else if (buff == "EXIT" || buff == "exit")
		this->_ft_exit();
	else
		std::cout << "\x1b[31m""Error: command not found""\x1b[0m" << std::endl;
}

// int		PhoneBook::_contacts_counter(void) const {
	
// 	//for (int i = 0; this->_arr_contacts[i] != NULL ; i++)
// }

void	PhoneBook::_update_contacts_arr(const Contact& contact) {

	this->_arr_contacts[_index % MAX_CONTACTS] = contact;
	this->_index += 1;
}

void	PhoneBook::_ft_add(void) {
	
	// std::string name;
	// std::string	last_name;
	// std::string	nickname;
	// std::string phone;
	// std::string secret;
	Contact	contact;
	
	contact.add_contact_fields();
	this->_update_contacts_arr(contact);
	std::cout << std::endl;
	std::cout << "\x1b[3m""\x1b[32m""Your contact has been saved""\x1b[0m" << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < _index; i++)
		std::cout << this->_arr_contacts[i].get_name() << std::endl;
	std::cout << "\x1b[3m""\x1b[32m""Your contact has been saved""\x1b[0m" << std::endl;
}

void	PhoneBook::_ft_search(void) {
	
	
}

void	PhoneBook::_ft_exit(void) {
	
	exit(EXIT_SUCCESS);
}
