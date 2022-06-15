#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {

	std::cout << "Default ScavTrap constructor called" << std::endl;
    this->_hitPoints = MAX_HIT_POINTS_SCAV;
    this->_energyPoints = MAX_ENERGY_POINTS_SCAV;
    this->_attackDamage = ATTACK_DAMAGE_SCAV;

}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	
	std::cout << "Parametric ScavTrap constructor called" << std::endl;
    this->_name = name;
    this->_hitPoints = MAX_HIT_POINTS_SCAV;
    this->_energyPoints = MAX_ENERGY_POINTS_SCAV;
    this->_attackDamage = ATTACK_DAMAGE_SCAV;
}

ScavTrap::ScavTrap(ScavTrap const & scavtrap) : ClapTrap(scavtrap) {

	std::cout << "Copy ScavTrap constructor called" << std::endl;
	*this = scavtrap;
}

ScavTrap::~ScavTrap() {

	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & scavtrap) {

	std::cout << "Copy assignment ScavTrap operator called" << std::endl;
	if (this != &scavtrap) {
		this->_name = scavtrap.getName();
		this->_hitPoints = scavtrap.getHitPoints();
		this->_energyPoints = scavtrap.getEnergyPoints();
		this->_attackDamage = scavtrap.getAttackDamage();
	}
	return *this;
}

void	ScavTrap::setAttackDamage(unsigned int amount) {

	std::cout << "Attack damage of ScavTrap " << this->_name << " has been set to " << amount;
	std::cout << std::endl;
	this->_attackDamage = amount;
}

void ScavTrap::attack(const std::string& target) {

	if (this->_hitPoints == 0) {
		std::cout << "ScavTrap " << this->_name << " can't attack: No hit points left" << std::endl;
		return;
	}
	if (this->_energyPoints > 0) {
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!";
		std::cout << std::endl;
		this->_energyPoints--;
	}
	else if (!(this->_energyPoints > 0))
		std::cout << "ScavTrap " << this->_name << " can't attack: No energy points left" << std::endl;
}

void ScavTrap::guardGate(void) {

    std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
}