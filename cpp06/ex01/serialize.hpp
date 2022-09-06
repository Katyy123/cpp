#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

#include <iostream>
#include "data.hpp"
#include <stdint.h>
#include <cstdlib>

int main();
uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif