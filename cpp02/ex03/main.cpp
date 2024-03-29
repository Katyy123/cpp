/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:48:12 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/13 17:49:06 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int	main(void)
{
	std::cout << std::boolalpha

		<< "a(2, 2), b(7, 4), c(2, 7), point(4, 5): "
		<< bsp(Point(2, 2), Point(7, 4), Point(2, 7), Point(4, 5)) << std::endl
		<< std::endl
		<< "a(0, 0), b(0, 5), c(5, 0), point(0, 5): "
		<< bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, 5)) << std::endl
		<< std::endl
		<< "a(0, 0), b(0, 5), c(5, 0), point(0, 3): "
		<< bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, 3)) << std::endl
		<< std::endl
		<< "a(0, 0), b(0, 5), c(5, 0), point(0, 0): "
		<< bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, 0)) << std::endl
		<< std::endl
		<< "a(0, 0), b(0, 5), c(5, 0), point(0.1, 0.01): "
		<< bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0.1f, 0.01f)) << std::endl
		<< std::endl
		<< "a(0, 0), b(0, 5), c(5, 0), point(10, 0.01): "
		<< bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(10, 0.01f)) << std::endl
		<< std::endl
		<< "a(0, 0), b(0, 5), c(5, 0), point(0, -0.01): "
		<< bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, -0.01f)) << std::endl
		<< std::endl
		<< "a(-3, 3), b(1, 1), c(-4, -2), point(-2, 1): "
		<< bsp(Point(-3, 3), Point(1, 1), Point(-4, -2), Point(-2, 1)) << std::endl
		<< std::endl
		<< "a(-3, 3), b(1, 1), c(-4, -2), point(-5, 0): "
		<< bsp(Point(-3, 3), Point(1, 1), Point(-4, -2), Point(-5, 0)) << std::endl
		<< std::endl;
	
	return 0;
}