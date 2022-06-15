#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

# define MAX_HIT_POINTS 10
# define MAX_ENERGY_POINTS 10

class ClapTrap {

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & claptrap);
		~ClapTrap();

		ClapTrap & operator=(ClapTrap const & claptrap);

		std::string const & getName(void) const;
		unsigned int		getHitPoints(void) const;
		unsigned int		getEnergyPoints(void) const;
		unsigned int		getAttackDamage(void) const;

		void	setName(std::string name);
		void	setHitPoints(unsigned int amount);
		void	setEnergyPoints(unsigned int amount);
		void	setAttackDamage(unsigned int amount);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
	
};

#endif