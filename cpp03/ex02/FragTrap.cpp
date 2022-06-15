#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {

	std::cout << "Default FragTrap constructor called" << std::endl;
    this->_hitPoints = MAX_HIT_POINTS_FRAG;
    this->_energyPoints = MAX_ENERGY_POINTS_FRAG;
    this->_attackDamage = ATTACK_DAMAGE_FRAG;

}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	
	std::cout << "Parametric FragTrap constructor called" << std::endl;
    this->_name = name;
    this->_hitPoints = MAX_HIT_POINTS_FRAG;
    this->_energyPoints = MAX_ENERGY_POINTS_FRAG;
    this->_attackDamage = ATTACK_DAMAGE_FRAG;
}

FragTrap::FragTrap(FragTrap const & fragtrap) : ClapTrap(fragtrap) {

	std::cout << "Copy FragTrap constructor called" << std::endl;
	*this = fragtrap;
}

FragTrap::~FragTrap() {

	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & fragtrap) {

	std::cout << "Copy assignment FragTrap operator called" << std::endl;
	if (this != &fragtrap) {
		this->_name = fragtrap.getName();
		this->_hitPoints = fragtrap.getHitPoints();
		this->_energyPoints = fragtrap.getEnergyPoints();
		this->_attackDamage = fragtrap.getAttackDamage();
	}
	return *this;
}

void	FragTrap::setAttackDamage(unsigned int amount) {

	std::cout << "Attack damage of FragTrap " << this->_name << " has been set to " << amount;
	std::cout << std::endl;
	this->_attackDamage = amount;
}

void    FragTrap::attack(const std::string& target) {

	if (this->_hitPoints == 0) {
		std::cout << "FragTrap " << this->_name << " can't attack: No hit points left" << std::endl;
		return;
	}
	if (this->_energyPoints > 0) {
		std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!";
		std::cout << std::endl;
		this->_energyPoints--;
	}
	else if (!(this->_energyPoints > 0))
		std::cout << "FragTrap " << this->_name << " can't attack: No energy points left" << std::endl;
}

void    FragTrap::beRepaired(unsigned int amount) {

	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " can't be repaired: No hit points left" << std::endl;
		return;
	}
	if (this->_hitPoints == MAX_HIT_POINTS_FRAG) {
		std::cout << "ClapTrap " << this->_name << " doesn't need to be repaired" << std::endl;
		return;
	}
	if (this->_energyPoints > 0 && this->_hitPoints + amount <= MAX_HIT_POINTS_FRAG) {
		this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->_name << " has been repaired, adding " << amount << " points to its hit points";
		std::cout << std::endl;
		this->_energyPoints--;
	}
	else if (!(this->_energyPoints > 0)) {
		std::cout << "ClapTrap " << this->_name << " can't be repaired: No energy points left" << std::endl;
		return;
	}
	else if (!(this->_hitPoints + amount <= MAX_HIT_POINTS_FRAG)) {
		this->setHitPoints(MAX_HIT_POINTS_FRAG);
		std::cout << "ClapTrap " << this->_name << " has been repaired, adding " << MAX_HIT_POINTS_FRAG - this->_hitPoints << " points to its hit points";
		std::cout << std::endl;
	}
	std::cout << "Now ClapTrap " << this->_name << " has " << this->_hitPoints << " hit points " << std::endl;
}

void    FragTrap::highFivesGuys(void) {

    std::cout << "FragTrap " << this->_name << " requests a positive high fives" << std::endl;
}
