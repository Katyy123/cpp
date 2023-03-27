/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catia <catia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:07:58 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/27 01:25:43 by catia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool ft_is_toobig(std::string const & str) {
	
	int	i;
	int	num;

	num = 0;
	i = 0;
	while (str[i] >= 48 && str[i] <= 57) {
		if (((2147483647 - (str[i] - 48)) / 10 < num))
			return true;
		else {
			num = num * 10 + (str[i] - 48);
			i++;
		}
	}
	return false;
}

int	ft_stoi(std::string const & str) {
	
	int	i;
	int	num;

	num = 0;
	i = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num);
}

int	ft_ctoi(char const c) {
	
	int	num;

	num = 0;
	if (c >= 48 && c <= 57)
		num = c - 48;
	return (num);
}

float	ft_stof(std::string const &str) {
	
	int			i;
	int			int_part;
	float		dec_part;
	std::string int_str;
	std::string dec_str;
	std::size_t dot_pos;
	float		num;

	int_part = 0;
	dec_part = 0;
	i = 0;
	dot_pos = str.find(".");
	int_str = str.substr(0, dot_pos);
	while (int_str[i] >= 48 && int_str[i] <= 57)
	{
		int_part = int_part * 10 + (int_str[i] - 48);
		i++;
	}
	if (dot_pos != str.npos)
	{
		dec_str = str.substr(dot_pos + 1, str.npos);
		i = dec_str.length();
		while (dec_str[i - 1] >= 48 && dec_str[i - 1] <= 57 && i > 0)
		{
			dec_part = (dec_part / 10) + (static_cast<float>(dec_str[i - 1] - 48) / 10); 
			i--;
		}
	}
	num = int_part + dec_part;
	return (num);
}

std::list<int>::iterator ft_next(std::list<int>::iterator it, int n) {

	for (int i = 0; i < n; i++) {
		it++;
	}
	return it;
}

std::list<int>::iterator ft_prev(std::list<int>::iterator it, int n) {

	for (int i = 0; i < n; i++) {
		it--;
	}
	return it;
}