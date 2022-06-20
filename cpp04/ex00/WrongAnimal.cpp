/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:29:13 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/20 15:36:16 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type_("") {

	std::cout << "WrongAnimal default constructor called" << std::endl; 
}

WrongAnimal::WrongAnimal(WrongAnimal const & wrong_animal) {

	std::cout << "WrongAnimal copy constructor called" << std::endl; 
	*this = wrong_animal;
}

WrongAnimal::~WrongAnimal() {

	std::cout << "WrongAnimal destructor called" << std::endl; 
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & wrong_animal) {

	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &wrong_animal)
		this->type_ = wrong_animal.getType();
	return *this;
}

std::string WrongAnimal::getType() const {

	return this->type_;
}

void WrongAnimal::makeSound() const {

	std::cout << "Undefined sound" << std::endl;
}