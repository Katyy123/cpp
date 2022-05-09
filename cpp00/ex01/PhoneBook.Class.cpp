/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:29:39 by cfiliber          #+#    #+#             */
/*   Updated: 2022/05/09 17:47:04 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _contact_index(0), _contacts_num(0) {
	
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



/* ----- ADD FUNCTIONS ----- */

void	PhoneBook::_update_contacts_arr(const Contact contact) {

	this->_arr_contacts[this->_contact_index % MAX_CONTACTS] = contact;
	if (this->_contact_index < 8)
		this->_contacts_num += 1;
	this->_contact_index += 1;
}

void	PhoneBook::_ft_add(void) {
	
	Contact	contact;
	
	contact.add_contact_fields();
	this->_update_contacts_arr(contact);
	std::cout << std::endl;
	std::cout << "\x1b[3m""\x1b[32m""Your contact has been saved""\x1b[0m" << std::endl;
	std::cout << std::endl;
}


/* ----- SEARCH FUNCTIONS ----- */

void	PhoneBook::_print_index(int index) const {

	int index_len;
	int length_diff;

	index_len = std::to_string(index).length();
	length_diff = 10 - index_len;
	while (length_diff > 0) {
		std::cout << " ";
		length_diff--;
	}
	std::cout << index + 1 << "|";
}

void	PhoneBook::_print_name(int index) const {
	
	int length_diff;
	std::string name;
	
	length_diff = 10 - this->_arr_contacts[index].get_name().length();
	if (length_diff >= 0) {
		while (length_diff > 0) {
			std::cout << " ";
			length_diff--;
		}
		std::cout << this->_arr_contacts[index].get_name() << "|";
	}
	else {
		name = this->_arr_contacts[index].get_name();
		while (length_diff <= 0) {
			name.pop_back();
			length_diff++;
		}
		name.push_back('.');
		std::cout << name << "|";
	}
}

void	PhoneBook::_print_last_name(int index) const {

	int length_diff;
	std::string last_name;

	length_diff = 10 - this->_arr_contacts[index].get_last_name().length();
	if (length_diff >= 0) {
		while (length_diff > 0) {
			std::cout << " ";
			length_diff--;
		}
		std::cout << this->_arr_contacts[index].get_last_name() << "|";
	}
	else {
		last_name = this->_arr_contacts[index].get_last_name();
		while (length_diff <= 0) {
			last_name.pop_back();
			length_diff++;
		}
		last_name.push_back('.');
		std::cout << last_name << "|";
	}
}

void	PhoneBook::_print_nickname(int index) const {

	int length_diff;
	std::string nickname;

	length_diff = 10 - this->_arr_contacts[index].get_nickname().length();
	if (length_diff >= 0) {
		while (length_diff > 0) {
			std::cout << " ";
			length_diff--;
		}
		std::cout << this->_arr_contacts[index].get_nickname();
	}
	else {
		nickname = this->_arr_contacts[index].get_nickname();
		while (length_diff <= 0) {
			nickname.pop_back();
			length_diff++;
		}
		nickname.push_back('.');
		std::cout << nickname;
	}
}

void	PhoneBook::_search_specif_contact(void) const {

	std::string	buff;
	int index;

	std::cout << std::endl;
	std::cout << "Type the index of the contact you want to be displayed: ";
	std::getline(std::cin >> std::ws, buff);
	while (!this->_ft_is_numeric(buff) || this->_is_toobig(buff)) {
		std::cout << "\x1b[31m""Wrong index. Type a number from 1 to ";
	 	std::cout << _contacts_num;
		std::cout << ": " << "\x1b[0m";;
		buff.erase();
		std::getline(std::cin >> std::ws, buff);
	}
	index = _ft_atoi(buff);
	std::cout << std::endl;
	std::cout << "First name: " << this->_arr_contacts[index - 1].get_name() << std::endl;
	std::cout << "Last name: " << this->_arr_contacts[index - 1].get_last_name() << std::endl;
	std::cout << "Nickname: " << this->_arr_contacts[index - 1].get_nickname() << std::endl;
	std::cout << "Phone number: " << this->_arr_contacts[index - 1].get_phone() << std::endl;
	std::cout << "Darkest secret: " << this->_arr_contacts[index - 1].get_secret() << std::endl;
}

void	PhoneBook::_ft_search(void) const {
	
	int i;
	
	if (this->_contacts_num == 0) {
		std::cout << std::endl;
		std::cout << "\x1b[3m""\x1b[32m""There are no contacts saved""\x1b[0m" << std::endl;
	}
	else {
		std::cout << std::endl;
		std::cout << "     INDEX|";
		std::cout << "FIRST NAME|";
		std::cout << " LAST NAME|";
		std::cout << "  NICKNAME";
		std::cout << std::endl;
		std::cout << std::endl;
		for (i = 0; i < this->_contacts_num; i++) {
			this->_print_index(i);
			this->_print_name(i);
			this->_print_last_name(i);
			this->_print_nickname(i);
			std::cout << std::endl;
		}
		this->_search_specif_contact();
	}
}


/* ----- EXIT FUNCTION ----- */

void	PhoneBook::_ft_exit(void) const {
	
	exit(EXIT_SUCCESS);
}


/* ----- UTILS ----- */

int		PhoneBook::_ft_is_numeric(std::string str) const {

	for (unsigned long i = 0; i < str.length(); i++) {
		if (!std::isdigit(str[i]))
			return 0;
	}
	return 1;
}

int		PhoneBook::_ft_atoi(std::string str) const {
	
	int	i;
	int	num;

	num = 0;
	i = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num);
}

int		PhoneBook::_is_toobig(std::string str) const {
	
	int	i;
	int	num;
	int	is_toobig;

	num = 0;
	i = 0;
	while (str[i] >= 48 && str[i] <= 57) {
		if (((2147483647 - (str[i] - 48)) / 10 < num))
			is_toobig = 1;
		else
			is_toobig = 0;
		num = num * 10 + (str[i] - 48);
		i++;
	}
	if (is_toobig == 0) {
		if (num > this->_contacts_num)
			is_toobig = 1;
	}
	return (is_toobig);
}