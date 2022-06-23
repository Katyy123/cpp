#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
//# include "Form.hpp"

class Form;

class Bureaucrat {

    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat const & bureaucrat);
        ~Bureaucrat();

        Bureaucrat & operator=(Bureaucrat const & bureaucrat);

        std::string const & getName() const;
        int getGrade() const;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        void incrementGrade();
        void decrementGrade();

        void signForm(Form const & form);

    private:
        const std::string _name;
        int _grade;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & bureaucrat);

#endif