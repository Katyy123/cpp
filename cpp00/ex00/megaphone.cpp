/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:49:12 by cfiliber          #+#    #+#             */
/*   Updated: 2022/04/12 18:56:26 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

//using namespace std;

int main(void)
{
	char	buff[512];
	std::cout << "Hello World!" << std::endl;
	std::cout << "Input a word: ";
	std::cin >> buff;
	std::cout << "You typed: [" << buff << "]" << std::endl; 
	return 0;
}