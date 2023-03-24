/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:13:46 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/24 19:26:02 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {

	clock_t 			vector_start, vector_end;
	clock_t 			list_start, list_end;
	double				vector_time;
	double				list_time;
	std::vector<int>	sorted_vector;
	std::list<int>		sorted_list;
	std::vector<int>	input_array;
	//std::size_t		size;

	//size = static_cast<std::size_t>(argc - 1);
	
	if (argc < 2) {
		std::cerr << "Error: bad arguments" << std::endl;
		return -1;
	}
	
	vector_start = clock();
	try {
		sorted_vector = vector_merge_insert_sort(argc, argv);
	}
	catch(std::exception & e) {
		std::cerr << "Error: bad input" << std::endl;
	}
	vector_end = clock();

	list_start = clock();
	try {
		sorted_list = list_merge_insert_sort(argc, argv);
	}
	catch(std::exception & e) {
		std::cerr << "Error: bad input" << std::endl;
	}
	list_end = clock();

	//make input array using argv
	
	vector_time = double(vector_end - vector_start) / double(CLOCKS_PER_SEC);
	list_time = double(list_end - list_start) / double(CLOCKS_PER_SEC);

	print_output(input_array, sorted_vector, argc - 1, vector_time);
	print_output(input_array, sorted_list, argc - 1, list_time);
	
	return 0;
}