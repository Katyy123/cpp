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
	HumanB(std::string name, Weapon* weapon);
	~HumanB();

	void	_attack();

private:
	Weapon* _weapon;
	std::string _name;
	
};

#endif