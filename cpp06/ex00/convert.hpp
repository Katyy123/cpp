#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>
#include <limits>
#include <climits>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <iomanip>
//#include <ios>
#include <cmath>

#define FLOAT_MAX       3.40282e+38
#define FLOAT_MIN       1.17549e-38
#define FLOAT_LOWEST    -3.40282e+38
#define DOUBLE_MAX      1.79769e+308
#define DOUBLE_MIN      2.22507e-308
#define DOUBLE_LOWEST   -1.79769e+308

class Convert {

    public:
        Convert();
        Convert(Convert const & convert);
        ~Convert();

        Convert const & operator=(Convert const convert);

    private:


};

void ft_convert_char(std::string str);
void ft_convert_int(char *char_str, std::string str);
void wrong_arg();

#endif