/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catia <catia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:13:46 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/27 04:51:11 by catia            ###   ########.fr       */
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
		delete my_vector;
		delete my_list;
		return -1;
	}
	
	vector_start = clock();
	try {
		my_vector = merge_insert_sort(argc - 1, argv + 1, my_vector);
	}
	catch(std::exception & e) {
		std::cerr << "Error: bad input" << std::endl;
		delete my_vector;
		delete my_list;
		return -1;
	}
	vector_end = clock();

	list_start = clock();
	try {
		my_list = merge_insert_sort(argc - 1, argv + 1, my_list);
	}
	catch(std::exception & e) {
		std::cerr << "Error: bad input" << std::endl;
		delete my_vector;
		delete my_list;
		return -1;
	}
	list_end = clock();

	for (int i = 1; i < argc; ++i) {
		std::string str(argv[i]);
		int num = ft_stoi(str);
		input_vector.push_back(num);
	}
	
	vector_time = double(vector_end - vector_start) / double(CLOCKS_PER_SEC);
	list_time = double(list_end - list_start) / double(CLOCKS_PER_SEC);

	print_output(input_vector, *my_vector, *my_list, input_vector.size(), vector_time, list_time);


	//check if my_vector and my_list are sorted
	std::cout << std::endl;
	bool vector_is_sorted = true;
	bool list_is_sorted = true;
	for (std::vector<int>::const_iterator it = my_vector->begin(); it != my_vector->end() - 1; it++) {
		if (*it > *(it + 1))
			vector_is_sorted = false;
	}
	std::cout << std::boolalpha << "my_vector is sorted: " << vector_is_sorted << std::endl;
	for (std::list<int>::iterator it = my_list->begin(); it != ft_prev(my_list->end(), 1); it++) {
		std::list<int>::iterator it_next = ft_next(it, 1);
		if (*it > *it_next)
			list_is_sorted = false;
	}
	std::cout << std::boolalpha << "my_list is sorted: " << list_is_sorted << std::endl;
	bool vector_list_are_equal = true;
	std::list<int>::iterator it_list = my_list->begin();
	for (size_t i = 0; i < my_vector->size() && my_vector->size() == my_list->size(); i++) {
		if ((*my_vector)[i] != *it_list) {
			vector_list_are_equal = false;
			std::cout << std::endl << "--- i --- : " << i << std::endl << std::endl;
		}
		it_list++;
	}
	std::cout << "input_vector size: " << input_vector.size() << std::endl;
	std::cout << "my_vector size: " << my_vector->size() << std::endl;
	std::cout << "my_list size: " << my_list->size() << std::endl;
	std::cout << std::boolalpha << "my_list and my_vector are equal: " << vector_list_are_equal << std::endl;
	// for (size_t i = 0; i < input_vector.size(); i++) {
		
	// }
		

	
	delete my_vector;
	delete my_list;
	return 0;
}