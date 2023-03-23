/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:30:28 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/23 17:18:13 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int solve_expression(std::string const & str) {//, int * result) {

	std::size_t		i;
	int				num;
	int				first_operand;
	int				second_operand;
	char			operation;
	std::string 	all_digits_str = "0123456789";
	std::stack<int> int_stack;
	int				result;
	
	i = 0;
	num = 0;
	operation = 0;
	result = 0;
	while (i < str.length()) {
		if (str[i] == ' ') {
			i++;
			continue;
		}
		if ((str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') && int_stack.size() >= 2) {
			operation = str[i];
			second_operand = int_stack.top();
			int_stack.pop();
			first_operand = int_stack.top();
			int_stack.pop();
			if (operation == '+')
				num = first_operand + second_operand;
			else if (operation == '-')
				num = first_operand - second_operand;
			else if (operation == '*')
				num = first_operand * second_operand;
			else if (operation == '/')
				num = first_operand / second_operand;
			int_stack.push(num);
			i++;
			continue;
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
			std::cerr << "Error: bad input" << std::endl;
			return -1;
		}
		if (all_digits_str.find(str[i]) != all_digits_str.npos) {
			num = ft_ctoi(str[i]);
			int_stack.push(num);
			i++;
			continue;
		}
		
	}
	if (int_stack.size() != 1) {
		std::cerr << "Error: bad input" << std::endl;
		return -1;
	}
	result = int_stack.top();
	std::cout << result << std::endl;
	return 0;
}