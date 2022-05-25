#include "Sed_is_for_losers.hpp"

bool    fileCheck(std::ifstream& filestream) {

    if (!filestream.is_open()) {
        std::cerr << "Error: The file doesn't exist or can't be opened" << std::endl;
        return 0;
    }
    if (filestream.eof()) { //da sistemare, non dà errore
        std::cerr << "Error: The file is empty" << std::endl;
        filestream.close();
        return 0;
    }
    return 1;
}

bool    argCheck(std::string str) {

    if (str.empty()) {//da sistemare, non funziona
        std::cerr << "Error: Arguments can't be empty" << std::endl;
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

int main(int argc, char** argv) {

    if (argc != 4) {
        std::cerr << "Error: Wrong number of arguments" << std::endl;
        return EXIT_FAILURE;
    }
    
    std::string infile(argv[1]);
    std::string s1(argv[1]);
    std::string s2(argv[1]);

    if (!argCheck(infile) || !argCheck(s1) || !argCheck(s2))
        return EXIT_FAILURE;
    
    //std::ifstream   in_stream(infile);
    std::ifstream   in_stream;
    in_stream.open(argv[1], std::ios_base::in);

    // if (!in_stream.is_open()) {
    //     std::cerr << "Error: The file doesn't exist or can't be opened" << std::endl;
    //     return EXIT_FAILURE;
    // }
    // if (in_stream.eof()) {
    //     std::cerr << "Error: The file is empty" << std::endl;
    //     in_stream.close();
    //     return EXIT_FAILURE;
    // }

    if (!fileCheck(in_stream))
        return EXIT_FAILURE;
    
    //std::ofstream   out(filename);

    // if (!ft_replace(in_stream))
    //     return EXIT_FAILURE;

    in_stream.close();

    return EXIT_SUCCESS;
}