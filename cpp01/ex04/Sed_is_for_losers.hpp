#ifndef SED_IS_FOR_LOSERS_HPP
# define SED_IS_FOR_LOSERS_HPP

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

#include <iostream>
#include <fstream>
#include <cctype>

bool    fileCheck(std::ifstream& filestream);
bool    argCheck1(std::string str);
bool    argCheck2(std::string str);
bool    ft_replace(std::string infile, std::ifstream& in_stream, std::string s1, std::string s2);


#endif