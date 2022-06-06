/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:51:56 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/06 17:48:52 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int    main(void) {

	Zombie* aLotOfZombies = zombieHorde( 5, "IdiotZombie" );
	for (int i = 0; i < 5; i++) {
		aLotOfZombies[i].announce();
	}
	// std::cout << "----- Inizio test -----" << std::endl;
	// aLotOfZombies[0].setName("0");
	// aLotOfZombies[0].announce();
	// aLotOfZombies[1].setName("1");
	// aLotOfZombies[1].announce();
	// aLotOfZombies[2].setName("2");
	// aLotOfZombies[2].announce();
	// aLotOfZombies[3].setName("3");
	// aLotOfZombies[3].announce();
	// aLotOfZombies[4].setName("4");
	// aLotOfZombies[4].announce();
	// std::cout << "----- Fine test -----" << std::endl;
	delete [] aLotOfZombies;
}