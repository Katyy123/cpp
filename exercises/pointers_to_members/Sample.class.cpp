#include "Sample.class.hpp"

Sample::Sample(void) {

	std::cout << "Constructor called" << std::endl;
	return;
}

Sample::~Sample(void) {

	std::cout << "Destructor called" << std::endl;
	return;
}

void	Sample::bar(void) const {

	std::cout << "Bar function called" << std::endl;
	return;
}