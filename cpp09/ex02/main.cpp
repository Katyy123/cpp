/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:13:46 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/26 21:07:26 by cfiliber         ###   ########.fr       */
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
	std::vector<int>		input_vector;
	
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
		return -1;
	}
	vector_end = clock();

	list_start = clock();
	try {
		my_list = merge_insert_sort(argc - 1, argv + 1, my_list);
	}
	catch(std::exception & e) {
		std::cerr << "Error: bad input" << std::endl;
		return -1;
	}
	list_end = clock();

	//make input array using argv
	for (int i = 1; i < argc; ++i) {
		int num = std::stoi(argv[i]);
		input_vector.push_back(num);
	}
	
	vector_time = double(vector_end - vector_start) / double(CLOCKS_PER_SEC);
	list_time = double(list_end - list_start) / double(CLOCKS_PER_SEC);

	print_output(input_vector, *my_vector, *my_list, input_vector.size(), vector_time, list_time);
	
	delete my_vector;
	delete my_list;
	return 0;
}