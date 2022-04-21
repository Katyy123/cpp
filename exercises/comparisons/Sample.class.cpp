#include "Sample.class.hpp"

Sample::Sample(int n) : _foo(n) {

	std::cout << "Constructor called" << std::endl;
	return;
}

Sample::~Sample(void) {

	std::cout << "Destructor called" << std::endl;
	return;
}

int	Sample::getFoo(void) const {

	return this->_foo;
}

int	Sample::compare(Sample *other) const {

	if (this->_foo > other->getFoo())
		return 1;
	if (this->_foo < other->getFoo())
		return -1;
	return 0;
}