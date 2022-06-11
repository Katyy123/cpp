/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:48:23 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/11 20:57:44 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int bsp( Point const a, Point const b, Point const c, Point const point) {
	
	/* 
  a, b, c: The vertices of our beloved triangle.
• point: The point to check.
• Returns: True if the point is inside the triangle. False otherwise.
Thus, if the point is a vertex or on edge, it will return False.
*/

	Fixed	inter_ab_x; // x-coordinate of the intersection between half straight line to the right from POINT and AB side of the triangle
	Fixed	inter_bc_x;
	Fixed	inter_ca_x;
	int		count = 0;
	Fixed	min_y;
	Fixed	max_y;
	
	// min_y = min(a.get_y(), b.get_y());
	// max_y = max(max(a.get_y(), b.get_y()), min(a.get_y(), c.get_y()));
	min_y = fmin(fmin(a.get_y().toFloat(), b.get_y().toFloat()), fmin(a.get_y().toFloat(), c.get_y().toFloat()));
	max_y = fmax(fmax(a.get_y().toFloat(), b.get_y().toFloat()), fmax(a.get_y().toFloat(), c.get_y().toFloat()));
	if (! (point.get_y() > min_y && point.get_y() < max_y) )
		return -1;

	// if (a.get_y() != b.get_y()) { //not a line "//" asse x or "//" asse y
	// 	if ((point.get_x() - a.get_x()) / (b.get_x() - a.get_x()) == (point.get_y() - a.get_y()) / (b.get_y() - a.get_y())) // math formula: point belongs to straight line between 2 points
	// }
	if (a.get_y() != b.get_y()) {//not a line "//" asse x
		inter_ab_x = ( (point.get_y() - a.get_y()) / (b.get_y() - a.get_y()) ) * (b.get_x() - a.get_x()) + a.get_x(); // math formula: intersection between 2 straight lines (1 is "//" asse x)
	}
	if (b.get_y() != c.get_y()) {//not a line "//" asse x
		inter_bc_x = ( (point.get_y() - b.get_y()) / (c.get_y() - b.get_y()) ) * (c.get_x() - b.get_x()) + b.get_x(); // math formula: intersection between 2 straight lines (1 is "//" asse x)
	}
	if (c.get_y() != a.get_y()) {//not a line "//" asse x
		inter_ca_x = ( (point.get_y() - c.get_y()) / (a.get_y() - c.get_y()) ) * (a.get_x() - c.get_x()) + c.get_x(); // math formula: intersection between 2 straight lines (1 is "//" asse x)
	}
	
	std::cout << "inter_ab_x: " << inter_ab_x << std::endl;//stampa inter_ab_x
	std::cout << "inter_bc_x: " << inter_bc_x << std::endl; //stampa inter_bc_x
	std::cout << "inter_ca_x: " << inter_ca_x << std::endl; //stampa inter_ca_x
	
	if (point.get_x() == inter_ab_x || point.get_x() == inter_bc_x || point.get_x() == inter_ca_x)
		return -2;
	
	if (inter_ab_x > point.get_x())
		count++;
	if (inter_bc_x != inter_ab_x && inter_bc_x > point.get_x())
		count++;
	if (inter_ca_x != inter_ab_x && inter_ca_x != inter_bc_x && inter_ca_x > point.get_x())
		count++;
	if (count == 1)
		return 1;

	return -3;
}
	

	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
// 	int 	cross_count = 0;
// 	Fixed	check_x;
	
// 	if ((a.get_y() > point.get_y()) != (b.get_y() > point.get_y()))
// 	{
// 		check_x = (b.get_x() - a.get_x()) * (point.get_y() - a.get_y()) / (b.get_y() - a.get_y()) + a.get_x();
// 		if (point.get_x() < check_x)
// 			cross_count++;
// 	}


// 	if ((b.get_y() > point.get_y()) != (c.get_y() > point.get_y()))
// 	{
// 		check_x = (c.get_x() - b.get_x()) * (point.get_y() - b.get_y()) / (c.get_y() - b.get_y()) + b.get_x();
// 		if (point.get_x() < check_x)
// 			cross_count++;
// 	}

// 	if ((c.get_y() > point.get_y()) != (a.get_y() > point.get_y()))
// 	{
// 		check_x = (a.get_x() - c.get_x()) * (point.get_y() - c.get_y()) / (a.get_y() - c.get_y()) + c.get_x();
// 		if (point.get_x() < check_x)
// 			cross_count++;
// 	}
	
// 	return (cross_count % 2 == 1);
// }