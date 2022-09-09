#include <iostream>
#include "Array.hpp"
#include <iostream>

#define MAX_VAL 750

// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];

//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }

//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }

//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }

//     delete [] mirror;//
//     return 0;
// }

int main(void) {

    // int * a = new int();

    // std::cout << *a << std::endl;
    // std::cout << 0 << std::endl; 

    // delete a;

    Array<int> arr1(5);
    Array<int> arr2();

    std::cout << "_size: " << arr1.size() << std::endl;
    std::cout << "First element of the _array 1: " << arr1[0] << std::endl;
    //std::cout << "First element of the _array 2: " << arr2[0] << std::endl;

    arr1[4] = 37;
    arr1[5] = 4;
    std::cout << arr1[5] << std::endl;
    
}