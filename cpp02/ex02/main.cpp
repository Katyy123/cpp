/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:33:10 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/10 18:43:22 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
//std::cout << "a._value : " << a.getRawBits() << std::endl;// the result is 1 and not 0.00390625 cause value = 1 (and not 0.00000001), so 1 in base 2 = 1 in base 10
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
//std::cout << "b._value : " << b.getRawBits() << std::endl;//the result is 2586 (instead of 101016) because is simply the value (int) in base 10. With the point, the conversion is different
std::cout << Fixed::max( a, b ) << std::endl;

// std::cout << std::endl;
// Fixed const c( Fixed( 5.05f ) + Fixed( 2 ) );
// std::cout << "c: " << c << std::endl;

// std::cout << std::endl;
// Fixed const d( Fixed( 5.05f ) - Fixed( 2 ) );
// std::cout << "d: " << d << std::endl;

// std::cout << std::endl;
// Fixed const e( Fixed( 5.05f ) / Fixed( 2 ) );
// std::cout << "e: " << e << std::endl;

// std::cout << std::endl;
// std::cout << "Testing min( c, d )..." << std::endl;
// std::cout << Fixed::min( c, d ) << std::endl;

// std::cout << std::endl;
// std::cout << "Testing c > d, c < d, c >= d, c <= d, c == d, c != d..." << std::endl;
// std::cout << (c > d) << std::endl;
// std::cout << (c < d) << std::endl;
// std::cout << (c >= d) << std::endl;
// std::cout << (c <= d) << std::endl;
// std::cout << (c == d) << std::endl;
// std::cout << (c != d) << std::endl;

// std::cout << std::endl;
// std::cout << "Testing a--..." << std::endl;
// std::cout << a-- << std::endl;
// std::cout << a << std::endl;

// std::cout << std::endl;
// std::cout << "Testing --a..." << std::endl;
// std::cout << --a << std::endl;
// std::cout << a << std::endl;
return 0;
}

/* output:

$> ./a.out
0
0.00390625 //because 0.00000001 in base 2 is 0.00390625 in base 10
0.00390625
0.00390625
0.0078125
10.1016
10.1016
$>

*/