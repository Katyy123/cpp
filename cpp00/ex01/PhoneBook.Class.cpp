/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:29:39 by cfiliber          #+#    #+#             */
/*   Updated: 2022/04/29 19:32:13 by cfiliber         ###   ########.fr       */
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
		std::cout << "Error: command not found" << std::endl;
}

void	PhoneBook::ft_add(void) {
	
	std::cout << "First name: ";
	
}

void	PhoneBook::ft_search(void) {
	
	
}

void	PhoneBook::ft_exit(void) {
	
	
}
