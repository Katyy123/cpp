#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template< typename T >
void iter(T *array, size_t arr_len, void (*arr_funct)(T const & arr_elem)) {

    for (size_t i = 0; i < arr_len ; i++)
        (*arr_funct)(array[i]);
}

#endif