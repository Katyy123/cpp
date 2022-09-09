#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template< typename T >
class Array {

    public:
        Array() : _array(NULL), _size(0) {}
        Array(unsigned int n) : _size(n) {
            // try {
            //     if (!(n >= 0 && n <= 4294967295))
            //         throw std::exception();
                this->_array = new T[_size];
            // }
            // catch (std::exception & e) {
            //     std::cout << "Invalid size: " << e.what() << std::endl;
            // }
        }
        // Array(T const & array) {

        // }

        ~Array() {
            delete [] this->_array;
        }

        Array & operator=(Array const & array) {

        }

        T & operator[](unsigned int index) {

            try {
                if (!(index >= 0 && index < this->_size ))
                    throw std::exception();
                //return (this->_array[index]);
            }
            catch (std::exception & e) {
                std::cout << "Index out of bounds: " << e.what() << std::endl;
                return (this->_array[this->_size - 1]);
            }
            //return (this->_array[index]);
            return (this->_array[this->_size - 1]);
        }

        unsigned int size(void) const {
            return this->_size;
        }

        T* getArrayAddress(void) const {
            return this->_array;
        }

    private:
        T*              _array;
        unsigned int    _size;

};

#endif