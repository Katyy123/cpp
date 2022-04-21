#include "Sample.class.hpp"

int	main(void) {

	Sample instance;
	instance.publicFoo = 42;
	//instance._privateFoo = 42; //not accessible
	std::cout << "instance.publicFoo: " << instance.publicFoo << std::endl;
	instance.publicFunct();
	//instance._privateFunct(); //not accessible
	return 0;
}