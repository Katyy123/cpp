/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:50:01 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/20 18:49:32 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() : _index(0) {

	std::cout << "Brain default constructor called" << std::endl; 
}

Brain::Brain(Brain const & brain) {

	std::cout << "Brain copy constructor called" << std::endl; 
	*this = brain;
}

Brain::~Brain() {

	std::cout << "Brain destructor called" << std::endl; 
}

Brain & Brain::operator=(Brain const & brain) {

	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &brain) {
		for (int i = 0; i < _ideasNum; i++) {
			this->_ideas[i] = brain._ideas[i];
			this->_index = brain._index;
		}
	}		
	return *this;
}

void Brain::printIdeas(void) const {

	for (int i = 0; i < _ideasNum && !this->_ideas[i].empty(); i++)
		std::cout << "\"" << this->_ideas[i] << "\"" << std::endl;
}

void Brain::setIdea(std::string idea) {

	this->_ideas[this->_index] = idea;
	this->_index++;
	this->_index = _index % 100;
}
