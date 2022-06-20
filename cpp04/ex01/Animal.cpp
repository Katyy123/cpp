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

Animal::Animal() : type_("") {

	std::cout << "Animal default constructor called" << std::endl; 
}

Animal::Animal(Animal const & animal) {

	std::cout << "Animal copy constructor called" << std::endl; 
	*this = animal;
}

Animal::~Animal() {

	std::cout << "Animal destructor called" << std::endl; 
}

Animal & Animal::operator=(Animal const & animal) {

	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &animal)
		this->type_ = animal.getType();
	return *this;
}

std::string Animal::getType() const {

	return this->type_;
}

void Animal::makeSound() const {

	std::cout << "Undefined sound" << std::endl;
}