/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:07:22 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/23 20:48:09 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include <stdexcept>
# include "Bureaucrat.hpp"
# include "Form.hpp"

class ShrubberyCreationForm : public AForm {

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const & form);
        virtual ~ShrubberyCreationForm();

        ShrubberyCreationForm & operator=(ShrubberyCreationForm const & form);

    protected:
		virtual void executeConcrete() const;
	
};

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & form);

#endif