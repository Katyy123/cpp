/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:13:52 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/26 22:45:46 by cfiliber         ###   ########.fr       */
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
	
	// for (int i = begin; i < end; i++) {
    //     // Get the value at index (i+1)
    //     int tempVal = *std::next(my_list->begin(), i + 1);
    //     int j = i + 1;
    //     // Shift elements to the right to make space for the current element
    //     while (j > begin && *std::next(my_list->begin(), j - 1) > tempVal) {
    //         *std::next(my_list->begin(), j) = *std::next(my_list->begin(), j - 1);
    //         j--;
    //     }
    //     // Insert the current element at its correct position
    //     *std::next(my_list->begin(), j) = tempVal;
    // }

	std::list<int>::iterator	it_begin = my_list->begin();
	std::list<int>::iterator	it_end = my_list->end();
	//std::list<int>::reverse_iterator	it_end = my_list->rbegin();//
	std::list<int>::iterator	it;
	std::list<int>::iterator	it_2;
	std::list<int>::iterator	it_3;
	//int							key;
	
	for (int i = 0; i < begin; i++)
		it_begin++;
	// for (int i = my_list->size(); i > end + 1; i--)
	// 	it_end--;
	it_end--;//
	for (int i = my_list->size() - 1; i > end; i--)//
		it_end--;//
	it = it_begin;
	it++;
	
	std::cout << "it_begin: " << *it_begin << std::endl;
	std::cout << "it_end: " << *it_end << std::endl;
	std::cout << "before it_end: " << *std::prev(it_end, 1) << std::endl;
	std::cout << "it: " << *it << std::endl;
	
	while (it != it_end) {
		//key = *it;
		it_2 = it;
		it_2--;
		//std::cout << "key: " << key << std::endl;
		std::cout << "it: " << *it << std::endl;
		std::cout << "it_2: " << *it_2 << std::endl;
		while (it_2 != it_begin && *it_2 > *it) {
			it_3 = it_2;
			it_3++; it_3++;
			std::cout << "--1-- it_2: " << *it_2 << std::endl;
			std::cout << "--1-- it_3: " << *it_3 << std::endl;
			std::cout << "--1-- In position of number " << *it_3 << " put " << *it_2 << std::endl;
			if (it_3 != my_list->begin())
				it_3 = my_list->insert(it_3, *it_2);
			else
				my_list->push_front(*it_2);
			it_2 = my_list->erase(it_2);
			it_2--;
		}
		if (it_2 == it_begin && *it_2 > *it) {
			it_3 = it_2;
			it_3++; it_3++;
			std::cout << "--2-- it_2: " << *it_2 << std::endl;
			std::cout << "--2-- it_3: " << *it_3 << std::endl;
			std::cout << "--2-- In position of number " << *it_3 << " put " << *it_2 << std::endl;
			if (it_3 != my_list->begin())
				it_3 = my_list->insert(it_3, *it_2);
			else
				my_list->push_front(*it_2);
			//std::list<int>::iterator it_4;
			it_2 = my_list->erase(it_2);
			it_2--;
		}
		// it_3 = it_2;
		// //std::cout << *it_3 << std::endl;
		// it_3++; it_3++;
		// std::cout << "--3-- it_2: " << *it_2 << std::endl;
		// std::cout << "--3-- it_3: " << *it_3 << std::endl;
		// std::cout << "--3-- In position of number " << *it_3 << " put " << *it << std::endl;
		// it_3 = my_list->insert(it_3, *it);
		// it = my_list->erase(it);
		it++;
	}
	if (it == it_end) {
		//key = *it;
		it_2 = it;
		it_2--;
		//std::cout << "--4-- key: " << key << std::endl;
		std::cout << "--4-- it: " << *it << std::endl;
		std::cout << "--4-- it_2: " << *it_2 << std::endl;
		while (it_2 != it_begin && *it_2 > *it) {
			it_3 = it_2;
			it_3++; it_3++;
			std::cout << "--5-- it_2: " << *it_2 << std::endl;
			std::cout << "--5-- it_3: " << *it_3 << std::endl;
			std::cout << "--5-- In position of number " << *it_3 << " put " << *it_2 << std::endl;
			if (it_3 != my_list->begin())
				it_3 = my_list->insert(it_3, *it_2);
			else
				my_list->push_front(*it_2);
			it_2 = my_list->erase(it_2);
			it_2--;
		}
		if (it_2 == it_begin && *it_2 > *it) {
			it_3 = it_2;
			it_3++; it_3++;
			std::cout << "--6-- it_2: " << *it_2 << std::endl;
			std::cout << "--6-- it_3: " << *it_3 << std::endl;
			std::cout << "--6-- In position of number " << *it_3 << " put " << *it_2 << std::endl;
			if (it_3 != my_list->begin())
				it_3 = my_list->insert(it_3, *it_2);
			else
				my_list->push_front(*it_2);
			//std::list<int>::iterator it_4;
			it_2 = my_list->erase(it_2);
			it_2--;
		}
		// it_3 = it_2;
		// //std::cout << *it_3 << std::endl;
		// it_3++; it_3++;
		// std::cout << "--7-- it_2: " << *it_2 << std::endl;
		// std::cout << "--7-- it_3: " << *it_3 << std::endl;
		// std::cout << "--7-- In position of number " << *it_3 << " put " << key << std::endl;
		// it_3 = my_list->insert(it_3, key);
		// it = my_list->erase(it);
		// it++;
	}
	
	// while (it != it_end) {
	// 	key = *it;
	// 	it_2 = it;
	// 	it_2--;
	// 	std::cout << "key: " << key << std::endl;
	// 	std::cout << "it: " << *it << std::endl;
	// 	std::cout << "it_2: " << *it_2 << std::endl;
	// 	while (it_2 != it_begin && *it_2 > key) {
	// 		it_3 = it_2;
	// 		it_3++;
	// 		std::cout << "--1-- it_2: " << *it_2 << std::endl;
	// 		std::cout << "--1-- it_3: " << *it_3 << std::endl;
	// 		std::cout << "--1-- In position of number " << *it_3 << " put " << *it_2 << std::endl;
	// 		my_list->insert(it_3, *it_2);
	// 		it_2 = my_list->erase(it_2);
	// 		it_2--;
	// 	}
	// 	if (it_2 == it_begin && *it_2 > key) {
	// 		it_3 = it_2;
	// 		it_3++;
	// 		std::cout << "--2-- it_2: " << *it_2 << std::endl;
	// 		std::cout << "--2-- it_3: " << *it_3 << std::endl;
	// 		std::cout << "--2-- In position of number " << *it_3 << " put " << *it_2 << std::endl;
	// 		my_list->insert(it_3, *it_2);
	// 		//std::list<int>::iterator it_4;
	// 		it_2 = my_list->erase(it_2);
	// 		it_2--;
	// 	}
	// 	it_3 = it_2;
	// 	//std::cout << *it_3 << std::endl;
	// 	it_3++;
	// 	std::cout << "--3-- it_2: " << *it_2 << std::endl;
	// 	std::cout << "--3-- it_3: " << *it_3 << std::endl;
	// 	std::cout << "--3-- In position of number " << *it_3 << " put " << key << std::endl;
	// 	my_list->insert(it_3, key);
	// 	it = my_list->erase(it);
	// 	it++;
	// }
	// if (it == it_end) {
	// 	key = *it;
	// 	it_2 = it;
	// 	it_2--;
	// 	std::cout << "--4-- key: " << key << std::endl;
	// 	std::cout << "--4-- it: " << *it << std::endl;
	// 	std::cout << "--4-- it_2: " << *it_2 << std::endl;
	// 	while (it_2 != it_begin && *it_2 > key) {
	// 		it_3 = it_2;
	// 		it_3++;
	// 		std::cout << "--5-- it_2: " << *it_2 << std::endl;
	// 		std::cout << "--5-- it_3: " << *it_3 << std::endl;
	// 		std::cout << "--5-- In position of number " << *it_3 << " put " << *it_2 << std::endl;
	// 		my_list->insert(it_3, *it_2);
	// 		it_2 = my_list->erase(it_2);
	// 		it_2--;
	// 	}
	// 	if (it_2 == it_begin && *it_2 > key) {
	// 		it_3 = it_2;
	// 		it_3++;
	// 		std::cout << "--6-- it_2: " << *it_2 << std::endl;
	// 		std::cout << "--6-- it_3: " << *it_3 << std::endl;
	// 		std::cout << "--6-- In position of number " << *it_3 << " put " << *it_2 << std::endl;
	// 		my_list->insert(it_3, *it_2);
	// 		//std::list<int>::iterator it_4;
	// 		it_2 = my_list->erase(it_2);
	// 		it_2--;
	// 	}
	// 	it_3 = it_2;
	// 	//std::cout << *it_3 << std::endl;
	// 	it_3++;
	// 	std::cout << "--7-- it_2: " << *it_2 << std::endl;
	// 	std::cout << "--7-- it_3: " << *it_3 << std::endl;
	// 	std::cout << "--7-- In position of number " << *it_3 << " put " << key << std::endl;
	// 	my_list->insert(it_3, key);
	// 	it = my_list->erase(it);
	// 	it++;
	// }

	// int i;
	// int key;
	// int j;
	
	// for (i = begin + 1; i <= end; i++) {
	// 	key = (*my_list)[i];
	// 	j = i - 1;
	// 	while (j >= begin && (*my_list)[j] > key) {
	// 		(*my_list)[j + 1] = (*my_list)[j];
	// 		j--;
	// 	}
	// 	(*my_list)[j + 1] = key;
	// }
}

void merge(std::list<int> * my_list, int const left, int const mid, int const right) {
	
	int n1 = mid - left + 1;
    int n2 = right - mid;
    std::list<int> LA, RA;
    // Copy elements from the left sublist to LA
    for (int i = 0; i < n1; i++) {
        LA.push_back(*std::next(my_list->begin(), left + i));
    }
    // Copy elements from the right sublist to RA
    for (int i = 0; i < n2; i++) {
        RA.push_back(*std::next(my_list->begin(), mid + 1 + i));
    }
    int RIDX = 0;
    int LIDX = 0;
    // Merge LA and RA into A
    for (int i = left; i <= right; i++) {
        if (RIDX == n2) {
            *std::next(my_list->begin(), i) = LA.front();
            LA.pop_front();
            LIDX++;
        } else if (LIDX == n1) {
            *std::next(my_list->begin(), i) = RA.front();
            RA.pop_front();
            RIDX++;
        } else if (RA.front() > LA.front()) {
            *std::next(my_list->begin(), i) = LA.front();
            LA.pop_front();
            LIDX++;
        } else {
            *std::next(my_list->begin(), i) = RA.front();
            RA.pop_front();
            RIDX++;
        }
    }
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