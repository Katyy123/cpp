/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:51:40 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/21 17:54:56 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {

	std::map<Date, float> database_map;
	std::multimap<Date, float> infile_map;
	std::ifstream csv_database;
	std::ifstream infile;


	/* Date class test
	
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

	std::cout << date << std::endl;

	end Date class test */
	
	
	
	if (argc < 2) {
		std::cerr << "Error: bad arguments" << std:: endl;
		return 2;
	}
	infile.open(argv[1], std::ios_base::in);
	if (!infile.is_open()) {
		std::cerr << "Error: the file does not exist or cannot be opened" << std::endl;
		return 3;
	}
	csv_database.open("data.csv", std::ios_base::in);
	if (!csv_database.is_open()) {
		std::cerr << "Error: the csv database does not exist or cannot be opened" << std::endl;
		return 1;
	}
	if (argc > 2) {
		std::cout << "Warning: only the first file will be considered" << std::endl << std::endl;
		float stof_test;
		stof_test = ft_stof(argv[2]);
		std::cout << "stof_test: " << stof_test << std::endl;
	}
	

	if (read_csv_database(csv_database, database_map) == -1) {
		std::cout << "problem" << std::endl;
		return 4;
	}
	// if (read_infile(infile, infile_map) == -1)
	// 	return 5;
	
	infile.close();
	csv_database.close();
	
	return 0;
}