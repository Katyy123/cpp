/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:23:51 by cfiliber          #+#    #+#             */
/*   Updated: 2022/05/09 15:02:50 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <cctype>

#define MAX_CONTACTS 8


class Contact {

public:
	Contact(void);
	~Contact(void);
	
	std::string	get_name(void) const;
	std::string	get_last_name(void) const;
	std::string	get_nickname(void) const;
	std::string	get_phone(void) const;
	std::string	get_secret(void) const;
	
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
	Contact _arr_contacts[MAX_CONTACTS];
	int		_contacts_num;
	void	_update_contacts_arr(const Contact contact);
	
	void	_ft_search(void) const;
	void	_print_index(int index) const;
	void	_print_name(int index) const;
	void	_print_last_name(int index) const;
	void	_print_nickname(int index) const;
	void	_search_specif_contact(void) const;
	int		_ft_is_numeric(std::string str) const;
	int		_ft_atoi(std::string str) const;
	int		_is_toobig(std::string str) const;
	
	void	_ft_exit(void) const;
};


#endif