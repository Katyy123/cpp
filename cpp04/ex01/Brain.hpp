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
	
	public:
		Brain();
		Brain(Brain const & brain);
		~Brain();

		Brain & operator=(Brain const & brain);

		void printIdeas(void) const;
		void setIdea(std::string idea);

	private:
		static const int	_ideasNum = 100;
		std::string _ideas[Brain::_ideasNum];
		int _index;
		
};

#endif