#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

template< typename T >
class Array {

    public:
        Array() : _array(NULL), _size(0) {
            std::cout << "Default constructor called" << std::endl;
        }

        Array(unsigned int n) : _array(NULL), _size(n) {
            this->_array = new T[_size];
            std::cout << "Parametric constructor called" << std::endl;
        }

        Array(Array const & array) {
            this->_array = new T[array._size];
            *this = array;
            std::cout << "Copy constructor called" << std::endl;
        }

        ~Array() {
            delete [] this->_array;
            std::cout << "Destructor called" << std::endl;
        }

        class OutOfBoundsException: public std::exception {
            virtual const char* what() const throw() {
                return "ArrayException: index out of bounds";
            }
        };

        Array & operator=(Array const & array) {
            if (this != &array) {
                this->_size = array._size;
                delete [] this->_array;
                this->_array = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                    this->_array[i] = array._array[i];
            }
            std::cout << "Assignment operator called" << std::endl;
            return *this;
        }

        T & operator[](unsigned int index) const {
            if (index < 0 || index >= this->_size)
                throw Array::OutOfBoundsException();
            return (this->_array[index]);
        }

        unsigned int size(void) const {
            return this->_size;
        }

        // T* getArrayAddress(void) const {
        //     return this->_array;
        // }

    private:
        T*              _array;
        unsigned int    _size;

};

template< typename T>
std::ostream & operator<<(std::ostream & o, Array<T> const & array) {
    if (array.size() > 0) {
        o << "Elements of the array: { ";
        for (unsigned int i = 0; i < array.size() - 1; i++)
            o << array[i] << ", ";
        o << array[array.size() - 1];
        o << " }" << std::endl;
    }
    else
        o << "No elements" << std::endl;
    return o;
}

#endif