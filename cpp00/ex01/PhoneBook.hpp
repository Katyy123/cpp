/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:23:51 by cfiliber          #+#    #+#             */
/*   Updated: 2022/04/29 19:29:36 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>


class Contact {

public:
	Contact(void);
	~Contact(void);
	std::string	get_first_name(void) const;
	std::string	get_last_name(void) const;
	std::string	get_nickname(void) const;
	std::string	get_phone_num(void) const;
	std::string	get_dark_secret(void) const;
	void	set_first_name(std::string buff);
	void	set_last_name(std::string buff);
	void	set_nickname(std::string buff);
	void	set_phone_num(std::string buff);
	void	set_dark_secret(std::string buff);

private:
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_num;
	std::string	_dark_secret;
};


class PhoneBook {

public:
	PhoneBook(void);
	~PhoneBook(void);
	void	check_command(std::string buff);
	void	ft_add(void);
	void	ft_search(void);//probably to modify
	void	ft_exit(void);//probably to modify

private:
	//Contact *_arr_contacts;

};


#endif