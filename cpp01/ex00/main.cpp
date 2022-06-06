/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:47:22 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/06 17:26:58 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int    main(void) {

	Zombie *zombie = newZombie("StupidZombie");
	delete zombie;
	randomChump("HomerZombie");
	//std::cout << "check" << std::endl;
}