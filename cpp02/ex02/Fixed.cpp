/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:33:14 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/09 21:09:11 by cfiliber         ###   ########.fr       */
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

bool Fixed::operator>(Fixed const & instance) const {

	if (this->getRawBits() > instance.getRawBits())
		return 1;
	return 0;
}

bool Fixed::operator<(Fixed const & instance) const {

	if (this->getRawBits() < instance.getRawBits())
		return 1;
	return 0;
}

bool Fixed::operator>=(Fixed const & instance) const {

	if (this->getRawBits() >= instance.getRawBits())
		return 1;
	return 0;
}

bool Fixed::operator<=(Fixed const & instance) const {

	if (this->getRawBits() <= instance.getRawBits())
		return 1;
	return 0;
}

bool Fixed::operator==(Fixed const & instance) const {

	if (this->getRawBits() == instance.getRawBits())
		return 1;
	return 0;
}

bool Fixed::operator!=(Fixed const & instance) const {

	if (this->getRawBits() != instance.getRawBits())
		return 1;
	return 0;
}

Fixed Fixed::operator+(Fixed const & instance) const {

	Fixed sum;
	
	sum._value = this->getRawBits() + instance.getRawBits();
	return sum;
}

Fixed Fixed::operator-(Fixed const & instance) const {

	Fixed diff;
	
	diff._value = this->getRawBits() - instance.getRawBits();
	return diff;
}

Fixed Fixed::operator*(Fixed const & instance) const {

	Fixed diff;
	
	diff._value = this->getRawBits() * instance.getRawBits();
	return diff;
}

Fixed Fixed::operator/(Fixed const & instance) const {

	Fixed quot;
	
	quot._value = this->getRawBits() / instance.getRawBits();
	return quot;
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