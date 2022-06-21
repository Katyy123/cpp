/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:29:11 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/20 15:36:28 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {

	std::cout << "WrongCat default constructor called" << std::endl;
	this->type_ = "WrongCat";
}

WrongCat::WrongCat(WrongCat const & wrong_cat) : WrongAnimal(wrong_cat) {

	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = wrong_cat;
}

WrongCat::~WrongCat() {

	std::cout << "WrongCat destructor called" << std::endl; 
}

WrongCat & WrongCat::operator=(WrongCat const & wrong_cat) {

	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &wrong_cat)
		this->type_ = wrong_cat.getType();
	return *this;
}

void WrongCat::makeSound() const {

	std::cout << "Miaaooo" << std::endl;
}