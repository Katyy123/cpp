/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:48:12 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/11 20:22:26 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int	main(void)
{
	//std::cout << std::boolalpha
	std::cout

		<< "a(2, 2), b(7, 4), c(2, 7), point(4, 5): "
		<< bsp(Point(2, 2), Point(7, 4), Point(2, 7), Point(4, 5)) << std::endl

		<< "a(0, 0), b(0, 5), c(5, 0), point(0, 5): "
		<< bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, 5)) << std::endl

		<< "a(0, 0), b(0, 5), c(5, 0), point(0, 3): "
		<< bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, 3)) << std::endl

		<< "a(0, 0), b(0, 5), c(5, 0), point(0, 0): "
		<< bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, 0)) << std::endl

		<< "a(0, 0), b(0, 5), c(5, 0), point(0.1, 0.01): "
		<< bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0.1f, 0.01f)) << std::endl

		<< "a(0, 0), b(0, 5), c(5, 0), point(10, 0.01): "
		<< bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(10, 0.01f)) << std::endl

		<< "a(0, 0), b(0, 5), c(5, 0), point(0, -0.01): "
		<< bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, -0.01f)) << std::endl;
	
	// Point	a(0, 0);
	// Point	b(20, 0);
	// Point	c(10, 30);
	// Point	in(10, 15);
	// Point	out(30, 50);

	// std::cout << "Point \"in\" created at x-" << in.get_x() << " y-" << in.get_y() << std::endl;
	// std::cout << "Point \"out\" created at x-" << out.get_x() << " y-" << out.get_y() << std::endl;
	// if (bsp(a, b, c, in))
	// 	std::cout << "\"in\" is in the triangle" << std::endl;
	// else
	// 	std::cout << "\"in\" is out of the triangle" << std::endl;
	// if (bsp(a, b, c, out))
	// 	std::cout << "\"out\" is in the triangle" << std::endl;
	// else
	// 	std::cout << "\"out\" is out of the triangle" << std::endl;
	
	// return 0;
}