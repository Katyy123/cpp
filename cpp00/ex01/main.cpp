/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:24:09 by cfiliber          #+#    #+#             */
/*   Updated: 2022/04/28 19:26:52 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.Class.hpp"
#include "Contact.Class.hpp" 

int main(){

	PhoneBook phonebook;

	std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
	std::cout << std::endl;
	std::cout << "Type ADD if you want to save a new contact," << std::endl;
	std::cout << "type SEARCH if you want to display a specific contact" << std::endl;
	std::cout << "or type EXIT if you want to quit the program";
	std::cout << "(WARNING: Your contacts will be lost!)" << std::endl;
	return 0;
}