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

Brain::Brain() {

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
		for (int i = 0; i < _ideasNum; i++)
			this->_ideas[i] = brain._ideas[i];
	}		
	return *this;
}