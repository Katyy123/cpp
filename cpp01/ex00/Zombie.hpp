/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:47:41 by cfiliber          #+#    #+#             */
/*   Updated: 2022/05/23 19:54:41 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {

public:
    Zombie(std::string name);
    ~Zombie();
    void announce(void); 

private:
    std::string _name;
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

#endif