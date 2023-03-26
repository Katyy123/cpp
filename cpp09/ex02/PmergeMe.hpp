/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:13:54 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/26 21:11:23 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <fstream>
# include <iomanip>
# include <string>
# include <ctime>
# include <vector>
# include <list>
# include <sstream>
//# include "print_output.tpp"
# include <cmath>

/* PmergeMe.cpp */
void				print_output(std::vector<int> const & input_vector, std::vector<int> const & sorted_vector,
						std::list<int> const & sorted_list, size_t elem_number, double vector_time, double list_time);

/* PmergeMe.cpp - vector */
void				insertion_sort(std::vector<int> * my_vector, int begin, int end);
void				merge(std::vector<int> * my_vector, int const left, int const mid, int const right);
void				merge_sort(std::vector<int> * my_vector, int const begin, int const end);
std::vector<int> *	merge_insert_sort(int elem_number, char **num_matrix, std::vector<int> * my_vector);

/* PmergeMe.cpp - list */
void				insertion_sort(std::list<int> * my_list, int begin, int end);
void				merge(std::list<int> * my_list, int const left, int const mid, int const right);
void				merge_sort(std::list<int> * my_list, int const begin, int const end);
std::list<int> *	merge_insert_sort(int elem_number, char **num_matrix, std::list<int> * my_list);

/* utils.cpp */
bool				ft_is_toobig(std::string const & str);
int					ft_stoi(std::string const & str);
int					ft_ctoi(char const c);
float				ft_stof(std::string const &str);
	
#endif