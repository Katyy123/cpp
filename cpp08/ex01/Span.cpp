#include "Span.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

Span::Span() {

}

Span::Span(unsigned int N) : _N(N) {

}

Span::Span(Span const & span) {

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

void	Span::addNumber(std::vector<int>::const_iterator it1, std::vector<int>::const_iterator it2)
{
	while (it1 < it2)
	{
		if (this->_numbers.size() == _N)
			throw FullSpanException();
		this->_numbers.push_back(*it1);
		it1++;
	}
}

unsigned int Span::shortestSpan() {

    unsigned int min_span = -1;
    unsigned int tmp_span;
    std::vector<int> copy(this->_numbers.size());

    std::copy(_numbers.begin(), _numbers.end(), copy.begin());
    
    if (copy.size() < 2)
        throw NoSpanCanBeFoundException();

    std::sort(copy.begin(), copy.end());

    std::vector<int>::const_iterator it;
    std::vector<int>::const_iterator it_end = copy.end();

    for (it = copy.begin(); it != it_end - 1; it++) {
        if ((tmp_span = std::abs(*it - *(it + 1))) < min_span)
            min_span = tmp_span;
    }
    return min_span;
}

unsigned int Span::longestSpan() const {

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

    return "No Span can be found";
}