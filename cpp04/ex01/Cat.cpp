/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:18:04 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/20 20:29:41 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {

	std::cout << "Cat default constructor called" << std::endl;
	this->_brain = new Brain();
	this->type_ = "Cat";
}

Cat::Cat(Cat const & cat) : Animal(cat) {

	std::cout << "Cat copy constructor called" << std::endl;
	*this = cat;
	//aggiungi brain con  new
}

Cat::~Cat() {

	std::cout << "Cat destructor called" << std::endl; 
	delete this->_brain;
}

Cat & Cat::operator=(Cat const & cat) {

	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &cat)
		this->type_ = cat.getType();
		//aggiungi brain con new
	return *this;
}

void Cat::makeSound() const {

	std::cout << "Miaaooo" << std::endl;
}

Brain* Cat::getBrain() const {

	return this->_brain;
}