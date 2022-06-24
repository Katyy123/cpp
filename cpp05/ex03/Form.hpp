/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:07:30 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/23 20:47:24 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class AForm {

    public:
        AForm();
        AForm(std::string name, std::string target, int gradeToSign, int gradeToExec);
        AForm(AForm const & form);
        ~AForm();

        AForm & operator=(AForm const & form);

        std::string const & getName() const;
        std::string getTarget() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExec() const;

        void setTarget(std::string target);
        void setIsSigned(bool isSigned);

        class GradeTooHighException : public std::exception {
            public:
                virtual const char * what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char * what() const throw();
        };

        class FormNotSignedException : public std::exception {
            public:
                virtual const char * what() const throw();
        };

        void beSigned(Bureaucrat & bureaucrat);
        void execute(Bureaucrat const & executor) const;
        
    protected:
        virtual void executeConcrete() const = 0; 

    private:
        const std::string _name;
        std::string _target;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExec;
};

std::ostream & operator<<(std::ostream & o, AForm const & form);

#endif