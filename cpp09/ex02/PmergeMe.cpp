/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catia <catia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:13:52 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/27 05:18:35 by catia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	print_output(std::vector<int> const & input_vector, std::vector<int> const & sorted_vector,
			std::list<int> const & sorted_list, size_t elem_number, double vector_time, double list_time) {
	
	std::cout << "Before: ";
	for (std::vector<int>::const_iterator it = input_vector.begin(); it != input_vector.end(); ++it)
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


/* ------------------------- VECTOR ------------------------- */


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
	
    std::vector<int> *left_vec = new std::vector<int>;
	std::vector<int> *right_vec = new std::vector<int>;
	int left_vec_elems = mid - left + 1;
    int right_vec_elems = right - mid;
	int left_vec_index = 0;
    int right_vec_index = 0;
    int merged_vec_index = left;
  
    // Copy data to temp vectors left_vec and right_vec
    for (int i = 0; i < left_vec_elems; i++)
		left_vec->push_back((*my_vector)[left + i]);
    for (int j = 0; j < right_vec_elems; j++)
        right_vec->push_back((*my_vector)[mid + 1 + j]);

	// Merge the temp vectors back into my_vector
    while (left_vec_index < left_vec_elems && right_vec_index < right_vec_elems) {
        if ((*left_vec)[left_vec_index] <= (*right_vec)[right_vec_index]) {
            (*my_vector)[merged_vec_index] = (*left_vec)[left_vec_index];
            left_vec_index++;
        }
        else {
            (*my_vector)[merged_vec_index] = (*right_vec)[right_vec_index];
            right_vec_index++;
        }
        merged_vec_index++;
    }
    // Copy the remaining elements of left_vec, if there are any
    while (left_vec_index < left_vec_elems) {
        (*my_vector)[merged_vec_index] = (*left_vec)[left_vec_index];
        left_vec_index++;
        merged_vec_index++;
    }
    // Copy the remaining elements of right_vec, if there are any
    while (right_vec_index < right_vec_elems) {
        (*my_vector)[merged_vec_index] = (*right_vec)[right_vec_index];
        right_vec_index++;
        merged_vec_index++;
    }
	
    delete left_vec;
    delete right_vec;
}

void merge_sort(std::vector<int> * my_vector, int const begin, int const end) {
	
	int	threshold = 15;
	int mid;
	
	if (begin >= end)
		return;
	if (end - begin + 1 <= threshold)
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

	return my_vector;
}


/* ------------------------- LIST ------------------------- */


void insertion_sort(std::list<int> * my_list, int begin, int end) {

	std::list<int>::iterator it;
	std::list<int>::iterator jt;
	int i;
	int key;
	int j;
	
	it = ft_next(my_list->begin(), begin + 1);
	for (i = begin + 1; i <= end; i++) {
		key = *it;
		j = i - 1;
		jt = ft_prev(it, 1);
		while (j >= begin && *jt > key) {
			*ft_next(jt, 1) = *jt;
			j--;
			jt--;
		}
		*ft_next(jt, 1) = key;
		it++;
	}
}

void merge(std::list<int> * my_list, int const left, int const mid, int const right) {
	
	std::list<int>::iterator it_left;
	std::list<int>::iterator it_mid_plus_1;
	std::list<int> *left_list = new std::list<int>;
	std::list<int> *right_list = new std::list<int>;
	std::list<int>::iterator it_left_lst;
	std::list<int>::iterator it_right_lst;
	std::list<int>::iterator it_merged_lst;
	int left_list_elems = mid - left + 1;
    int right_list_elems = right - mid;
	int left_list_index = 0;
    int right_list_index = 0;
    int merged_list_index = left;
  
    // Copy data to temp lists left_list and right_list
	it_left = ft_next(my_list->begin(), left);
    for (int i = 0; i < left_list_elems; i++) {
		left_list->push_back(*it_left);
		it_left++;
	}
	it_mid_plus_1 = ft_next(my_list->begin(), mid + 1);
    for (int j = 0; j < right_list_elems; j++) {
		right_list->push_back(*it_mid_plus_1);
		it_mid_plus_1++;
	}

	// Merge the temp lists back into my_list
	it_left_lst = left_list->begin();
	it_right_lst = right_list->begin();
	it_merged_lst = ft_next(my_list->begin(), left);
    while (left_list_index < left_list_elems && right_list_index < right_list_elems) {
		if (*it_left_lst <= *it_right_lst) {
            *it_merged_lst = *it_left_lst;
            left_list_index++;
			it_left_lst++;
        }
        else {
			*it_merged_lst = *it_right_lst;
            right_list_index++;
			it_right_lst++;
        }
        merged_list_index++;
		it_merged_lst++;
    }
    // Copy the remaining elements of left_vec, if there are any
    while (left_list_index < left_list_elems) {
        *it_merged_lst = *it_left_lst;
        left_list_index++;
        merged_list_index++;
		it_left_lst++;
		it_merged_lst++;
    }
    // Copy the remaining elements of right_vec, if there are any
    while (right_list_index < right_list_elems) {
        *it_merged_lst = *it_right_lst;
        right_list_index++;
        merged_list_index++;
		it_right_lst++;
		it_merged_lst++;
    }
	
    delete left_list;
    delete right_list;
}

void merge_sort(std::list<int> * my_list, int const begin, int const end) {
	
	int	threshold = 15;
	int mid;
	
	if (begin >= end)
		return;
	if (end - begin + 1 <= threshold)
		insertion_sort(my_list, begin, end);
	else {
		mid = begin + (end - begin) / 2;
		merge_sort(my_list, begin, mid);
		merge_sort(my_list, mid + 1, end);
		merge(my_list, begin, mid, end);
	}
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

	merge_sort(my_list, 0, my_list->size() - 1);

	return my_list;
}