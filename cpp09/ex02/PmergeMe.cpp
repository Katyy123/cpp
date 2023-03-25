/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:13:52 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/25 16:26:02 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	print_output(std::vector<int> const & input_array, std::vector<int> const & sorted_vector,
			std::list<int> const & sorted_list, size_t elem_number, double vector_time, double list_time) {
	
	std::cout << "Before: ";
	for (std::vector<int>::const_iterator it = input_array.begin(); it != input_array.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "After with std::vector: ";
	for (std::vector<int>::const_iterator it = sorted_vector.begin(); it != sorted_vector.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "After with std::list:   ";
	for (std::list<int>::const_iterator it = sorted_list.begin(); it != sorted_list.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << elem_number << " elements with std::vector: "
			<< std::fixed << vector_time << std::setprecision(6) << " s" << std::endl; 
	std::cout << "Time to process a range of " << elem_number << " elements with std::list:   "
			<< std::fixed << list_time << std::setprecision(6) << " s" << std::endl;
}

std::vector<int> * merge_insert_sort(int elem_number, char **num_matrix, std::vector<int> * my_vector) {

	int					num;
	std::string			num_str;
	std::string			all_digits_string("0123456789");

	for (int i = 0; i < elem_number; ++i) {
		num_str = static_cast<std::string>(num_matrix[i]);
		for (size_t j = 0; j < num_str.length(); ++j) {
			if (all_digits_string.find(num_str[j]) == all_digits_string.npos)
				throw std::exception();
		}
		if (ft_is_toobig(num_str) == true)
			throw std::exception();
		else {
			num = ft_stoi(num_str);
			my_vector->push_back(num);
		}
	}
	for (std::vector<int>::const_iterator it = my_vector->begin(); it != my_vector->end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	return my_vector;
}

std::list<int> * merge_insert_sort(int elem_number, char **num_matrix, std::list<int> * my_list) {

	int					num;
	std::string			num_str;
	std::string			all_digits_string("0123456789");

	for (int i = 0; i < elem_number; ++i) {
		num_str = static_cast<std::string>(num_matrix[i]);
		for (size_t j = 0; j < num_str.length(); ++j) {
			if (all_digits_string.find(num_str[j]) == all_digits_string.npos)
				throw std::exception();
		}
		if (ft_is_toobig(num_str) == true)
			throw std::exception();
		else {
			num = ft_stoi(num_str);
			my_list->push_back(num);
		}
	}
	for (std::list<int>::const_iterator it = my_list->begin(); it != my_list->end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	return my_list;
}