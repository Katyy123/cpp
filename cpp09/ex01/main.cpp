/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:30:31 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/22 18:27:12 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

int main(int argc, char **argv) {

	std::string str;
	int * 		result;

	if (argc != 2)
		std::cerr << "Error: bad arguments" << std::endl;
	str = static_cast<std::string>(argv[1]);
	if (str.find_first_not_of("0123456789+-*/ ")){
		std::cerr << "Error" << std::endl;
		return 1;
	}
	
	if (solve_expression(str, result) == -1)
		return 2;
	
	std::cout << result << std::endl;
	
	return 0;
}