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
	
	
}

Weapon::~Weapon() {
	
	
}

std::string const & Weapon::getType() {

	std::string& typeRef = this->_type;
	return typeRef;
}

//testare se la ref ritornata è const

void	Weapon::setType(std::string newType) {

	this->_type = newType;
}