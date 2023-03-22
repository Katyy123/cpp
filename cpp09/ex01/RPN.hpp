/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:30:25 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/22 19:02:13 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef RPN_HPP
#define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

//#define static_cast<std::string>("0123456789") ALL_DIGITS_STRING

int solve_expression(std::string const & str, int * result);

#endif