/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:30:25 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/23 16:04:56 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef RPN_HPP
#define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

//#define static_cast<std::string>("0123456789") ALL_DIGITS_STRING

/* RPN.cpp */
int solve_expression(std::string const & str);

/* utils.cpp */
bool ft_is_toobig(std::string const & str);
int	ft_stoi(std::string const & str);
float	ft_stof(std::string const &str);

#endif