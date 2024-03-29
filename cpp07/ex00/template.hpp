#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

#include <iostream>

template< typename T >
void swap(T & x, T & y) {

    T z;

    z = x;
    x = y;
    y = z;
}

template< typename T >
T const & min(T const & x, T const & y) {

    return (x < y ? x : y);
}

template< typename T >
T const & max(T const & x, T const & y) {

    return (x > y ? x : y);
}

#endif