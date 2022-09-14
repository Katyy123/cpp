#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>
#include <limits>
#include <climits>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstring>

void wrong_arg();
void ft_convert_char(std::string str);
void ft_convert_int(char *char_str, std::string str);
void ft_convert_float(char* char_str);
void ft_convert_double(std::string str, char* char_str);
void ft_convert(std::string str, char * char_str);
int main(int argc, char **argv);

#endif