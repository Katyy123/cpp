/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:29:07 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/20 15:54:01 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {

	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const & wrong_animal);
		virtual ~WrongAnimal();

		WrongAnimal & operator=(WrongAnimal const & wrong_animal);

		std::string		getType(void) const;

		void	makeSound() const;
	
	protected:
		std::string type_;
	
};

#endif