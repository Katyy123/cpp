/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:29:32 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/14 20:28:38 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(MAX_HIT_POINTS), _energyPoints(MAX_ENERGY_POINTS), _attackDamage(0) {

	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(MAX_HIT_POINTS), _energyPoints(MAX_ENERGY_POINTS), _attackDamage(0) {
	
	std::cout << "Parametric constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & claptrap) {

	std::cout << "Copy constructor called" << std::endl;
	*this = claptrap;
}

ClapTrap::~ClapTrap() {

	std::cout << "Destructor called" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & claptrap) {

	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &claptrap) {
		this->_name = claptrap.getName();
		this->_hitPoints = claptrap.getHitPoints();
		this->_energyPoints = claptrap.getEnergyPoints();
		this->_attackDamage = claptrap.getAttackDamage();
	}
	return *this;
}

std::string const & ClapTrap::getName(void) const{

	return this->_name;
}

unsigned int	ClapTrap::getHitPoints(void) const {

	return this->_hitPoints;
}

unsigned int	ClapTrap::getEnergyPoints(void) const {

	return this->_energyPoints;
}

unsigned int	ClapTrap::getAttackDamage(void) const {

	return this->_attackDamage;
}

void	ClapTrap::setName(std::string name) {

	this->_name = name;
}

void	ClapTrap::setHitPoints(unsigned int amount) {

	this->_hitPoints = amount;
}

void	ClapTrap::setEnergyPoints(unsigned int amount) {

	this->_energyPoints = amount;
}

void	ClapTrap::setAttackDamage(unsigned int amount) {

	std::cout << "Attack damage of ClapTrap " << this->_name << " has been set to " << amount;
	std::cout << std::endl;
	this->_attackDamage = amount;
}

void ClapTrap::attack(const std::string& target) {

	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " can't attack: No hit points left" << std::endl;
		return;
	}
	if (this->_energyPoints > 0) {// && [target_class].getHitPoints() - this->_attackDamage >= 0) {
		//[target_class].takeDamage(this->_attackDamage);
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!";
		std::cout << std::endl;
		this->_energyPoints--;
	}
	// else if (this->_energyPoints > 0 && [target_class].getHitPoints() > 0) {
	// 	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << [target_class].getHitPoints() << " points of damage!";
	// 	std::cout << std::endl;
	// 	[target_class].takeDamage(this->_attackDamage);
	// 	this->_energyPoints--;
	// }
	else if (!(this->_energyPoints > 0))
		std::cout << "ClapTrap " << this->_name << " can't attack: No energy points left" << std::endl;
// 	else if (!([target_class].getHitPoints() > 0))
// 		std::cout << "ClapTrap " << this->_name << " can't attack: Target has no hit points left" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {

	if (this->_hitPoints >= amount) {
		this->_hitPoints -= amount;
		std::cout << "ClapTrap " << this->_name << " has lost " << amount << " hit points";
		std::cout << std::endl;
	}
	else if (this->_hitPoints > 0) {
		std::cout << "ClapTrap " << this->_name << " has lost " << this->_hitPoints << " hit points";
		this->setHitPoints(0);
		std::cout << std::endl;
	}
	else {
		std::cout << "ClapTrap " << this->_name << " has " << this->_hitPoints << " no hit points, so it can't lose any more";
		std::cout << std::endl;
		return;
	}
	std::cout << "Now ClapTrap " << this->_name << " has " << this->_hitPoints << " hit points left " << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {

	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " can't be repaired: No hit points left" << std::endl;
		return;
	}
	if (this->_hitPoints == MAX_HIT_POINTS) {
		std::cout << "ClapTrap " << this->_name << " doesn't need to be repaired" << std::endl;
		return;
	}
	if (this->_energyPoints > 0 && this->_hitPoints + amount <= MAX_HIT_POINTS) {
		this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->_name << " has been repaired, adding " << amount << " points to its hit points";
		std::cout << std::endl;
		this->_energyPoints--;
	}
	else if (!(this->_energyPoints > 0)) {
		std::cout << "ClapTrap " << this->_name << " can't be repaired: No energy points left" << std::endl;
		return;
	}
	else if (!(this->_hitPoints + amount <= MAX_HIT_POINTS)) {
		this->setHitPoints(MAX_HIT_POINTS);
		std::cout << "ClapTrap " << this->_name << " has been repaired, adding " << MAX_HIT_POINTS - this->_hitPoints << " points to its hit points";
		std::cout << std::endl;
	}
	std::cout << "Now ClapTrap " << this->_name << " has " << this->_hitPoints << " hit points " << std::endl;
}