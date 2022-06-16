/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:18:04 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/16 17:04:07 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {

	std::cout << "Cat default constructor called" << std::endl;
	this->type_ = "Cat";
}

Cat::Cat(std::string type) : Animal(type) {

	std::cout << "Cat parametric constructor called" << std::endl; 
}

Cat::Cat(Cat const & cat) : Animal(cat) {

	std::cout << "Cat copy constructor called" << std::endl; 
}

Cat::~Cat() {

	std::cout << "Cat destructor called" << std::endl; 
}

Cat & Cat::operator=(Cat const & cat) {

	std::cout << "Cat copy assignment operator called" << std::endl; 
}

void Cat::makeSound() {

	std::cout << "Undefined sound" << std::endl;
}