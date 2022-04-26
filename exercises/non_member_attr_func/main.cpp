#include "Sample.class.hpp"

void	f1(void) {

	Sample instance;
	std::cout << "Number of instances: " << Sample::getNbInst() << std::endl;
	return;
}

void	f0(void) {

	Sample instance;
	std::cout << "Number of instances: " << Sample::getNbInst() << std::endl;
	f1();
	return;
}

int	main(void) {
	
	std::cout << "Number of instances: " << Sample::getNbInst() << std::endl; //I use Sample instead of instance because getNbInst is a non member function
	f0();
	std::cout << "Number of instances: " << Sample::getNbInst() << std::endl;
	return 0;
}