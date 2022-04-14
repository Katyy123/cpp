#include <iostream>

//using namespace std;

int main(void)
{
	char	buff[512];
	std::cout << "Hello World!" << std::endl;
	std::cout << "Input a word: ";
	std::cin >> buff;
	std::cout << "You typed: [" << buff << "]" << std::endl; 
	return 0;
}