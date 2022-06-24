#ifndef INTERN_HPP
#define INTERN_HPP

# include <iostream>
# include "Bureaucrat.hpp"
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {

    public:
        Intern();
        Intern(Intern const &intern);
        ~Intern();

        Intern &operator=(Intern const &intern);
        
        AForm * makeForm(std::string formName, std::string target);
};

#endif