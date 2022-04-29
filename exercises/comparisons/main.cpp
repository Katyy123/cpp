#include "Sample.class.hpp"

int	main(void) {

	Sample instance1(42);
	Sample instance2(42);
	if (&instance1 == &instance1)
		std::cout << "instance 1 and instance1 are phisically equal" << std::endl;
	else
		std::cout << "instance 1 and instance1 are not phisically equal" << std::endl;
	if (&instance1 == &instance2)
		std::cout << "instance 1 and instance2 are phisically equal" << std::endl;
	else
		std::cout << "instance 1 and instance2 are not phisically equal" << std::endl;
	if (instance1.compare(&instance1) == 0)
		std::cout << "instance 1 and instance1 are structurally equal" << std::endl;
	else
		std::cout << "instance 1 and instance1 are not structurally equal" << std::endl;
	if (instance1.compare(&instance2) == 0)
		std::cout << "instance 1 and instance2 are structurally equal" << std::endl;
	else
		std::cout << "instance 1 and instance2 are not structurally equal" << std::endl;
	return 0;
}