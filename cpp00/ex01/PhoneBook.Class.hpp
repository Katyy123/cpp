/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:23:51 by cfiliber          #+#    #+#             */
/*   Updated: 2022/04/28 19:31:31 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include <iostream>
# include <string>

class Contact {

private:


public:
	Contact(void);
	~Contact(void);
};


class PhoneBook {

private:
	Contact *array_of_contacts;

public:
	PhoneBook(void);
	~PhoneBook(void);
};

#endif