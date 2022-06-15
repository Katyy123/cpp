#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {

    FragTrap bim("bim");
    FragTrap bom("bom");

    std::cout << std::endl;
    bim.attack("bom");
    bom.takeDamage (bim.getAttackDamage());
    std::cout << std::endl;

    bim.highFivesGuys();
    std::cout << std::endl;

    return 0;
}
