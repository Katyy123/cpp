/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:29:39 by cfiliber          #+#    #+#             */
/*   Updated: 2022/05/08 19:32:30 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _contacts_num(0) {
	
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

void	PhoneBook::_update_contacts_arr(const Contact contact) {

	this->_arr_contacts[this->_contacts_num % MAX_CONTACTS] = contact;
	this->_contacts_num += 1;
}

void	PhoneBook::_ft_add(void) {
	
	Contact	contact;
	
	contact.add_contact_fields();
	this->_update_contacts_arr(contact);
	std::cout << std::endl;
	std::cout << "\x1b[3m""\x1b[32m""Your contact has been saved""\x1b[0m" << std::endl;
	std::cout << std::endl;
}

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

int		PhoneBook::_ft_is_numeric(std::string str) const {

	for (unsigned long i = 0; i < str.length(); i++) {
		if (!std::isdigit(str[i])) {
			std::cout << "\x1b[31m""Error: the index must be a number""\x1b[0m" << std::endl;
			//std::cout << "buff: " << str << std::endl;
			return 0;
		} 
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

int		PhoneBook::_is_not_toobig(std::string str) const {
	
	int	i;
	int	num;
	int	is_toobig;

	num = 0;
	i = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (((2147483647 - (str[i] - 48)) / 10 < num))
			is_toobig = 1;
		else
			is_toobig = 0;
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (is_toobig);
}

void	PhoneBook::_search_specif_contact(void) const {

	std::string	buff;
	//int i;

	std::cout << std::endl;
	std::cout << "Type the index of the contact you want to be displayed: ";
	std::cin >> buff;
	//std::cout << buff;
	while (!this->_ft_is_numeric(buff) || !this->_is_not_toobig(buff))
	if (!this->_ft_is_numeric(buff))
		std::cout << "non numeric" << std::endl;
	// for (i = 0; i < std::to_string(buff).length(); i++) {
	// 	if (!std::isdigit(std::to_string(buff)[i])) {
	// 		std::cout << "\x1b[31m""Error: the index must be a number""\x1b[0m" << std::endl;
	// 		is_numeric = 0;
	// 		break;
	// 	} 
	// }
	// if (is_numeric)
	// if (isdigit(index)index <= this->_contacts_num) {
			
	// }
	// else {
	// 	while (index > )
	// 	std::cout << "\x1b[31m""Wrong index. Type a number between 1 and ";
	// 	std::cout << _contacts_num << "\x1b[0m" << std::endl;
	// }
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

void	PhoneBook::_ft_exit(void) const {
	
	exit(EXIT_SUCCESS);
}
