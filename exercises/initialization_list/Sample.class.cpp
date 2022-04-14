#include "Sample.class.hpp"

Sample::Sample(char p, int q, float r) : a(p), b(q), c(r) {

	std::cout << "Constructor called" << std::endl;
	std::cout << "this->a: " << this->a << std::endl;
	std::cout << "this->b: " << this->b << std::endl;
	std::cout << "this->c: " << this->c << std::endl;
}

Sample::~Sample(void) {

	std::cout << "Destructor called" << std::endl;
}