/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:57:55 by cfiliber          #+#    #+#             */
/*   Updated: 2022/05/24 19:03:43 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {
	
	std::cout << type <<" has been created" << std::endl;
}

Weapon::~Weapon() {
	
	std::cout << this->_type << " has been deleted" << std::endl;
}

std::string const & Weapon::getType() {

	return this->_type;
}

void	Weapon::setType(std::string newType) {

	this->_type = newType;
}