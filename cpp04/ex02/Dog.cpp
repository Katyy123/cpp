/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:18:01 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/20 20:19:33 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal() {

	std::cout << "Dog default constructor called" << std::endl;
	this->_brain = new Brain();
	this->type_ = "Dog";
}

Dog::Dog(Dog const & dog) : AAnimal(dog) {

	std::cout << "Dog copy constructor called" << std::endl; 
	this->type_ = dog.getType();
	this->_brain = new Brain(*dog.getBrain());
}

Dog::~Dog() {

	std::cout << "Dog destructor called" << std::endl; 
	delete this->_brain;
}

Dog & Dog::operator=(Dog const & dog) {

	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &dog) {
		this->type_ = dog.getType();
		delete this->_brain;
		this->_brain = new Brain(*dog.getBrain());
	}
	return *this;
}

void Dog::makeSound() const {

	std::cout << "Bau bau" << std::endl;
}

Brain* Dog::getBrain() const {

	return this->_brain;
}