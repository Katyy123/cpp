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