#ifndef SAMPLE_CLASS_HPP
# define SAMPLE_CLASS_HPP

#include <iostream>

class Sample {

    public:
        Sample(void) : _n(0) {}
        Sample(int n) : _n(n) {}

        Sample & operator= (Sample & a) { _n = a._n; return *this; }
        bool operator==( Sample const & sample ) const { return (this->_n == sample._n); }
        bool operator!=( Sample const & sample ) const{ return (this->_n != sample._n); }
        bool operator>( Sample const & sample ) const { return (this->_n > sample._n); }
        bool operator<( Sample const & sample ) const { return (this->_n < sample._n); }
        bool operator>=( Sample const & sample ) const { return (this->_n >= sample._n); }
        bool operator<=( Sample const & sample ) const { return (this->_n <= sample._n); }

        int get_n() const { return _n; }

    private:
        int _n;
};

std::ostream & operator<<(std::ostream & o, const Sample &a) { o << a.get_n(); return o; }

#endif