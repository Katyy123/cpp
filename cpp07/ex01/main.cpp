#include "iter.hpp"
#include "Sample.hpp"
#include <string>
#include <iostream>

int main() {

    int         arr1[] = { 0, 1, 2, 3};
    Sample      arr2[3];
    float       arr3[] = {0.21, 0.42};
    std::string arr4[] = {"Ciao", "Mondo"};

    iter( arr1, 4, print );
    std::cout << std::endl;
    iter( arr2, 3, print );
    std::cout << std::endl;
    iter( arr3, 2, print );
    std::cout << std::endl;
    iter( arr4, 2, print );

    return 0;
}