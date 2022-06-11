/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:48:08 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/11 17:33:35 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {

	//std::cout << "Default constructor called" << std::endl;
}

Point::Point(float const x, float const y) : _x(x), _y(y) {

	//std::cout << "Parameter constructor called" << std::endl;
}

Point::Point(Point const & point) { // : _x(src._x), _y(src._y)

	//std::cout << "Copy constructor called" << std::endl;
	*this = point;
}

Point & Point::operator=(Point const & point) {

	//std::cout << "Copy assignment operator called" << std::endl;
	(void)point; // mi sembra sbagliato
	return (*this);
}

Point::~Point(void) {

	//std::cout << "Destructor called" << std::endl;
}

Fixed Point::get_x(void) const {

	return this->_x;
}

Fixed Point::get_y(void) const {

	return this->_y;
}
