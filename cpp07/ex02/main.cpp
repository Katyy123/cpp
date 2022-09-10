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

    //Array< Array<int> > arr1(3);
    Array<std::string> arr3(3);
    //Array<int> arr1(3);
    // Array<char const *> arr1(3);
    // Array<char const *> arr2(2);
    

    //Array< Array<int> > arr2(3);

    // arr1[0] = 'a';
    // arr1[1] = 'b';
    //arr1[-2] = 'c';

    //arr1[3] = 1;
    // arr1[1] = 2;
    // arr1[2] = 3;

    // arr1[0] = "hey";
    // arr1[1] = "ciao";
    // arr1[2] = "mondo";

    // arr1[0] = Array<int>(2);
    // arr1[1] = Array<int>(2);
    // arr1[2] = Array<int>(2);

    // arr1[0][0] = 8;

    // Array< Array<int> > arr2(arr1);
    //Array<int> arr2(arr1);

    // arr2[0] = Array<int>(2);
    // arr2[1] = Array<int>(2);
    // arr2[2] = Array<int>(2);

    

    std::cout << "arr3: " << arr3 << std::endl;

    //Array<char const *> arr2(arr1);
    //Array<int> arr2(arr1);
    //arr2 = arr1;
    

    //std::cout << "arr2: " << arr2 << std::endl;

    //arr1[0] = "bye";
    //arr1[0] = 4;
    //arr1[0][0] = 7;
    

    // std::cout << "arr1: " << arr1 << std::endl;
    // std::cout << "arr2: " << arr2 << std::endl;

    // arr1[0] = Array<int>(2);
    // arr1[1] = Array<int>(2);
    // arr1[2] = Array<int>(2);

    std::cout << "size: " << arr3.size() << std::endl;
    //std::cout << "Array address: " << arr1.getArrayAddress() << std::endl;

    // std::cout << arr1 << std::endl;
    //std::cout << arr2 << std::endl;

    //arr1[4] = 37;
    // arr1[5] = 4;
    // std::cout << arr1[5] << std::endl;

    
}