/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:07:20 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/23 16:07:21 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <stdexcept>
# include <cstdlib>
//# include <iomanip>
//# include <string>
# include "Bureaucrat.hpp"
# include "Form.hpp"

class RobotomyRequestForm : public AForm {

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const & form);
        ~RobotomyRequestForm();

        RobotomyRequestForm & operator=(RobotomyRequestForm const & form);

    protected:
		virtual void executeConcrete() const;
	
};

std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & form);

#endif