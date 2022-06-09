/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:33:12 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/09 21:05:19 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {

	public:
		Fixed();
		Fixed(const int integer);
		Fixed(const float floatNum);
		Fixed(Fixed const & instance);
		~Fixed();
		
		Fixed & operator=(Fixed const & instance);
		bool operator>(Fixed const & instance) const;
		bool operator<(Fixed const & instance) const;
		bool operator>=(Fixed const & instance) const;
		bool operator<=(Fixed const & instance) const;
		bool operator==(Fixed const & instance) const;
		bool operator!=(Fixed const & instance) const;

		Fixed operator+(Fixed const & instance) const;
		Fixed operator-(Fixed const & instance) const;
		Fixed operator*(Fixed const & instance) const;
		Fixed operator/(Fixed const & instance) const;

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		float toFloat( void ) const;
		int toInt( void ) const;

	private:
		int	_value;
		static const int _FractBits;

};

std::ostream & operator<<(std::ostream & o, Fixed const & instance);

#endif