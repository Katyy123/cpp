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

HumanB::HumanB(std::string name, Weapon* weapon) : _name(name), _weapon(weapon) {

	std::cout << "A HumanB has been born" << std::endl;
}

HumanB::~HumanB() {
	
	std::cout << "A HumanB has died" << std::endl;
}

void	HumanB::_attack() {

	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}