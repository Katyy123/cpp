#include "Harl.hpp"

Harl::Harl() {

    std::cout << "An Harl has been born" << std::endl;
}

Harl::~Harl() {

    std::cout << "An Harl has died" << std::endl;
}

void Harl::debug( void ) {

    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void ) {

    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning( void ) {

    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ) {

    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level ) {

    t_level_ptr     table[4] = {{"DEBUG", &Harl::debug}, {"INFO", &Harl::info}, {"WARNING", &Harl::warning}, {"ERROR", &Harl::error}};
    std::string     level_arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    std::string*    level_arr_ptr;
    int             index;
    void            (Harl::*ptr)();

    level_arr_ptr = std::find(level_arr, level_arr + 4, level);
    index = level_arr_ptr - level_arr;

    ptr = table[index].f;
    std::cout << "[" << level << "]" << std::endl;
    (this->*ptr)();
}