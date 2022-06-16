/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:17:58 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/16 17:03:20 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal {

	public:
		Cat();
		Cat(std::string type);
		Cat(Cat const & cat);
		~Cat();

		Cat & operator=(Cat const & cat);
		
		virtual void	makeSound();
		
};

#endif