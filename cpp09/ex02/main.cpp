/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catia <catia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:13:46 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/27 05:26:29 by catia            ###   ########.fr       */
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


	/* ---------- OTHER TESTS ---------- */
	
	// std::cout << std::endl;
	// bool vector_is_sorted = true;
	// bool list_is_sorted = true;
	// for (std::vector<int>::const_iterator it = my_vector->begin(); it != my_vector->end() - 1; it++) {
	// 	if (*it > *(it + 1))
	// 		vector_is_sorted = false;
	// }
	// std::cout << std::boolalpha << "my_vector is sorted: " << vector_is_sorted << std::endl;
	// for (std::list<int>::iterator it = my_list->begin(); it != ft_prev(my_list->end(), 1); it++) {
	// 	std::list<int>::iterator it_next = ft_next(it, 1);
	// 	if (*it > *it_next)
	// 		list_is_sorted = false;
	// }
	// std::cout << std::boolalpha << "my_list is sorted: " << list_is_sorted << std::endl;
	// bool vector_list_are_equal = true;
	// std::list<int>::iterator it_list = my_list->begin();
	// for (size_t i = 0; i < my_vector->size() && my_vector->size() == my_list->size(); i++) {
	// 	if ((*my_vector)[i] != *it_list) {
	// 		vector_list_are_equal = false;
	// 		std::cout << std::endl << "--- i --- : " << i << std::endl << std::endl;
	// 	}
	// 	it_list++;
	// }
	// std::cout << "input_vector size: " << input_vector.size() << std::endl;
	// std::cout << "my_vector size: " << my_vector->size() << std::endl;
	// std::cout << "my_list size: " << my_list->size() << std::endl;
	// bool elem_is_present = false;
	// bool all_elem_are_present = true;
	// for (size_t i = 0; i < input_vector.size(); i++) {
	// 	for (size_t j = 0; j < my_vector->size(); j++) {
	// 		if (input_vector[i] == (*my_vector)[j])
	// 			elem_is_present = true;
	// 	}
	// 	if (elem_is_present == false)
	// 		all_elem_are_present = false;
	// }
	// std::cout << std::boolalpha << "All elements in input_vector are present in my_vector: " << all_elem_are_present << std::endl;
	// bool elem_is_present_2 = false;
	// bool all_elem_are_present_2 = true;
	// for (size_t i = 0; i < my_vector->size(); i++) {
	// 	for (size_t j = 0; j < input_vector.size(); j++) {
	// 		if ((*my_vector)[i] == input_vector[j])
	// 			elem_is_present_2 = true;
	// 	}
	// 	if (elem_is_present_2 == false)
	// 		all_elem_are_present_2 = false;
	// }
	// std::cout << std::boolalpha << "All elements in my_vector are present in input_vector: " << all_elem_are_present_2 << std::endl;
	// std::cout << std::boolalpha << "my_list and my_vector are equal: " << vector_list_are_equal << std::endl;
	
	/* ---------------------------- */

	
	delete my_vector;
	delete my_list;
	return 0;
}