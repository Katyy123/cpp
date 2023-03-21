/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:53:45 by catia             #+#    #+#             */
/*   Updated: 2023/03/21 16:57:34 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

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
		//std::cout << "test" << std::endl;
		dec_str = str.substr(dot_pos + 1, str.npos);
		i = dec_str.length();
		//std::cout << "i: " << i << std::endl << "dec_str: " << dec_str << std::endl;
		while (dec_str[i - 1] >= 48 && dec_str[i - 1] <= 57 && i > 0)
		{
			dec_part = (dec_part / 10) + (static_cast<float>(dec_str[i - 1] - 48) / 10);
			//std::cout << "dec_part: " << dec_part << std::endl; 
			i--;
		}
	}
	//std::cout << std::endl << "int_part: " << int_part << std::endl;
	//std::cout << "dec_part: " << dec_part << std::endl;
	num = int_part + dec_part;
	//std::cout << "int_part casted in float: " << static_cast<float>(int_part) << std::endl;
	//std::cout << "num: " << num << std::endl;
	return (num);
}

// float	ft_stof(std::string const & str) {
	
// 	std::istringstream ss(str);
//     float f;
//     ss >> f;
//     return static_cast<float>(atof(str.c_str()));
// }