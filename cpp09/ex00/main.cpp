/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:51:40 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/22 17:23:16 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {

	std::map<Date, float> database_map;
	std::ifstream csv_database;
	std::ifstream infile;
	
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
	if (argc > 2)
		std::cout << "Warning: only the first file will be considered" << std::endl << std::endl;
		
	if (read_database(csv_database, database_map) == -1)
		return 4;
	if (read_infile(infile, database_map) == -1)
		return 5;
	
	infile.close();
	csv_database.close();
	
	return 0;
}