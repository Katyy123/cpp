/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:17:58 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/20 15:39:55 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal {

	public:
		Cat();
		Cat(Cat const & cat);
		virtual ~Cat();

		Cat & operator=(Cat const & cat);
		
		virtual void	makeSound() const;
		
};

#endif