/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:13:45 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/16 17:02:40 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {

	public:
		Animal();
		Animal(std::string type);
		Animal(Animal const & animal);
		~Animal();

		Animal & operator=(Animal const & animal);

		std::string		getType(void) const;

		virtual void	makeSound();
	
	protected:
		std::string type_;
	
};

#endif