#include "Sed_is_for_losers.hpp"

bool    fileCheck(std::ifstream& filestream) {

    if (!filestream.is_open()) {
        std::cerr << "Error: The file doesn't exist or can't be opened" << std::endl;
        return 0;
    }
    if (filestream.peek() == EOF) {
        std::cerr << "Error: The file is empty" << std::endl;
        filestream.close();
        return 0;
    }
    return 1;
}

bool    argCheck1(std::string str) {

    if (str.empty()) {
        std::cerr << "Error: The string to be replaced can't be empty" << std::endl;
        return 0;
    }
    for (long unsigned i = 0; i < str.length(); i++) {
        if (!std::isprint(str[i])) {
            std::cerr << "Error: Bad arguments" << std::endl;
            return 0;
        }
    }
    return 1;
}

bool    argCheck2(std::string str) {

    for (long unsigned i = 0; i < str.length(); i++) {
        if (!std::isprint(str[i])) {
            std::cerr << "Error: Bad arguments" << std::endl;
            return 0;
        }
    }
    return 1;
}

int main(int argc, char** argv) {

    if (argc != 4) {
        std::cerr << "Error: Wrong number of arguments" << std::endl;
        return EXIT_FAILURE;
    }

    std::string infile(argv[1]);
    std::string s1(argv[2]);
    std::string s2(argv[3]);
    
    if (!argCheck1(infile) || !argCheck1(s1) || !argCheck2(s2))
        return EXIT_FAILURE;
    
    std::ifstream   in_stream;
    in_stream.open(argv[1], std::ios_base::in);

    if (!fileCheck(in_stream))
        return EXIT_FAILURE;

    if (!ft_replace(infile, in_stream, s1, s2))
        return EXIT_FAILURE;

    in_stream.close();

    return EXIT_SUCCESS;
}