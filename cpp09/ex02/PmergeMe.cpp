/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:13:52 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/25 13:36:07 by cfiliber         ###   ########.fr       */
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
	std::cout << "Time to process a range of " << elem_number << " elements with std::vector: " << vector_time << " s" << std::endl; 
	std::cout << "Time to process a range of " << elem_number << " elements with std::list:   " << list_time << " s" << std::endl;
}