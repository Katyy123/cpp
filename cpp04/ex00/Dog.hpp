/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:17:55 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/20 15:18:18 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal {

	public:
		Dog();
		Dog(Dog const & dog);
		virtual ~Dog();

		Dog & operator=(Dog const & dog);
		
		virtual void	makeSound() const;
		
};
#endif