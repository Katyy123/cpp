#include "Sample.class.hpp"

Sample::Sample(void) {

	std::cout << "Constructor called" << std::endl;
	this->publicFoo = 0;
	std::cout << "this->publicFoo: " << this->publicFoo << std::endl;
	this->_privateFoo = 0;
	std::cout << "this->_privateFoo: " << this->_privateFoo << std::endl; 
	this->publicFunct();
	this->_privateFunct();
}

Sample::~Sample(void) {

	std::cout << "Destructor called" << std::endl;
	return;
}

void	Sample::publicFunct(void) {

	std::cout << "publicFunct called" << std::endl;
	return;
}

void	Sample::_privateFunct(void) {

	std::cout << "_privateFunct called" << std::endl;
	return;
}