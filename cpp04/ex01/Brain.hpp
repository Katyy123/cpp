/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:09:46 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/20 18:59:45 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

#define ANIMALS_NUM 4

class Brain {

	private:
		static const int	_ideasNum = 100;
	
	public:
		Brain();
		Brain(Brain const & brain);
		virtual ~Brain();

		Brain & operator=(Brain const & brain);

		std::string _ideas[Brain::_ideasNum];
		
};

#endif