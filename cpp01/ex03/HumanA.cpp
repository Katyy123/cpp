/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:57:46 by cfiliber          #+#    #+#             */
/*   Updated: 2022/05/24 19:20:42 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {

	std::cout << "A HumanA has been born" << std::endl;
}

HumanA::~HumanA() {
	
	std::cout << "A HumanA has died" << std::endl;
}

void	HumanA::_attack() {

	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}