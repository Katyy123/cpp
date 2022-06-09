/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:23:57 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/09 20:24:30 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0) {

	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer) {

	std::cout << "Int constructor called" << std::endl;
	this->_value = integer << this->_FractBits;
}

Fixed::Fixed(const float floatNum) {

	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(floatNum * (1 << this->_FractBits));
}

Fixed::Fixed(Fixed const & instance) {

	std::cout << "Copy constructor called" << std::endl;
	*this = instance;
}

Fixed::~Fixed(void) {

	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(Fixed const & instance) {

	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &instance)
		this->_value = instance.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const {

	return this->_value;
}

void Fixed::setRawBits( int const raw ) {

	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float Fixed::toFloat( void ) const {

	float floatNum;

	floatNum = float(this->_value) / (1 << this->_FractBits);
	return floatNum;
}

int Fixed::toInt( void ) const {

	int integer;

	integer = this->_value >> this->_FractBits;
	return integer;
}

std::ostream & operator<<(std::ostream & o, Fixed const & instance) {

	o << instance.toFloat();
	return o;
}

const int Fixed::_FractBits = 8;