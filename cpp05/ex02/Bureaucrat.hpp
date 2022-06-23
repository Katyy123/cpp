/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:07:35 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/23 20:52:13 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

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

        void signForm(AForm const & form);
        void executeForm(Form const & form);

    private:
        const std::string _name;
        int _grade;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & bureaucrat);

#endif