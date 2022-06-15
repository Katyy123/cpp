#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

# define MAX_HIT_POINTS_FRAG 100
# define MAX_ENERGY_POINTS_FRAG 100
# define ATTACK_DAMAGE_FRAG 30

class FragTrap : public ClapTrap {

    public:
        FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const & fragtrap);
		~FragTrap();

		FragTrap & operator=(FragTrap const & fragtrap);

        void	setAttackDamage(unsigned int amount);

        void	attack(const std::string& target);
        void    beRepaired(unsigned int amount);

        void    highFivesGuys(void);

};

#endif