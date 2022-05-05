/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:24:09 by cfiliber          #+#    #+#             */
/*   Updated: 2022/05/05 15:10:50 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp" 

// void	check_command(PhoneBook phonebook, std::string buff) { //check if can be put inside the class

// 	if (buff == "ADD" || buff == "add")
// 		phonebook.ft_add();
// 	else if (buff == "SEARCH" || buff == "search")
// 		phonebook.ft_search();
// 	else if (buff == "EXIT" || buff == "exit")
// 		phonebook.ft_exit();
// 	else
// 		std::cout << "Error: command not found" << std::endl;
// }

int main(){

	PhoneBook	phonebook;
	std::string	buff;
	//Contact		contact;

	std::cout << "\x1b[35m""Welcome to My Awesome PhoneBook!""\x1b[0m" << std::endl;
	while (1) {
	std::cout << std::endl;
	std::cout << "Type ""\x1b[36m""ADD""\x1b[0m"" if you want to save a new contact." << std::endl;
	std::cout << "Type ""\x1b[36m""SEARCH""\x1b[0m"" if you want to display a specific contact." << std::endl;
	std::cout << "Type ""\x1b[36m""EXIT""\x1b[0m"" if you want to quit the program ";
	std::cout << "(""\x1b[33m""WARNING""\x1b[0m"": your contacts will be lost!)." << std::endl;
	std::cout << std::endl;
	//add an infinite loop
	std::cin >> buff;
	
	phonebook.check_command(buff);
	
	}
	return 0;
}