#include "serialize.hpp"
#include "data.hpp"

int main() {
    
    Data data;
    Data *ptr = &data;
    Data *ptr2;
    uintptr_t raw;

    data.n = 42;
    std::cout << "data ptr: " << ptr->n << std::endl;
    std::cout << "address ptr: " << ptr << std::endl;
    raw = serialize(ptr);
    ptr2 = deserialize(raw);
    if (ptr == ptr2 && ptr->n == ptr2->n) {
        std::cout << "data ptr2: " << ptr2->n << std::endl;
        std::cout << "address ptr2: " << ptr2 << std::endl;
        std::cout << "The functions work as expected" << std::endl;
        return EXIT_SUCCESS;
    }
    else {
        std::cout << "The functions don't work as expected" << std::endl;
        return EXIT_FAILURE;
    }

}