# ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

# define MAX_HIT_POINTS_SCAV 100
# define MAX_ENERGY_POINTS_SCAV 50
# define ATTACK_DAMAGE_SCAV 20

class ScavTrap : public ClapTrap {

    public:
        ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & scavtrap);
		~ScavTrap();

		ScavTrap & operator=(ScavTrap const & scavtrap);

        void	setAttackDamage(unsigned int amount);

        void	attack(const std::string& target);

        void    guardGate();

};

#endif