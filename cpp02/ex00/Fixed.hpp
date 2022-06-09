/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:22:31 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/09 18:22:32 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

	public:
		Fixed();
		Fixed(Fixed const & instance);
		~Fixed();
		Fixed & operator=(Fixed const & instance);

		int getRawBits( void ) const;
		void setRawBits( int const raw );

	private:
		int	_n;
		static const int _FractBits;

};

#endif