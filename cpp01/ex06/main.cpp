#include "Harl.hpp"

void    ft_switch(int idx, Harl& harl) {

    switch(idx) {
        case 0:
            harl.debug();
            harl.info();
            harl.warning();
            harl.error();
            break;
        case 1:
            harl.info();
            harl.warning();
            harl.error();
            break;
        case 2:
            harl.warning();
            harl.error();
            break;
        case 3:
            harl.error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            std::cout << std::endl;
    }
}

int main(int argc, char **argv) {

    switch(argc) {

        case 1:
            std::cout << "Error: too few arguments" << std::endl;
            return 1;
        default:
            std::cout << "Error: too many arguments" << std::endl;
            return 1;
        case 2:
            Harl            harl;
            std::string     level_arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
            std::string*    level_arr_ptr;
            int             idx;
            std::string     level(argv[1]);
            
            level_arr_ptr = std::find(level_arr, level_arr + 4, level);
            idx = level_arr_ptr - level_arr;
            ft_switch(idx, harl);
            return 0;   
    }
}