/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:52:11 by cfiliber          #+#    #+#             */
/*   Updated: 2022/05/24 14:48:57 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {

	std::cout << "A zombie has been born" << std::endl;
}

Zombie::Zombie(std::string name) : _name(name) {

	std::cout << this->_name << " has been initialized" << std::endl;
}

Zombie::~Zombie() {

	std::cout << this->_name << " has died" << std::endl;
}

void	Zombie::announce(void) {

	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name) {

	this->_name = name;
}
