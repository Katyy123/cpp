/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:30:28 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/22 19:25:16 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int solve_expression(std::string const & str, int * result) {

	int				i;
	std::string 	num_str;
	char			sign;
	char			operation;
	//bool			new_num;
	std::string 	all_digits_str = "0123456789";
	std::stack<int> int_stack;
	
	i = 0;
	sign = '+';
	operation = 0;
	//new_num = 1;
	while (i < str.length()) {
		if (str[i] == ' ') {
			//new_num = true;
			i++;
			continue;
		}
		if (str[i] == '+') {
			sign = '+';
		}
		if (str[i] == '-') {
			sign = '-';
		}
		while (all_digits_str.find(str[i]) != all_digits_str.npos) {
			num_str += str[i];
			i++;
		}
		if (num_str.length() > 0) {
			//controlla che il numero non sia troppo grande, poi convertilo in int con stoi e push in to the stack
			if
			
		}
			
	}
	
	return 0;
}