/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:30:28 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/23 17:11:17 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int solve_expression(std::string const & str) {//, int * result) {

	std::size_t		i;
	//std::string 	num_str;
	//char			sign;
	int				num;
	int				first_operand;
	int				second_operand;
	char			operation;
	//int				nums_count;
	//bool			new_num;
	std::string 	all_digits_str = "0123456789";
	std::stack<int> int_stack;
	int				result;
	
	i = 0;
	//sign = '+';
	num = 0;
	operation = 0;
	//nums_count = 0;
	//new_num = 1;
	result = 0;
	while (i < str.length()) {
		if (str[i] == ' ') {
			//new_num = true;
			i++;
			continue;
		}
		// if ((str[i] == '+' || str[i] == '-') && (i + 1) != str.length() && all_digits_str.find(str[i + 1]) != all_digits_str.npos) {
		// 	sign = str[i];
		// 	i++;
		// 	continue;
		// }
		if ((str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') && int_stack.size() >= 2) {
			operation = str[i];
			//std::cout << "int_stack.top(): " << int_stack.top() << std::endl;
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
		// else if ((str[i] == '+' || str[i] == '-') && int_stack.size() >= 2) {
		// 	operation = str[i];
			
		// 	i++;
		// 	continue;
		// }
		// else if ((str[i] == '+' || str[i] == '-')) {
		// 	std::cerr << "Error: bad input" << std::endl;
		// 	return -1;
		// }
		// if ((str[i] == '*' || str[i] == '/') && int_stack.size() >= 2) {
		// 	operation = str[i];
		// 	i++;
		// 	continue;
		// }
		// else if (str[i] == '*' || str[i] == '/') {
		// 	std::cerr << "Error: bad input" << std::endl;
		// 	return -1;
		// }
		if (all_digits_str.find(str[i]) != all_digits_str.npos) {
			//num_str += str[i];
			// i++;
		// }
		// while (all_digits_str.find(str[i]) != all_digits_str.npos) {
		// 	num_str += str[i];
		// 	i++;
		// }
		//if (num_str.length() > 0) {
			//controlla che il numero non sia troppo grande, poi convertilo in int con stoi e push into the stack
			// if (ft_is_toobig(num_str) == true) {
			// 	std::cerr << "Error: too large number" << std::endl;
			// 	return -1;
			// }
			//else {
			num = ft_ctoi(str[i]);
			// if (sign == '-')
			// 	num *= -1;
			//}
			//std::cout << "num: " << num << std::endl;
			int_stack.push(num);
			//nums_count++;
			//num_str.erase();
			i++;
			continue;
		}
		
	}
	if (int_stack.size() != 1) {
		std::cerr << "Error: bad input" << std::endl;
		return -1;
	}
	// if (nums_count >= 10) {
	// 	std::cerr << "Error: numbers should be less than 10" << std::endl;
	// 	return -1;
	// }
	//*result = int_stack.top();
	result = int_stack.top();
	std::cout << result << std::endl;
	return 0;
}