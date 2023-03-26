/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:13:54 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/26 17:47:01 by cfiliber         ###   ########.fr       */
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
void	print_output(std::vector<int> const & input_vector, std::vector<int> const & sorted_vector,
			std::list<int> const & sorted_list, size_t elem_number, double vector_time, double list_time);
			
std::vector<int> * merge_insert_sort(int argc, char **argv, std::vector<int> * my_vector);

std::list<int> * merge_insert_sort(int elem_number, char **num_matrix, std::list<int> * my_list);

/* utils.cpp */
bool	ft_is_toobig(std::string const & str);
int		ft_stoi(std::string const & str);
int		ft_ctoi(char const c);
float	ft_stof(std::string const &str);
	
#endif