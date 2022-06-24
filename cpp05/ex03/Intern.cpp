#include "Intern.hpp"

Intern::Intern() {

    std::cout << "Intern Default constructor called" << std::endl;
}

Intern::Intern(Intern const & intern) {

    std::cout << "Intern Copy constructor called" << std::endl;
    *this = intern;
}

Intern::~Intern() {

    std::cout << "Intern Destructor called" << std::endl;
}

Intern & Intern::operator=(Intern const & intern) {

    return *this;
}

AForm * Intern::makeForm(std::string formName, std::string target) {

    
}