/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:13:54 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/25 13:36:14 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <ctime>
# include <vector>
# include <list>
//# include "print_output.tpp"

void	print_output(std::vector<int> const & input_array, std::vector<int> const & sorted_vector,
			std::list<int> const & sorted_list, size_t elem_number, double vector_time, double list_time);

	
#endif