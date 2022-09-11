#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iterator>
# include <exception>

class NotFoundException : public std::exception {

    public:
        virtual const char * what() const throw() {
            return "Value not found";
        }
};

template< typename T >
typename T::const_iterator easyfind(T const & x, int n) {

    typename T::const_iterator it;

    it = find(x.begin(), x.end(), n);
    if (it == x.end())
        throw NotFoundException();
    return it;
}

#endif