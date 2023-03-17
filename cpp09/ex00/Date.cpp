/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:35:05 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/17 17:26:42 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

Date::Date() {

}

Date::Date( long int year, long int month, long int day) : _year(year), _month(month), _day(day) {

	try {
		if (!(year >= 0 && year <= 3000))
			throw WrongYearException();
		if (!(month >=1 && month <=12))
			throw WrongMonthException();
		if (!(day >= 1 && day <= 31))
			throw WrongDayException();
	}
	catch(WrongYearException & e) {
		std::cout << e.what() << std::endl;
	}
	catch(WrongMonthException & e) {
		std::cout << e.what() << std::endl;
	}
	catch(WrongDayException & e) {
		std::cout << e.what() << std::endl;
	}
}

Date::Date(Date const & other) : _year(other.getYear()), _month(other.getMonth()), _day(other.getDay()) {

}

Date::~Date() {

}

Date & Date::operator=(Date const & other) {

	this->_year = other.getYear();
	this->_month = other.getMonth();
	this->_day = other.getDay();
	return *this;
}

long int Date::getYear() const {

	return this->_year;
}

long int Date::getMonth() const {

	return this->_month;
}

long int Date::getDay() const {

	return this->_day;
}

void Date::setYear(long int year) {

	this->_year = year;
}

void Date::setMonth(long int month) {

	this->_month = month;
}

void Date::setDay(long int day) {

	this->_day = day;
}

bool Date::operator==(Date const & other) const {
	
	return (this->_year == other.getYear() && this->_month == other.getMonth() && this->_day == other.getDay());
}

bool Date::operator<(Date const & other) const {
	
	if (this->_year == other.getYear()) {
		if (this->_month == other.getMonth()) {
			if (this->_day < other.getDay())
				return true;
		}
		else if (this->_month < other.getMonth())
			return true;
	}
	else if (this->_year < other.getYear())
		return true;
	return false;
}

bool Date::operator>(Date const & other) const {
	
	return (!(*this < other || *this == other));
}

bool Date::operator<=(Date const & other) const {
	
	return (*this < other || *this == other);
}

bool Date::operator>=(Date const & other) const {
	
	return (*this > other || *this == other);
}

const char * Date::WrongYearException::what() const throw() {

	return "Error: wrong year";
}

const char * Date::WrongMonthException::what() const throw() {

	return "Error: wrong month";
}

const char * Date::WrongDayException::what() const throw() {

	return "Error: wrong day";
}

std::ostream & operator<<(std::ostream & o, Date const & date) {

	o << date.getYear() << "-" << date.getMonth() << "-" << date.getDay();
	return o;
}