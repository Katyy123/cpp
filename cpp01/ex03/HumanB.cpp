/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:57:50 by cfiliber          #+#    #+#             */
/*   Updated: 2022/05/24 19:13:27 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {

	std::cout << name << " has been born" << std::endl;
}

HumanB::~HumanB() {
	
	std::cout << this->_name << " has died" << std::endl;
}

void	HumanB::attack() {

	if (this->_weapon == NULL)
		std::cout << this->_name << " attacks with a fist" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {

	this->_weapon = &weapon;
}