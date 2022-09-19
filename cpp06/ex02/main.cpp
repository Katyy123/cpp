#include <iostream>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {

    //It randomly instanciates A, B or C and returns the instance as a Base pointer

    int index;
    std::string arr[3] = {"A", "B", "C"};
    srand(time(NULL));
    index = rand() % 3;
    if (index == 0) {
        A* a = new A();
        std::cout << "Instantiated A" << std::endl;
        Base* base = a;
        return base;
    }
    else if (index == 1) {
        B* b = new B();
        std::cout << "Instantiated B" << std::endl;
        Base* base = b;
        return base;
    }
    else {
        C* c = new C();
        std::cout << "Instantiated C" << std::endl;
        Base* base = c;
        return base;
    }
}

void identify(Base* p) {

//It prints the actual type of the object pointed to by p: "A", "B" or "C".

    if(dynamic_cast<A *>(p) != NULL)
        std::cout << "A" << std::endl;
    else if(dynamic_cast<B *>(p) != NULL)
        std::cout << "B" << std::endl;
    else
        std::cout << "C" << std::endl;

}

void identify(Base& p) {

    //It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
//inside this function is forbidden.
    try {
        (void)dynamic_cast<A &>(p); 
        std::cout << "A" << std::endl;
    }
    catch (std::exception & e) {
        try {
            (void)dynamic_cast<B &>(p);
            std::cout << "B" << std::endl;
        }
        catch (std::exception & e2) {
            std::cout << "C" << std::endl;
        }
    }
}

int main() {

        Base* base = generate();
        identify(base);
        identify(*base);
        delete base;
}