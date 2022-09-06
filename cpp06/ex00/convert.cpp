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
    std::cout << std::fixed << std::setprecision(1) << "float: " << float_n << "f" << std::endl;
    double double_n = static_cast<double>(c);
    std::cout << std::fixed << std::setprecision(1) << "double: " << double_n << std::endl;
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
    else if (int_n >= 0 && int_n <= 127)  
        std::cout << "char: " << "Non displayable" << std::endl;
    else
        std::cout << "char: " << "Impossible" << std::endl;
    std::cout <<"int: " << int_n << std::endl;
    float float_n = static_cast<float>(int_n);
    std::cout << std::fixed << std::setprecision(1) <<"float: " << float_n << "f" << std::endl;
    double double_n = static_cast<double>(int_n);
    std::cout << std::fixed << std::setprecision(1) <<"double: " << double_n << std::endl;
}

void ft_convert_float(std::string str, char* char_str) {

    std::stringstream   ss;
    std::stringstream   ss2;
    float               float_n;
    int                 precision = 1;
    long double         long_double_n;

    if (str == "inff" || str == "-inff" || str == "0.0f" || str == "nanf")
        float_n = std::atof(char_str);
    else {
        ss << str;
        ss >> long_double_n;
        if (long_double_n > FLOAT_MAX || long_double_n < FLOAT_MIN ||
                    (long_double_n < FLOAT_LOWEST && long_double_n > -FLOAT_LOWEST)) {
            wrong_arg();
            exit(EXIT_FAILURE);
        }
        ss2 << str;
        ss2 >> float_n;
    }
    if (float_n >= 32 && float_n < 127) { 
        char c = static_cast<char>(float_n);
        std::cout << "char: " << "'" << c << "'" << std::endl;
    }
    else if (float_n >= 0 && float_n <= 127)  
        std::cout << "char: " << "Non displayable" << std::endl;
    else
        std::cout << "char: " << "impossible" << std::endl;
    if (float_n <= INT_MAX && float_n >= INT_MIN) {
        int int_n = static_cast<int>(float_n);
        std::cout << "int: " << int_n << std::endl;
    }
    else
        std::cout << "int: " << "impossible" << std::endl;
    if (std::floor(float_n) != float_n)
        precision = 3;
    std::cout << std::fixed << std::setprecision(precision) << "float: " << float_n << "f" << std::endl;
    double double_n = static_cast<double>(float_n);
    std::cout << std::fixed << std::setprecision(precision) << "double: " << double_n << std::endl;
}

void ft_convert_double(std::string str, char* char_str) {

    std::stringstream   ss;
    std::stringstream   ss2;
    int                 precision = 1;
    long double         long_double_n;
    double              double_n;

    if (str == "inf" || str == "-inf" || str == "0.0" || str == "nan")
        double_n = std::atof(char_str);
    else {
        ss << str;
        ss >> long_double_n;
        if (long_double_n > DOUBLE_MAX || long_double_n < DOUBLE_MIN ||
                    (long_double_n < DOUBLE_LOWEST && long_double_n > -DOUBLE_LOWEST)) {
            wrong_arg();
            exit(EXIT_FAILURE);
        }
        ss2 << str;
        ss2 >> double_n;
    }
    if (double_n >= 32 && double_n < 127) { 
        char c = static_cast<char>(double_n);
        std::cout << "char: " << "'" << c << "'" << std::endl;
    }
    else if (double_n >= 0 && double_n <= 127)  
        std::cout << "char: " << "Non displayable" << std::endl;
    else
        std::cout << "char: " << "impossible" << std::endl;
    if (double_n <= INT_MAX && double_n >= INT_MIN) {
        int int_n = static_cast<int>(double_n);
        std::cout << "int: " << int_n << std::endl;
    }
    else
        std::cout << "int: " << "impossible" << std::endl;
    if (std::floor(double_n) != double_n)
        precision = 3;
    float float_n = static_cast<float>(double_n);
    std::cout << std::fixed << std::setprecision(precision) << "float: " << float_n << "f" << std::endl;
    std::cout << std::fixed << std::setprecision(precision) << "double: " << double_n << std::endl;
}

void ft_convert(std::string str, char * char_str) {

    bool is_not_int = 0;
    bool is_there_point = 0;
    char *end_ptr;

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
    else if (is_not_int == 0 &&
                (std::strtol(char_str, &end_ptr, 10) != 0 ||
                static_cast<long unsigned int>(end_ptr - char_str) == str.length()))
        ft_convert_int(str);
    else if ((is_there_point == 1 && str[str.length() - 1] == 'f' && std::atof(char_str) != 0.0) ||
                str == "inff" || str == "-inff" || str == "0.0f" || str == "nanf")
        ft_convert_float(str, char_str);
    else if ((is_there_point == 1 && std::atof(char_str) != 0.0) ||
                str == "inf" || str == "-inf" || str == "0.0" || str == "nan")
        ft_convert_double(str, char_str);
    else
        wrong_arg();
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