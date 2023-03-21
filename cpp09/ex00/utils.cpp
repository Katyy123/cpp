/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catia <catia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:53:45 by catia             #+#    #+#             */
/*   Updated: 2023/03/20 20:31:22 by catia            ###   ########.fr       */
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

int	ft_atoi(std::string str) {
	
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