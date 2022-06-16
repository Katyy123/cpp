/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:13:41 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/16 17:01:52 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {

	std::cout << "Animal default constructor called" << std::endl; 
}

Animal::Animal(std::string type) : type_(type) {

	std::cout << "Animal parametric constructor called" << std::endl; 
}

Animal::Animal(Animal const & animal) {

	std::cout << "Animal copy constructor called" << std::endl; 
}

Animal::~Animal() {

	std::cout << "Animal destructor called" << std::endl; 
}

Animal & Animal::operator=(Animal const & animal) {

	std::cout << "Animal copy assignment operator called" << std::endl; 
}

std::string Animal::getType() const {

	return this->type_;
}

void Animal::makeSound() {

	std::cout << "Undefined sound" << std::endl;
}