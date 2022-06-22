#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Form {

    public:
        Form();
        Form(std::string name, int gradeToSign, int gradeToExec);
        Form(Form const & form);
        ~Form();

        Form & operator=(Form const & form);

        std::string const & getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExec() const;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char * what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char * what() const throw();
        };

        void beSigned(Bureaucrat & bureaucrat);

    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExec;
};

std::ostream & operator<<(std::ostream & o, Form const & form);

#endif