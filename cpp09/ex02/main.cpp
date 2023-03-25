/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:13:46 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/25 16:20:23 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {

	clock_t 				vector_start, vector_end;
	clock_t 				list_start, list_end;
	double					vector_time;
	double					list_time;
	std::vector<int>		*my_vector = new std::vector<int>;
	std::list<int>			*my_list = new std::list<int>;
	std::vector<int>		input_array;
	
	if (argc < 2) {
		std::cerr << "Error: bad arguments" << std::endl;
		return -1;
	}
	
	vector_start = clock();
	try {
		my_vector = merge_insert_sort(argc - 1, argv + 1, my_vector);
	}
	catch(std::exception & e) {
		std::cerr << "Error: bad input" << std::endl;
	}
	vector_end = clock();

	list_start = clock();
	try {
		my_list = merge_insert_sort(argc - 1, argv + 1, my_list);
	}
	catch(std::exception & e) {
		std::cerr << "Error: bad input" << std::endl;
	}
	list_end = clock();

	//make input array using argv
	for (int i = 1; i < argc; ++i) {
		//num_str = static_cast<std::string>(num_matrix[i]);
		// for (size_t j = 0; j < num_str.length(); ++j) {
		// 	if (all_digits_string.find(num_str[j]) == all_digits_string.npos)
		// 		throw std::exception();
		// }
		// if (ft_is_toobig(num_str) == true)
		// 	throw std::exception();
		// else {
		int num = std::stoi(argv[i]);
		input_array.push_back(num);
	}
	
	vector_time = double(vector_end - vector_start) / double(CLOCKS_PER_SEC);
	list_time = double(list_end - list_start) / double(CLOCKS_PER_SEC);

	print_output(input_array, *my_vector, *my_list, input_array.size(), vector_time, list_time);

	// for (std::vector<int>::const_iterator it = my_vector->begin(); it != my_vector->end(); ++it)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	
	delete my_vector;
	return 0;
}