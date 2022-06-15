#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int main() {

    ScavTrap bim("bim");
    ScavTrap bom("bom");

    std::cout << std::endl;
    bim.attack("bom");
    bom.takeDamage (bim.getAttackDamage());
    std::cout << std::endl;

    bim.guardGate();
    std::cout << std::endl;

    return 0;
}
