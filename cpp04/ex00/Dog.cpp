/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:18:01 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/20 15:05:19 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {

	std::cout << "Dog default constructor called" << std::endl;
	this->type_ = "Dog";
}

Dog::Dog(Dog const & dog) : Animal(dog) {

	std::cout << "Dog copy constructor called" << std::endl; 
	*this = dog;
}

Dog::~Dog() {

	std::cout << "Dog destructor called" << std::endl; 
}

Dog & Dog::operator=(Dog const & dog) {

	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &dog)
		this->type_ = dog.getType();
	return *this;
}

void Dog::makeSound() const {

	std::cout << "Bau bau" << std::endl;
}