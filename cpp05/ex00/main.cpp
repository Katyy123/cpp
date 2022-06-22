#include "Bureaucrat.hpp"

int main() {

    Bureaucrat giorgio("Giorgio", 42);
    Bureaucrat claudia("Claudia", 24);
    Bureaucrat michela("Michela", 0);
    Bureaucrat luca("Luca", 151);
    std::cout << std::endl;
    
    std::cout << giorgio;
    std::cout << claudia;
    std::cout << michela;
    std::cout << luca;
    std::cout << std::endl;

    giorgio.incrementGrade();
    std::cout << giorgio;
    claudia.decrementGrade();
    std::cout << claudia;
    michela.incrementGrade();
    std::cout << michela;
    luca.decrementGrade();
    std::cout << luca;
    std::cout << std::endl;

    return 0;
}
