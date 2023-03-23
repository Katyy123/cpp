/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:30:25 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/23 17:19:27 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef RPN_HPP
#define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

/* RPN.cpp */
int solve_expression(std::string const & str);

/* utils.cpp */
bool	ft_is_toobig(std::string const & str);
int		ft_stoi(std::string const & str);
int		ft_ctoi(char const c);
float	ft_stof(std::string const &str);

#endif