#include "Sample.class.hpp"

Sample::Sample(float const c) : a(c), b(42) {

	std::cout << "Constructor called" << std::endl;
	//this->a = 2.7; //dà errore perché a è const
	return;
}

Sample::~Sample(void) {

	std::cout << "Destructor called" << std::endl;
	return;
}

void Sample::bla(void) const {

	std::cout << "this->a: " << this->a << std::endl;
	std::cout << "this->b: " << this->b << std::endl;
	//this->b = 8; //dà errore perchee la funzione bla è const
	return;
}