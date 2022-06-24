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

    if (this == &intern){}
    return *this;
}

const char * Intern::FormNotFoundException::what() const throw() {

    return "Form not found";
}

AForm * Intern::makeForm(std::string formName, std::string target) {

    try {
        for (int i = 0; i < 3; i++)
            if (formNameArr[i] == formName) {
                std::cout << "Intern creates " << formName << " form" << std::endl;
                return (this->*(ptr_to_func[i]))(target);
            }
        throw  FormNotFoundException();
    }
    catch (FormNotFoundException & e){
        std::cout << e.what() << std::endl;
        return NULL;
    }
}

AForm *	Intern::ShrubberyCreation(const std::string & target) const {

    return new ShrubberyCreationForm(target);
}

AForm *	Intern::RobotomyRequest(const std::string & target) const {

    return new RobotomyRequestForm(target);
}

AForm *	Intern::PresidentialPardon(const std::string & target) const {

    return new PresidentialPardonForm(target);
}

const std::string Intern::formNameArr[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
const ptrToFunc Intern::ptr_to_func[3] = {&Intern::ShrubberyCreation, &Intern::RobotomyRequest, &Intern::PresidentialPardon};