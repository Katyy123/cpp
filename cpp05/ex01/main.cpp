#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {

    Form form_1("form_1", 42, 30);
    Form form_2("form_2", 0, 0);
    Form form_3("form_3", 151, 167);
    Form form_4("form_4", 4, 102);
    std::cout << std::endl;

    Bureaucrat michela("Michela", 40);
    Bureaucrat luca("Luca", 51);
    
    std::cout << form_1;
    std::cout << form_4;

    std::cout << michela;
    std::cout << luca;
    std::cout << std::endl;

    form_1.beSigned(michela);
    form_1.beSigned(luca);
    form_4.beSigned(luca);

    std::cout << form_1;
    std::cout << form_4;

    return 0;
}
