/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:01:04 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/16 18:09:02 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
# define DATE_HPP

# include <iostream>

class Date {
	
	public:
		Date(unsigned int year, unsigned int month, unsigned int day);
		Date(Date const & date);
		~Date();

		Date & operator=(Date const & date);

		unsigned int getYear() const;
		unsigned int getMonth() const;
		unsigned int getDay() const;

		void setYear(unsigned int year);
		void setMonth(unsigned int year);
		void setDay(unsigned int year);

		class WrongYearException: public std::exception {
			public:
				const char * what() const throw();
		};

		class WrongMonthException: public std::exception {
			public:
				const char * what() const throw();
		};

		class WrongDayException: public std::exception {
			public:
				const char * what() const throw();
		};
		
	private:
		Date();
		unsigned int _year;
		unsigned int _month;
		unsigned int _day;

};

std::ostream & operator<<(std::ostream & o, Date const & date);

#endif