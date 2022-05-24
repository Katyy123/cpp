/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:52:42 by cfiliber          #+#    #+#             */
/*   Updated: 2022/05/24 15:32:31 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {

	Zombie* zombieHorde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		zombieHorde[i].setName(name);
	}
	return zombieHorde;
}