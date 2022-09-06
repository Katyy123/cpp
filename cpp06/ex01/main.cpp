#include "serialize.hpp"
#include "data.hpp"

int main() {
    
    Data *ptr = NULL;
    Data *ptr2;
    uintptr_t raw;

    std::cout << "data: " << ptr->data << std::endl;
    raw = serialize(ptr);
    ptr2 = deserialize(raw);
    if (ptr == ptr2 && ptr->data == ptr2->data) {
        std::cout << "data: " << ptr2->data << std::endl;
        std::cout << "The functions work as expected" << std::endl;
        return EXIT_SUCCESS;
    }
    else {
        std::cout << "The functions don't work as expected" << std::endl;
        return EXIT_FAILURE;
    }

}