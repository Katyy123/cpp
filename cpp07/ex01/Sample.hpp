#ifndef SAMPLE_HPP
# define SAMPLE_HPP

#include <iostream>

class Sample
{
    public:
        Sample( void ) : _n( 42 ) {}
        int get( void ) const { return this->_n; }

    private:
        int _n;
};

std::ostream & operator<<( std::ostream & o, Sample const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; }

#endif