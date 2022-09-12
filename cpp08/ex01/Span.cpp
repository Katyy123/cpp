#include "Span.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

Span::Span() {

}

Span::Span(unsigned int N) : _N(N) {

    // if (!N)
	// 	throw InvalidSizeException();
}

Span::Span(Span const & span) {

    //this->_numbers.clear();
    *this = span;
}

Span & Span::operator=(Span const & span) {

    if (this != &span) {
        this->_N = span._N;
        this->_numbers = span._numbers;
    }
    return *this;
}

Span::~Span() {

}

void Span::addNumber(unsigned int n) {

    if (this->_numbers.size() == this->_N)
        throw FullSpanException();
    this->_numbers.push_back(n);
}

unsigned int Span::shortestSpan() {

    if (this->_numbers.size() < 2)
        throw NoSpanCanBeFoundException();
}

unsigned int Span::longestSpan() {

    unsigned int min;
    unsigned int max;

    if (this->_numbers.size() < 2)
        throw NoSpanCanBeFoundException();
    min = *std::min_element(this->_numbers.begin(), this->_numbers.end());
    max = *std::max_element(this->_numbers.begin(), this->_numbers.end());
    return (max - min);
}

const char * Span::FullSpanException::what() const throw() {

    return "Span is full";
}

const char * Span::NoSpanCanBeFoundException::what() const throw() {

    return "No Span ca be found";
}