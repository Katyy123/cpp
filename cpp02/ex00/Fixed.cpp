/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:22:27 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/09 18:22:28 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _n(0) {

	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & instance) {

	std::cout << "Copy constructor called" << std::endl;
	*this = instance;
}

Fixed::~Fixed(void) {

	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(Fixed const & instance) {

	std::cout << "Copy ssignment operator called" << std::endl;
	if (this != &instance)
		this->_n = instance.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const {

	std::cout << "getRawBits member function called" << std::endl;
	return this->_n;
}

void Fixed::setRawBits( int const raw ) {

	std::cout << "setRawBits member function called" << std::endl;
	this->_n = raw;
}


const int Fixed::_FractBits = 8;