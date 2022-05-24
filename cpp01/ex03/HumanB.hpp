/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:58:07 by cfiliber          #+#    #+#             */
/*   Updated: 2022/05/24 19:10:10 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
#include "Weapon.hpp"


class HumanB {

public:
	HumanB(std::string name);
	~HumanB();

	void	attack();
	void	setWeapon(Weapon weapon);

private:
	std::string _name;
	Weapon*		_weapon;
	
};

#endif