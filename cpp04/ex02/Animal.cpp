/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:13:41 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/20 15:05:08 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal() : type_("") {

	std::cout << "AAnimal default constructor called" << std::endl; 
}

AAnimal::AAnimal(AAnimal const & animal) {

	std::cout << "AAnimal copy constructor called" << std::endl; 
	*this = animal;
}

AAnimal::~AAnimal() {

	std::cout << "AAnimal destructor called" << std::endl; 
}

AAnimal & AAnimal::operator=(AAnimal const & animal) {

	std::cout << "AAnimal copy assignment operator called" << std::endl;
	if (this != &animal)
		this->type_ = animal.getType();
	return *this;
}

std::string AAnimal::getType() const {

	return this->type_;
}

void AAnimal::makeSound() const {

	std::cout << "Undefined sound" << std::endl;
}