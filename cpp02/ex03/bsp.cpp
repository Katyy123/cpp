/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:48:23 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/14 15:21:35 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point) {

	Fixed	inter_ab_x; // x-coordinate of the intersection between half straight line to the right from POINT and AB side of the triangle
	Fixed	inter_bc_x;
	Fixed	inter_ca_x;
	int		count = 0;
	Fixed	min_y;
	Fixed	max_y;
	bool	is_ab_horiz = 0;
	bool	is_bc_horiz = 0;
	bool	is_ca_horiz = 0;
	
	min_y = fmin(fmin(a.get_y().toFloat(), b.get_y().toFloat()), fmin(a.get_y().toFloat(), c.get_y().toFloat()));
	max_y = fmax(fmax(a.get_y().toFloat(), b.get_y().toFloat()), fmax(a.get_y().toFloat(), c.get_y().toFloat()));
	if (! (point.get_y() > min_y && point.get_y() < max_y) ) {
		std::cout << std::endl;
		std::cout << "Point above or under the triangle or at the same height as the highest or lowest vertex" << std::endl;
		return 0;
	}
	
	if (a.get_y() != b.get_y()) //not a line "//" asse x
		inter_ab_x = ( (point.get_y() - a.get_y()) / (b.get_y() - a.get_y()) ) * (b.get_x() - a.get_x()) + a.get_x(); // math formula: intersection between 2 straight lines (1 is "//" asse x)
	else
		is_ab_horiz = 1;
	if (b.get_y() != c.get_y()) //not a line "//" asse x
		inter_bc_x = ( (point.get_y() - b.get_y()) / (c.get_y() - b.get_y()) ) * (c.get_x() - b.get_x()) + b.get_x(); // math formula: intersection between 2 straight lines (1 is "//" asse x)
	else
		is_bc_horiz = 1;
	if (c.get_y() != a.get_y()) //not a line "//" asse x
		inter_ca_x = ( (point.get_y() - c.get_y()) / (a.get_y() - c.get_y()) ) * (a.get_x() - c.get_x()) + c.get_x(); // math formula: intersection between 2 straight lines (1 is "//" asse x)
	else
		is_ca_horiz = 1;
	
	std::cout << std::endl;
	std::cout << "inter_ab_x: " << inter_ab_x << std::endl;
	std::cout << "inter_bc_x: " << inter_bc_x << std::endl;
	std::cout << "inter_ca_x: " << inter_ca_x << std::endl;

	std::cout << std::boolalpha << "is_ab_horiz: " << is_ab_horiz << std::endl;
	std::cout << std::boolalpha << "is_bc_horiz: " << is_bc_horiz << std::endl;
	std::cout << std::boolalpha << "is_ca_horiz: " << is_ca_horiz << std::endl;
	
	if ((point.get_x() == inter_ab_x && is_ab_horiz == 0 )|| (point.get_x() == inter_bc_x && is_bc_horiz == 0) || (point.get_x() == inter_ca_x && is_ca_horiz == 0)) {
		std::cout << "Point on the border" << std::endl;
		return 0;
	}
	
	if (is_ab_horiz == 0 && inter_ab_x > point.get_x() && inter_ab_x <= fmax(a.get_x().toFloat(), b.get_x().toFloat()))
		count++;
	if (is_bc_horiz == 0 && inter_bc_x != inter_ab_x && inter_bc_x > point.get_x() && inter_bc_x <= fmax(b.get_x().toFloat(), c.get_x().toFloat()))
		count++;
	if (is_ca_horiz == 0 && inter_ca_x != inter_ab_x && inter_ca_x != inter_bc_x && inter_ca_x > point.get_x() && inter_ca_x <= fmax(c.get_x().toFloat(), a.get_x().toFloat()))
		count++;
	if (count == 1)
		return 1;

	std::cout << "Point on the left or the right of the triangle" << std::endl;
	return 0;
}