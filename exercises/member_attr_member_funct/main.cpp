#include "Sample.class.hpp"

int	main() {

	Sample instance;

	instance.foo = 42;
	std::cout << "Instance.foo: " << instance.foo << std::endl;
	instance.f();
	return 0;
	
}