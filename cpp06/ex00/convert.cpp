#include "convert.hpp"

void wrong_arg() {

    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

void ft_convert_char(std::string str) {

    char c = static_cast<char>(str[0]);
    std::cout << "char: " << "'" << c << "'" << std::endl;
    int int_n = static_cast<int>(c);
    std::cout <<"int: " << int_n << std::endl;
    float float_n = static_cast<float>(c);
    std::cout << std::setprecision(1) << "float: " << float_n << "f" << std::endl;
    double double_n = static_cast<double>(c);
    std::cout << std::setprecision(1) << "double: " << double_n << std::endl;
}

void ft_convert_int(std::string str) {

    std::stringstream   ss;
    long long int       long_n;
    int                 int_n;

    ss << str;
    ss >> long_n;
    if (long_n > INT_MAX || long_n < INT_MIN) {
        wrong_arg();
        exit(EXIT_FAILURE);
    }
    int_n = static_cast<int>(long_n);
    if (int_n >= 32 && int_n <= 126) { 
        char c = static_cast<char>(int_n);
        std::cout << "char: " << "'" << c << "'" << std::endl;
    }
    else    
        std::cout << "char: " << "Non displayable" << std::endl;
    std::cout <<"int: " << int_n << std::endl;
    float float_n = static_cast<float>(int_n);
    std::cout <<"float: " << float_n << ".0f" << std::endl;
    double double_n = static_cast<double>(int_n);
    std::cout <<"double: " << double_n << ".0" << std::endl;
}

void ft_convert_float(std::string str) {

    std::stringstream   ss;
    //long float     long_float_n;
    float               float_n;

    ss << str;
    //ss >> long_float_n;
    ss >> float_n;
    // if (long_float_n > FLOAT_MAX || long_float_n < FLOAT_LOWEST || (long_float_n < FLOAT_MIN && long_float_n > -FLOAT_MIN)) {
    //     wrong_arg();
    //     exit(EXIT_FAILURE);
    // }
    // float_n = static_cast<float>(long_float_n);
    if (float_n >= 32 && float_n < 127) { 
        char c = static_cast<char>(float_n);
        std::cout << "char: " << "'" << c << "'" << std::endl;
    }
    else    
        std::cout << "char: " << "Non displayable" << std::endl;
    int int_n = static_cast<int>(float_n);
    std::cout << "int: " << int_n << std::endl;
    std::cout << std::setprecision(3) << "float: " << float_n << "f" << std::endl;
    double double_n = static_cast<double>(float_n);
    std::cout << std::setprecision(3) << "double: " << double_n << std::endl;
}

void ft_convert(std::string str, char * char_str) {

    bool is_not_int = 0;
    bool is_there_point = 0;

    for (long unsigned int i = 0; i < str.length(); i++) {
        if (std::isprint(str[i]) == 0) {
            wrong_arg();
            exit(EXIT_FAILURE);
        }
        if (i > 0 && std::isdigit(str[i]) == 0)
            is_not_int = 1;
        if (str[i] == '.')
            is_there_point = 1;
    }
    if (str.length() == 1 && !std::isdigit(str[0]))
        ft_convert_char(str);
    else if (is_not_int == 0 && std::atoi(char_str) != 0)
            ft_convert_int(str);
    else if (is_there_point == 1 && str[str.length() - 1] == 'f' && std::atof(char_str) != 0.0)
        ft_convert_float(str);
}

int main(int argc, char **argv) {

    try {
        if (argc == 2) {
            ft_convert(std::string(argv[1]), argv[1]);
        }
        else
            throw std::exception();
    }
    catch (std::exception& e) {
        std::cout <<"Error: bad arguments" << std::endl;
    }
}







































// void	printType(const std::string& type)
// {
// 	std::cout << type << ": ";
// }

// void	cChar(double val)
// {
// 	char	c = static_cast<char>(val);

// 	if (val != val || !isascii(val))
// 		std::cout << "impossible";
// 	else if (isprint(c))
// 		std::cout << "'" << c << "'";
// 	else
// 		std::cout << "Non displayable";
// }

// void	cInt(double val)
// {
// 	int	i = static_cast<int>(val);

// 	if (val != val || val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
// 		std::cout << "impossible";
// 	else
// 		std::cout << i;
// }

// void	cFloat(double val)
// {
// 	float	f = static_cast<float>(val);

// 	std::cout << f << "f";
// }

// int main(int ac, char **av)
// {
// 	if (ac < 2)
// 		return 1;

// 	double	val = atof(av[1]);

// 	std::cout.precision(1);
// 	std::cout << std::fixed;

// 	printType("char");
// 	cChar(val);
// 	std::cout << std::endl;

// 	printType("int");
// 	cInt(val);
// 	std::cout << std::endl;

// 	printType("float");
// 	cFloat(val);
// 	std::cout << std::endl;

// 	printType("double");
// 	std::cout << val << std::endl;
// }
