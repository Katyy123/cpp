/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:51:40 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/17 17:46:27 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {

	std::map<Date, float> database_map;
	std::multimap<Date, float> infile_map;
	std::ifstream csv_database;
	std::ifstream infile;
	std::ifstream infile_2;
	Date date(2024, 13, 18);
	Date date_2(2023, 03, 18);
	
	if (date < date_2)
		std::cout << "date < date_2" << std::endl;
	else
		std::cout << "! date < date_2" << std::endl;
	if (date > date_2)
		std::cout << "date > date_2" << std::endl;
	else
		std::cout << "! date > date_2" << std::endl;
	if (date <= date_2)
		std::cout << "date <= date_2" << std::endl;
	else
		std::cout << "! date <= date_2" << std::endl;
	if (date >= date_2)
		std::cout << "date >= date_2" << std::endl;
	else
		std::cout << "! date >= date_2" << std::endl;
	if (date == date_2)
		std::cout << "date == date_2" << std::endl;
	else
		std::cout << "! date == date_2" << std::endl;
	
	csv_database.open("data.csv", std::ios_base::in);
	if (!csv_database.is_open()) {
		std::cout << "Error: the csv database does not exist or cannot be opened" << std::endl;
		return 1;
	}
	//database_map = read_database(csv_database, NULL); //don't know if NULL is ok for ifstream
	if (argc < 2) {
		std::cout << "Error: bad arguments" << std:: endl;
		return 2;
	}
	infile.open(argv[1], std::ios_base::in);
	if (!infile.is_open()) {
		std::cout << "Error: the file does not exist or cannot be opened" << std::endl;
		return 3;
	}
	if (argc == 3) {
		infile_2.open(argv[2], std::ios_base::in);
		if (!infile_2.is_open())
			std::cout << "Warning: the second file does not exist or cannot be opened" << std::endl << std::endl;
	}
	//infile_map = read_database(infile, infile_2);

	std::cout << date << std::endl;
	
	infile.close();
	if (infile_2.is_open())
		infile_2.close();
	return 0;
}