/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:23:51 by cfiliber          #+#    #+#             */
/*   Updated: 2022/05/05 16:45:42 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <cctype>

#define MAX_CONTACTS 100

class Contact {

public:
	Contact(void);
	~Contact(void);
	std::string	get_name(void) const;
	std::string	get_last_name(void) const;
	std::string	get_nickname(void) const;
	std::string	get_phone(void) const;
	std::string	get_secret(void) const;
	// void	set_name(std::string buff);
	// void	set_last_name(std::string buff);
	// void	set_nickname(std::string buff);
	// void	set_phone(std::string buff);
	// void	set_secret(std::string buff);
	void		add_contact_fields(void);

private:
	std::string	_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone;
	std::string	_secret;
	void		_check_add_command(std::string buff, std::string field);
};

class PhoneBook {

public:
	PhoneBook(void);
	~PhoneBook(void);
	void	check_command(std::string buff);

private:
	void	_ft_add(void);
	void	_ft_search(void);//probably to modify
	void	_ft_exit(void);//probably to modify
	int		_contacts_counter(void) const;
	Contact _arr_contacts[MAX_CONTACTS];
	int		_index;
	void	_update_contacts_arr(const Contact& contact);
	//Contact *_contacts_list;
};


#endif