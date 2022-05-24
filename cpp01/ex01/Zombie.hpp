/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:52:29 by cfiliber          #+#    #+#             */
/*   Updated: 2022/05/24 15:32:22 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {

public:
    Zombie(std::string name);
	Zombie();
    ~Zombie();
    void announce(void); 
	void setName(std::string name);

private:
    std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif