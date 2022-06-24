#ifndef INTERN_HPP
#define INTERN_HPP

# include <iostream>
# include "Bureaucrat.hpp"
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern;

typedef AForm * (Intern::*ptrToFunc)(const std::string&) const;

class Intern {

    public:
        Intern();
        Intern(Intern const &intern);
        ~Intern();

        Intern & operator=(Intern const &intern);
        
        AForm * makeForm(std::string formName, std::string target);

        class FormNotFoundException : public std::exception {
            public:
                virtual const char * what() const throw();
        };

    private:
        AForm *	ShrubberyCreation(const std::string & target) const;
		AForm *	RobotomyRequest(const std::string & target) const;
		AForm *	PresidentialPardon(const std::string & target) const;

        static const std::string    formNameArr[3];
        static const ptrToFunc      ptr_to_func[3];
};

#endif