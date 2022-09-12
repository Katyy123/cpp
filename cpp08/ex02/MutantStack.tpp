#include "MutantStack.hpp"

template< typename T >
MutantStack<T>::MutantStack() : std::stack<T>() {

}

template< typename T >
MutantStack<T>::MutantStack(MutantStack<T> const & mutant_stack) : std::stack<T>(mutant_stack) {

}

template< typename T >
MutantStack<T> & MutantStack<T>::operator=(MutantStack<T> const & mutant_stack) {

    if (this != &mutant_stack)
        static_cast< std::stack<T> >(*this) = static_cast< std::stack<T> >(mutant_stack);
    return *this;
}

template< typename T >
MutantStack<T>::~MutantStack() {

}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin() {
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end() {
	return this->c.end();
}