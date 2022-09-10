#include <iostream>
#include "Array.hpp"
#include <cstdlib>

int main(void)
{
    /* ---------- SIMPLE TYPE ---------- */

    std::cout << "---------- SIMPLE TYPE ----------" << std::endl;
    Array<int> int_arr(3);

    int_arr[0] = 1;
    int_arr[1] = 2;
    int_arr[2] = 3;
    std::cout << "int_arr: " << int_arr << std::endl;

    std::cout << "Size: " << int_arr.size() << std::endl;
    std::cout << std::endl;

    /* Copy constructor test with simple type*/

    std::cout << " ----- Copy constructor test ----- " << std::endl;
    Array<int> int_copy1(int_arr);
    std::cout << "int_copy1: " << int_copy1 << std::endl;
    int_arr[2] = 4;
    std::cout << "int_arr: " << int_arr << std::endl;
    std::cout << "int_copy1: " << int_copy1 << std::endl;
    std::cout << std::endl;

    /* Assignment operator test with simple type*/

    std::cout << " ----- Assignment operator test ----- " << std::endl;
    Array<int> int_copy2;
    int_copy2 = int_arr;
    std::cout << "int_copy2: " << int_copy2 << std::endl;
    int_arr[2] = 5;
    std::cout << "int_arr: " << int_arr << std::endl;
    std::cout << "int_copy2: " << int_copy2 << std::endl;
    std::cout << std::endl;

    /* Out of bounds index test with simple type*/

    std::cout << " ----- Out of bounds index test ----- " << std::endl;
    try {
        int_arr[-2] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    try {
        int_arr[3] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;

    /* ---------- COMPLEX TYPE ---------- */

    std::cout << "---------- COMPLEX TYPE ----------" << std::endl;
    Array<std::string> str_arr(3);
    
    str_arr[0] = "Hey";
    str_arr[1] = "Mondo";
    str_arr[2] = "!!";
    std::cout << "str_arr : " << str_arr << std::endl;

    std::cout << "Size: " << str_arr.size() << std::endl;
    std::cout << std::endl;

    /* Copy constructor test with complex type*/

    std::cout << " ----- Copy constructor test ----- " << std::endl;
    Array<std::string> str_copy1(str_arr);
    std::cout << "str_copy1: " << str_copy1 << std::endl;
    str_arr[2] = "??";
    std::cout << "str_arr: " << str_arr << std::endl;
    std::cout << "str_copy1: " << str_copy1 << std::endl;
    std::cout << std::endl;

    /* Assignment operator test with complex type*/

    std::cout << " ----- Assignment operator test ----- " << std::endl;
    Array<std::string> str_copy2;
    str_copy2 = str_arr;
    std::cout << "str_copy2: " << str_copy2 << std::endl;
    str_arr[2] = "££";
    std::cout << "str_arr: " << str_arr << std::endl;
    std::cout << "str_copy2: " << str_copy2 << std::endl;
    std::cout << std::endl;
    
    /* Out of bounds index test with complex type*/

    std::cout << " ----- Out of bounds index test ----- " << std::endl;
    try {
        str_arr[-2] = "ciao";
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    try {
        str_arr[3] = "ciao";
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;

    return 0;
}

//int main(void) {

    // int * a = new int();

    // std::cout << *a << std::endl;
    // std::cout << 0 << std::endl; 

    // delete a;

    //Array< Array<int> > arr1(3);
    //Array<std::string> arr3(3);
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

    

    //std::cout << "arr3: " << arr3 << std::endl;

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

    //std::cout << "size: " << arr3.size() << std::endl;
    //std::cout << "Array address: " << arr1.getArrayAddress() << std::endl;

    // std::cout << arr1 << std::endl;
    //std::cout << arr2 << std::endl;

    //arr1[4] = 37;
    // arr1[5] = 4;
    // std::cout << arr1[5] << std::endl;
//}