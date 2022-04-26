#include "Sample.class.hpp"

int	main(void) {
	
	Sample instance;
	Sample *instancep = &instance;
	int	Sample::*p = NULL;
	void	(Sample::*f)(void) const;

	p = &Sample::foo;

	std::cout << "Value of member foo: " << instance.foo << std::endl;//I must use instance instead of Sample to specify which instance I'm referring 
	instance.*p = 21;												//every instance can have different values of its attributes
	std::cout << "Value of member foo: " << instance.foo << std::endl;
	instancep->*p = 42;
	std::cout << "Value of member foo: " << instance.foo << std::endl;

	f = &Sample::bar;

	(instance.*f)();
	(instancep->*f)();
	return 0;
}