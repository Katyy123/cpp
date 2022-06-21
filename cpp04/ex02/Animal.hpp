/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:13:45 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/20 15:18:05 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class AAnimal {

	public:
		AAnimal();
		AAnimal(AAnimal const & animal);
		virtual ~AAnimal();

		AAnimal & operator=(AAnimal const & animal);

		std::string		getType(void) const;

		virtual void	makeSound() const = 0;
	
	protected:
		std::string type_;
	
};

#endif