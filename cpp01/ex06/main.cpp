#include "Harl.hpp"

void    ft_switch(int idx, Harl& harl) {

    switch(idx) {
        case 0:
            harl.debug();
            ft_switch(idx++, harl);
            break;
        case 1:
            harl.info();
            ft_switch(idx++, harl);
            break;
        case 2:
            harl.warning();
            ft_switch(idx++, harl);
            break;
        case 3:
            harl.error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}

int main(int argc, char **argv) {

    Harl harl;
    std::string     level_arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    std::string*    level_arr_ptr;
    int             idx;
    std::string level(argv[1]);
    
    harl.just_to_use_argc = argc;
    level_arr_ptr = std::find(level_arr, level_arr + 3, level);
    idx = level_arr - level_arr_ptr;
    ft_switch(idx, harl);
    
    return 0;
}