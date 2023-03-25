/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:13:52 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/25 20:12:25 by cfiliber         ###   ########.fr       */
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

void insertion_sort(std::vector<int> * my_vector, int begin, int end) {

	int i;
	int key;
	int j;
	
	for (i = begin + 1; i <= end; i++) {
		key = (*my_vector)[i];
		j = i - 1;
		while (j >= begin && (*my_vector)[j] > key) {
			(*my_vector)[j + 1] = (*my_vector)[j];
			j--;
		}
		(*my_vector)[j + 1] = key;
	}
}

void merge(std::vector<int> * my_vector, int const left, int const mid, int const right) {
	
	int left_arr_elems = mid - left + 1;
    int right_arr_elems = right - mid;
  
    // Create temp arrays
    std::vector<int> *left_arr = new std::vector<int>[left_arr_elems];
	std::vector<int> *right_arr = new std::vector<int>[right_arr_elems];
  
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < left_arr_elems; i++)
        (*left_arr)[i] = (*my_vector)[left + i];
    for (int j = 0; j < right_arr_elems; j++)
        (*right_arr)[j] = (*my_vector)[mid + 1 + j];
  
    int left_arr_index = 0; // Initial index of first sub-array
    int right_arr_index = 0; // Initial index of second sub-array
    int merged_arr_index = left; // Initial index of merged array
  
    // Merge the temp arrays back into array[left..right]
    while (left_arr_index < left_arr_elems && right_arr_index < right_arr_elems) {
        if ((*left_arr)[left_arr_index] <= (*right_arr)[right_arr_index]) {
            (*my_vector)[merged_arr_index] = (*left_arr)[left_arr_index];
            left_arr_index++;
        }
        else {
            (*my_vector)[merged_arr_index] = (*right_arr)[right_arr_index];
            right_arr_index++;
        }
        merged_arr_index++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (left_arr_index < left_arr_elems) {
        (*my_vector)[merged_arr_index] = (*left_arr)[left_arr_index];
        left_arr_index++;
        merged_arr_index++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (right_arr_index < right_arr_elems) {
        (*my_vector)[merged_arr_index] = (*right_arr)[right_arr_index];
        right_arr_index++;
        merged_arr_index++;
    }
    delete[] left_arr;
    delete[] right_arr;
}

void merge_sort(std::vector<int> * my_vector, int const begin, int const end) {
	
	int	threshold = 20;
	int mid;
	
	if (begin >= end)
		return;
	if (end - begin <= threshold)
		insertion_sort(my_vector, begin, end);
	else {
		mid = begin + (end - begin) / 2;
		merge_sort(my_vector, begin, mid);
		merge_sort(my_vector, mid + 1, end);
		merge(my_vector, begin, mid, end);
	}
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

	merge_sort (my_vector, 0, my_vector->size() - 1);
	
	// for (std::vector<int>::const_iterator it = my_vector->begin(); it != my_vector->end(); ++it)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;

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
	// for (std::list<int>::const_iterator it = my_list->begin(); it != my_list->end(); ++it)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;

	return my_list;
}