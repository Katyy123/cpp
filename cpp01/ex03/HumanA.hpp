/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:58:09 by cfiliber          #+#    #+#             */
/*   Updated: 2022/05/24 19:20:46 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
#include "Weapon.hpp"


class HumanA {

public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA();

	void	attack();

private:
	std::string _name;
	Weapon&		_weapon;
	
};

#endif