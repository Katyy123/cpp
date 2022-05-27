#include "Sed_is_for_losers.hpp"
#include <algorithm>

bool    ft_replace(std::string infile, std::ifstream& in_stream, std::string s1, std::string s2) {

    std::string     line;
    std::ofstream   out_stream;
    std::string     outfile;
    char*           char_outfile;
    std::size_t     pos;

    outfile = infile;
    outfile.append(".replace");
    char_outfile = const_cast<char*>(outfile.c_str());
    out_stream.open(char_outfile, std::ios_base::out);
    if (!out_stream.is_open()) {
        std::cerr << "Error: problem with outfile" << std::endl;
        return 0;
    }
    while (getline(in_stream, line)) {
        while (true) {
            pos = line.find(s1);
            if (pos == std::string::npos) {
                out_stream << line;
                break;
            }
        out_stream << line.substr(0, pos) << s2;
        line = line.substr(pos + s1.length());
        }
        if (in_stream.peek() != EOF)
            out_stream << std::endl;
    }
    if (in_stream.peek() != EOF) {
        std::cerr << "Error: getline" << std::endl;
        out_stream.close();
        return 0;
    }
    out_stream.close();
    return 1;
}