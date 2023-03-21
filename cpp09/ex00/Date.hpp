/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catia <catia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:01:04 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/20 20:35:52 by catia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
# define DATE_HPP

# include <iostream>

class Date {
	
	public:
		Date();
		Date(long int year, long int month, long int day);
		Date(Date const & other);
		~Date();

		Date & operator=(Date const & other);

		long int getYear() const;
		long int getMonth() const;
		long int getDay() const;

		void setYear(long int year);
		void setMonth(long int year);
		void setDay(long int year);

		bool operator==(Date const & other) const;
		bool operator<(Date const & other) const;
		bool operator>(Date const & other) const;
		bool operator<=(Date const & other) const;
		bool operator>=(Date const & other) const;

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
		long int _year;
		long int _month;
		long int _day;

};

std::ostream & operator<<(std::ostream & o, Date const & date);

#endif