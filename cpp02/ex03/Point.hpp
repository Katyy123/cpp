/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:48:06 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/13 16:45:30 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <cmath>
# include "Fixed.hpp"

class Point {

	public:
		Point();
		Point(float const x, float const y);
		Point(Point const & point);
		~Point();
		
		Point & operator=(Point const & point);

		Fixed get_x(void) const;
		Fixed get_y(void) const;

		//anything else useful
	
	private:
		Fixed const _x;
		Fixed const _y;
		//anything else useful
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif