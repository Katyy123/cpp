/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:29:38 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/14 16:33:28 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {

    ClapTrap bim("bim");
    ClapTrap bom("bom");
    ClapTrap bum("bum");
    ClapTrap bem("bem");

    std::cout << std::endl;
    bim.attack("bom");
    bom.takeDamage (bim.getAttackDamage());
    std::cout << std::endl;

    bom.beRepaired (bim.getAttackDamage());
    std::cout << std::endl;

    bim.setAttackDamage(6);
    std::cout << std::endl;

    bim.attack("bom");
    bom.takeDamage (bim.getAttackDamage());
    std::cout << std::endl;

    bom.beRepaired (bim.getAttackDamage());
    std::cout << std::endl;

    bim.setAttackDamage(12);
    std::cout << std::endl;

    bim.attack("bom");
    bom.takeDamage (bim.getAttackDamage());
    std::cout << std::endl;

    bom.beRepaired (bim.getAttackDamage());
    std::cout << std::endl;

    bim.setAttackDamage(1);
    std::cout << std::endl;

    bim.attack("bum");
    bum.takeDamage (bim.getAttackDamage());
    std::cout << std::endl;

    bum.beRepaired (bim.getAttackDamage());
    std::cout << std::endl;

    bim.attack("bum");
    bum.takeDamage (bim.getAttackDamage());
    std::cout << std::endl;

    bum.beRepaired (bim.getAttackDamage());
    std::cout << std::endl;

    bim.attack("bum");
    bum.takeDamage (bim.getAttackDamage());
    std::cout << std::endl;

    bum.beRepaired (bim.getAttackDamage());
    std::cout << std::endl;

    bim.attack("bum");
    bum.takeDamage (bim.getAttackDamage());
    std::cout << std::endl;

    bum.beRepaired (bim.getAttackDamage());
    std::cout << std::endl;

    bim.attack("bum");
    bum.takeDamage (bim.getAttackDamage());
    std::cout << std::endl;

    bum.beRepaired (bim.getAttackDamage());
    std::cout << std::endl;

    bim.attack("bum");
    bum.takeDamage (bim.getAttackDamage());
    std::cout << std::endl;

    bum.beRepaired (bim.getAttackDamage());
    std::cout << std::endl;

    bim.attack("bum");
    bum.takeDamage (bim.getAttackDamage());
    std::cout << std::endl;

    bum.beRepaired (bim.getAttackDamage());
    std::cout << std::endl;

    bim.attack("bum");
    std::cout << std::endl;

    bem.setAttackDamage(1);
    std::cout << std::endl;

    bem.attack("bum");
    bum.takeDamage (bem.getAttackDamage());
    std::cout << std::endl;

    bum.beRepaired (bem.getAttackDamage());
    std::cout << std::endl;

    bem.attack("bum");
    bum.takeDamage (bem.getAttackDamage());
    std::cout << std::endl;

    bum.beRepaired (bem.getAttackDamage());
    std::cout << std::endl;

    bem.attack("bum");
    bum.takeDamage (bem.getAttackDamage());
    std::cout << std::endl;

    bum.beRepaired (bem.getAttackDamage());
    std::cout << std::endl;

    bem.attack("bum");
    bum.takeDamage (bem.getAttackDamage());
    std::cout << std::endl;

    bum.beRepaired (bem.getAttackDamage());
    std::cout << std::endl;

    return 0;
}
